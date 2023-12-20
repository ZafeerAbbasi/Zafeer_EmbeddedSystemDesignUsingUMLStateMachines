//$file${../Core/Src::QHSMTest_SM.c} vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
//
// Model: qhsmtst.qm
// File:  ${../Core/Src::QHSMTest_SM.c}
//
// This code has been generated by QM 6.0.0 <www.state-machine.com/qm>.
// DO NOT EDIT THIS FILE MANUALLY. All your changes will be lost.
//
// SPDX-License-Identifier: GPL-3.0-or-later
//
// This generated code is open source software: you can redistribute it under
// the terms of the GNU General Public License as published by the Free
// Software Foundation.
//
// This code is distributed in the hope that it will be useful, but WITHOUT
// ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
// FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
// more details.
//
// NOTE:
// Alternatively, this generated code may be distributed under the terms
// of Quantum Leaps commercial licenses, which expressly supersede the GNU
// General Public License and are specifically designed for licensees
// interested in retaining the proprietary status of their code.
//
// Contact information:
// <www.state-machine.com/licensing>
// <info@state-machine.com>
//
//$endhead${../Core/Src::QHSMTest_SM.c} ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
#include "qpc.h"
#include "QHSMTest_SM.h"
#include "bsp.h"
//$declare${HSMs::QHsmTst} vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv

//${HSMs::QHsmTst} ...........................................................
typedef struct QHsmTst {
// protected:
    QHsm super;

// private:
    uint8_t foo;

// public:
} QHsmTst;

extern QHsmTst QHsmTst_inst;

// protected:
static QState QHsmTst_initial(QHsmTst * const me, void const * const par);
static QState QHsmTst_s(QHsmTst * const me, QEvt const * const e);
static QState QHsmTst_s1(QHsmTst * const me, QEvt const * const e);
static QState QHsmTst_s11(QHsmTst * const me, QEvt const * const e);
static QState QHsmTst_s2(QHsmTst * const me, QEvt const * const e);
static QState QHsmTst_s21(QHsmTst * const me, QEvt const * const e);
static QState QHsmTst_s211(QHsmTst * const me, QEvt const * const e);
//$enddecl${HSMs::QHsmTst} ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
//$skip${QP_VERSION} vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
// Check for the minimum required QP version
#if (QP_VERSION < 730U) || (QP_VERSION != ((QP_RELEASE^4294967295U) % 0x3E8U))
#error qpc version 7.3.0 or higher required
#endif
//$endskip${QP_VERSION} ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

//$define${HSMs::super_QHsmTst} vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv

//${HSMs::super_QHsmTst} .....................................................
QHsmTst *const super_QHsmTst = &QHsmTst_inst.super;
//$enddef${HSMs::super_QHsmTst} ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
//$define${HSMs::QHsmTst} vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv

//${HSMs::QHsmTst} ...........................................................
QHsmTst QHsmTst_inst;

//${HSMs::QHsmTst::SM} .......................................................
static QState QHsmTst_initial(QHsmTst * const me, void const * const par) {
    //${HSMs::QHsmTst::SM::initial}
    Q_UNUSED_PAR(par);
    me->foo = 0U;
    BSP_display("top-INIT;");

    QS_SIG_DICTIONARY(A_SIG, (void *)0);
    QS_SIG_DICTIONARY(B_SIG, (void *)0);
    QS_SIG_DICTIONARY(C_SIG, (void *)0);
    QS_SIG_DICTIONARY(D_SIG, (void *)0);
    QS_SIG_DICTIONARY(E_SIG, (void *)0);
    QS_SIG_DICTIONARY(F_SIG, (void *)0);
    QS_SIG_DICTIONARY(G_SIG, (void *)0);
    QS_SIG_DICTIONARY(H_SIG, (void *)0);
    QS_SIG_DICTIONARY(I_SIG, (void *)0);
    QS_SIG_DICTIONARY(IGNORE_SIG,    (void *)0);
    QS_SIG_DICTIONARY(TERMINATE_SIG, (void *)0);

    QS_FUN_DICTIONARY(&QHsmTst_s);
    QS_FUN_DICTIONARY(&QHsmTst_s1);
    QS_FUN_DICTIONARY(&QHsmTst_s11);
    QS_FUN_DICTIONARY(&QHsmTst_s2);
    QS_FUN_DICTIONARY(&QHsmTst_s21);
    QS_FUN_DICTIONARY(&QHsmTst_s211);

    return Q_TRAN(&QHsmTst_s2);
}

