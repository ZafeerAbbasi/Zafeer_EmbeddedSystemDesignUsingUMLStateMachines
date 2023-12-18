//$file${src::qf::qf_defer.c} vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
//
// Model: qpc.qm
// File:  ${src::qf::qf_defer.c}
//
// This code has been generated by QM 5.3.0 <www.state-machine.com/qm>.
// DO NOT EDIT THIS FILE MANUALLY. All your changes will be lost.
//
// This code is covered by the following QP license:
// License #    : LicenseRef-QL-dual
// Issued to    : Any user of the QP/C real-time embedded framework
// Framework(s) : qpc
// Support ends : 2024-12-31
// License scope:
//
// Copyright (C) 2005 Quantum Leaps, LLC <state-machine.com>.
//
//                    Q u a n t u m  L e a P s
//                    ------------------------
//                    Modern Embedded Software
//
// SPDX-License-Identifier: GPL-3.0-or-later OR LicenseRef-QL-commercial
//
// This software is dual-licensed under the terms of the open source GNU
// General Public License version 3 (or any later version), or alternatively,
// under the terms of one of the closed source Quantum Leaps commercial
// licenses.
//
// The terms of the open source GNU General Public License version 3
// can be found at: <www.gnu.org/licenses/gpl-3.0>
//
// The terms of the closed source Quantum Leaps commercial licenses
// can be found at: <www.state-machine.com/licensing>
//
// Redistributions in source code must retain this top-level comment block.
// Plagiarizing this software to sidestep the license obligations is illegal.
//
// Contact information:
// <www.state-machine.com/licensing>
// <info@state-machine.com>
//
//$endhead${src::qf::qf_defer.c} ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
#define QP_IMPL           // this is QP implementation
#include "qp_port.h"      // QP port
#include "qp_pkg.h"       // QP package-scope interface
#include "qsafe.h"        // QP Functional Safety (FuSa) Subsystem
#ifdef Q_SPY              // QS software tracing enabled?
    #include "qs_port.h"  // QS port
    #include "qs_pkg.h"   // QS facilities for pre-defined trace records
#else
    #include "qs_dummy.h" // disable the QS software tracing
#endif // Q_SPY

Q_DEFINE_THIS_MODULE("qf_defer")

//$skip${QP_VERSION} vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
// Check for the minimum required QP version
#if (QP_VERSION < 730U) || (QP_VERSION != ((QP_RELEASE^4294967295U) % 0x3E8U))
#error qpc version 7.3.0 or higher required
#endif
//$endskip${QP_VERSION} ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

//$define${QF::QActive::defer} vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv

//${QF::QActive::defer} ......................................................
//! @protected @memberof QActive
bool QActive_defer(QActive const * const me,
    struct QEQueue * const eq,
    QEvt const * const e)
{
    bool const status = QEQueue_post(eq, e, 0U, me->prio);

    QS_CRIT_STAT
    QS_CRIT_ENTRY();
    QS_MEM_SYS();
    QS_BEGIN_PRE_(QS_QF_ACTIVE_DEFER, me->prio)
        QS_TIME_PRE_();      // time stamp
        QS_OBJ_PRE_(me);     // this active object
        QS_OBJ_PRE_(eq);     // the deferred queue
        QS_SIG_PRE_(e->sig); // the signal of the event
        QS_2U8_PRE_(QEvt_getPoolId_(e), e->refCtr_); // poolId & refCtr
    QS_END_PRE_()
    QS_MEM_APP();
    QS_CRIT_EXIT();

    return status;
}
//$enddef${QF::QActive::defer} ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
//$define${QF::QActive::recall} vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv

//${QF::QActive::recall} .....................................................
//! @protected @memberof QActive
bool QActive_recall(QActive * const me,
    struct QEQueue * const eq)
{
    QEvt const * const e = QEQueue_get(eq, me->prio);
    QF_CRIT_STAT

    bool recalled;
    if (e != (QEvt *)0) { // event available?
        QACTIVE_POST_LIFO(me, e); // post it to the front of the AO's queue

        QF_CRIT_ENTRY();
        QF_MEM_SYS();

        if (QEvt_getPoolId_(e) != 0U) { // is it a mutable event?

            // after posting to the AO's queue the event must be referenced
            // at least twice: once in the deferred event queue (eq->get()
            // did NOT decrement the reference counter) and once in the
            // AO's event queue.
            Q_ASSERT_INCRIT(210, e->refCtr_ >= 2U);

            // we need to decrement the reference counter once, to account
            // for removing the event from the deferred event queue.
            QEvt_refCtr_dec_(e); // decrement the reference counter
        }

        QS_BEGIN_PRE_(QS_QF_ACTIVE_RECALL, me->prio)
            QS_TIME_PRE_();      // time stamp
            QS_OBJ_PRE_(me);     // this active object
            QS_OBJ_PRE_(eq);     // the deferred queue
            QS_SIG_PRE_(e->sig); // the signal of the event
            QS_2U8_PRE_(QEvt_getPoolId_(e), e->refCtr_); // poolId & refCtr
        QS_END_PRE_()

        QF_MEM_APP();
        QF_CRIT_EXIT();

        recalled = true;
    }
    else {
        QS_CRIT_ENTRY();
        QS_MEM_SYS();

        QS_BEGIN_PRE_(QS_QF_ACTIVE_RECALL_ATTEMPT, me->prio)
            QS_TIME_PRE_();      // time stamp
            QS_OBJ_PRE_(me);     // this active object
            QS_OBJ_PRE_(eq);     // the deferred queue
        QS_END_PRE_()

        QS_MEM_APP();
        QS_CRIT_EXIT();

        recalled = false;
    }
    return recalled;
}
//$enddef${QF::QActive::recall} ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
//$define${QF::QActive::flushDeferred} vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv

//${QF::QActive::flushDeferred} ..............................................
//! @protected @memberof QActive
uint_fast16_t QActive_flushDeferred(QActive const * const me,
    struct QEQueue * const eq,
    uint_fast16_t const num)
{
    uint_fast16_t n = 0U;
    while (n < num) {
        QEvt const * const e = QEQueue_get(eq, me->prio);
        if (e != (QEvt *)0) {
            ++n; // count one more flushed event
    #if (QF_MAX_EPOOL > 0U)
            QF_gc(e); // garbage collect
    #endif
        }
        else {
            break;
        }
    }

    return n;
}
//$enddef${QF::QActive::flushDeferred} ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
