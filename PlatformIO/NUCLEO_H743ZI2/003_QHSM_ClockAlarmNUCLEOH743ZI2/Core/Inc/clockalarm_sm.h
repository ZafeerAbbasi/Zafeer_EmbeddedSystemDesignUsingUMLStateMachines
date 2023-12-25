//$file${HSMs::../Core/Inc::clockalarm_sm.h} vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
//
// Model: 003_QHSM_ClockAlarm.qm
// File:  ${HSMs::../Core/Inc::clockalarm_sm.h}
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
//$endhead${HSMs::../Core/Inc::clockalarm_sm.h} ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
#ifndef CLOCK_ALARM_SM_H
#define CLOCK_ALARM_SM_H

#define MAX_TIME    ( 864000UL )

typedef enum SIGNAL_eClockAlarmSignals
{
    SET_SIG = Q_USER_SIG,
    OK_SIG,
    ABORT_SIG,
    ALARM_SIG,
    TICK_SIG,
    MAX_SIG
}SIGNAL_eClockAlarmSignals;

//$declare${HSMs::CLKALRM_Ctor} vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv

//${HSMs::CLKALRM_Ctor} ......................................................
void CLKALRM_Ctor(void);
//$enddecl${HSMs::CLKALRM_Ctor} ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

#endif