//${HSMs::QHsmTst::SM::s} ....................................................
static QState QHsmTst_s(QHsmTst * const me, QEvt const * const e) {
    QState status_;
    switch (e->sig) {
        //${HSMs::QHsmTst::SM::s}
        case Q_ENTRY_SIG: {
            BSP_display("s-ENTRY;");
            status_ = Q_HANDLED();
            break;
        }
        //${HSMs::QHsmTst::SM::s}
        case Q_EXIT_SIG: {
            BSP_display("s-EXIT;");
            status_ = Q_HANDLED();
            break;
        }
        //${HSMs::QHsmTst::SM::s::initial}
        case Q_INIT_SIG: {
            BSP_display("s-INIT;");
            status_ = Q_TRAN(&QHsmTst_s11);
            break;
        }
        //${HSMs::QHsmTst::SM::s::I}
        case I_SIG: {
            //${HSMs::QHsmTst::SM::s::I::[me->foo]}
            if (me->foo) {
                me->foo = 0U;
                BSP_display("s-I;");
                status_ = Q_HANDLED();
            }
            else {
                status_ = Q_UNHANDLED();
            }
            break;
        }
        //${HSMs::QHsmTst::SM::s::E}
        case E_SIG: {
            BSP_display("s-E;");
            status_ = Q_TRAN(&QHsmTst_s11);
            break;
        }
        //${HSMs::QHsmTst::SM::s::TERMINATE}
        case TERMINATE_SIG: {
            BSP_terminate( );
            status_ = Q_HANDLED();
            break;
        }
        default: {
            status_ = Q_SUPER(&QHsm_top);
            break;
        }
    }
    return status_;
}

//${HSMs::QHsmTst::SM::s::s1} ................................................
static QState QHsmTst_s1(QHsmTst * const me, QEvt const * const e) {
    QState status_;
    switch (e->sig) {
        //${HSMs::QHsmTst::SM::s::s1}
        case Q_ENTRY_SIG: {
            BSP_display("s1-ENTRY;");
            status_ = Q_HANDLED();
            break;
        }
        //${HSMs::QHsmTst::SM::s::s1}
        case Q_EXIT_SIG: {
            BSP_display("s1-EXIT;");
            status_ = Q_HANDLED();
            break;
        }
        //${HSMs::QHsmTst::SM::s::s1::initial}
        case Q_INIT_SIG: {
            BSP_display("s1-INIT;");
            status_ = Q_TRAN(&QHsmTst_s11);
            break;
        }
        //${HSMs::QHsmTst::SM::s::s1::I}
        case I_SIG: {
            BSP_display("s1-I;");
            status_ = Q_HANDLED();
            break;
        }
        //${HSMs::QHsmTst::SM::s::s1::D}
        case D_SIG: {
            //${HSMs::QHsmTst::SM::s::s1::D::[!me->foo]}
            if (!me->foo) {
                me->foo = 1U;
                BSP_display("s1-D;");
                status_ = Q_TRAN(&QHsmTst_s);
            }
            else {
                status_ = Q_UNHANDLED();
            }
            break;
        }
        //${HSMs::QHsmTst::SM::s::s1::A}
        case A_SIG: {
            BSP_display("s1-A;");
            status_ = Q_TRAN(&QHsmTst_s1);
            break;
        }
        //${HSMs::QHsmTst::SM::s::s1::B}
        case B_SIG: {
            BSP_display("s1-B;");
            status_ = Q_TRAN(&QHsmTst_s11);
            break;
        }
        //${HSMs::QHsmTst::SM::s::s1::F}
        case F_SIG: {
            BSP_display("s1-F;");
            status_ = Q_TRAN(&QHsmTst_s211);
            break;
        }
        //${HSMs::QHsmTst::SM::s::s1::C}
        case C_SIG: {
            BSP_display("s1-C;");
            status_ = Q_TRAN(&QHsmTst_s2);
            break;
        }
        default: {
            status_ = Q_SUPER(&QHsmTst_s);
            break;
        }
    }
    return status_;
}

//${HSMs::QHsmTst::SM::s::s1::s11} ...........................................
static QState QHsmTst_s11(QHsmTst * const me, QEvt const * const e) {
    QState status_;
    switch (e->sig) {
        //${HSMs::QHsmTst::SM::s::s1::s11}
        case Q_ENTRY_SIG: {
            BSP_display("s11-ENTRY;");
            status_ = Q_HANDLED();
            break;
        }
        //${HSMs::QHsmTst::SM::s::s1::s11}
        case Q_EXIT_SIG: {
            BSP_display("s11-EXIT;");
            status_ = Q_HANDLED();
            break;
        }
        //${HSMs::QHsmTst::SM::s::s1::s11::H}
        case H_SIG: {
            BSP_display("s11-H;");
            status_ = Q_TRAN(&QHsmTst_s);
            break;
        }
        //${HSMs::QHsmTst::SM::s::s1::s11::D}
        case D_SIG: {
            //${HSMs::QHsmTst::SM::s::s1::s11::D::[me->foo]}
            if (me->foo) {
                me->foo = 0U;
                BSP_display("s11-D;");
                status_ = Q_TRAN(&QHsmTst_s1);
            }
            else {
                status_ = Q_UNHANDLED();
            }
            break;
        }
        //${HSMs::QHsmTst::SM::s::s1::s11::G}
        case G_SIG: {
            BSP_display("s11-G;");
            status_ = Q_TRAN(&QHsmTst_s211);
            break;
        }
        default: {
            status_ = Q_SUPER(&QHsmTst_s1);
            break;
        }
    }
    return status_;
}

//${HSMs::QHsmTst::SM::s::s2} ................................................
static QState QHsmTst_s2(QHsmTst * const me, QEvt const * const e) {
    QState status_;
    switch (e->sig) {
        //${HSMs::QHsmTst::SM::s::s2}
        case Q_ENTRY_SIG: {
            BSP_display("s2-ENTRY;");
            status_ = Q_HANDLED();
            break;
        }
        //${HSMs::QHsmTst::SM::s::s2}
        case Q_EXIT_SIG: {
            BSP_display("s2-EXIT;");
            status_ = Q_HANDLED();
            break;
        }
        //${HSMs::QHsmTst::SM::s::s2::initial}
        case Q_INIT_SIG: {
            BSP_display("s2-INIT;");
            status_ = Q_TRAN(&QHsmTst_s211);
            break;
        }
        //${HSMs::QHsmTst::SM::s::s2::I}
        case I_SIG: {
            //${HSMs::QHsmTst::SM::s::s2::I::[!me->foo]}
            if (!me->foo) {
                me->foo = 1U;
                BSP_display("s2-I;");
                status_ = Q_HANDLED();
            }
            else {
                status_ = Q_UNHANDLED();
            }
            break;
        }
        //${HSMs::QHsmTst::SM::s::s2::F}
        case F_SIG: {
            BSP_display("s2-F;");
            status_ = Q_TRAN(&QHsmTst_s11);
            break;
        }
        //${HSMs::QHsmTst::SM::s::s2::C}
        case C_SIG: {
            BSP_display("s2-C;");
            status_ = Q_TRAN(&QHsmTst_s1);
            break;
        }
        default: {
            status_ = Q_SUPER(&QHsmTst_s);
            break;
        }
    }
    return status_;
}

//${HSMs::QHsmTst::SM::s::s2::s21} ...........................................
static QState QHsmTst_s21(QHsmTst * const me, QEvt const * const e) {
    QState status_;
    switch (e->sig) {
        //${HSMs::QHsmTst::SM::s::s2::s21}
        case Q_ENTRY_SIG: {
            BSP_display("s21-ENTRY;");
            status_ = Q_HANDLED();
            break;
        }
        //${HSMs::QHsmTst::SM::s::s2::s21}
        case Q_EXIT_SIG: {
            BSP_display("s21-EXIT;");
            status_ = Q_HANDLED();
            break;
        }
        //${HSMs::QHsmTst::SM::s::s2::s21::initial}
        case Q_INIT_SIG: {
            BSP_display("s21-INIT;");
            status_ = Q_TRAN(&QHsmTst_s211);
            break;
        }
        //${HSMs::QHsmTst::SM::s::s2::s21::G}
        case G_SIG: {
            BSP_display("s21-G;");
            status_ = Q_TRAN(&QHsmTst_s1);
            break;
        }
        //${HSMs::QHsmTst::SM::s::s2::s21::A}
        case A_SIG: {
            BSP_display("s21-A;");
            status_ = Q_TRAN(&QHsmTst_s21);
            break;
        }
        //${HSMs::QHsmTst::SM::s::s2::s21::B}
        case B_SIG: {
            BSP_display("s21-B;");
            status_ = Q_TRAN(&QHsmTst_s211);
            break;
        }
        default: {
            status_ = Q_SUPER(&QHsmTst_s2);
            break;
        }
    }
    return status_;
}

//${HSMs::QHsmTst::SM::s::s2::s21::s211} .....................................
static QState QHsmTst_s211(QHsmTst * const me, QEvt const * const e) {
    QState status_;
    switch (e->sig) {
        //${HSMs::QHsmTst::SM::s::s2::s21::s211}
        case Q_ENTRY_SIG: {
            BSP_display("s211-ENTRY;");
            status_ = Q_HANDLED();
            break;
        }
        //${HSMs::QHsmTst::SM::s::s2::s21::s211}
        case Q_EXIT_SIG: {
            BSP_display("s211-EXIT;");
            status_ = Q_HANDLED();
            break;
        }
        //${HSMs::QHsmTst::SM::s::s2::s21::s211::H}
        case H_SIG: {
            BSP_display("s211-H;");
            status_ = Q_TRAN(&QHsmTst_s);
            break;
        }
        //${HSMs::QHsmTst::SM::s::s2::s21::s211::D}
        case D_SIG: {
            BSP_display("s211-D;");
            status_ = Q_TRAN(&QHsmTst_s21);
            break;
        }
        default: {
            status_ = Q_SUPER(&QHsmTst_s21);
            break;
        }
    }
    return status_;
}
//$enddef${HSMs::QHsmTst} ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
