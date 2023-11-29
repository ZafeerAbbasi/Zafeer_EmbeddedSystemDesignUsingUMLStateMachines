/*.$file${HSMs::../src::ClockAlarm_SM.h} vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv*/
/*
* Model: ClockAlarm.qm
* File:  ${HSMs::../src::ClockAlarm_SM.h}
*
* This code has been generated by QM 5.1.1 <www.state-machine.com/qm/>.
* DO NOT EDIT THIS FILE MANUALLY. All your changes will be lost.
*
* This program is open source software: you can redistribute it and/or
* modify it under the terms of the GNU General Public License as published
* by the Free Software Foundation.
*
* This program is distributed in the hope that it will be useful, but
* WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
* or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License
* for more details.
*/
/*.$endhead${HSMs::../src::ClockAlarm_SM.h} ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^*/
#ifndef CLOCK_ALARM_H
#define CLOCK_ALARM_H

enum ClockAlarm_Signals{
    SET_SIG = Q_USER_SIG,
    OK_SIG,
    ABRT_SIG,
    ALARM_SIG,
    TICK_SIG,
    IGNORE_SIG,
    MAX_SIG
};

enum time_mode{
    MODE_24H,
    MODE_12H
};

enum alarm_status{
    ALARM_OFF,
    ALARM_ON
};

typedef enum time_format{
    FORMAT_24H,
    FORMAT_AM,
    FORMAT_PM
}time_format_t;

#define GET_HOUR(seconds)     (seconds/3600UL)
#define GET_MIN(seconds)      ((seconds/60UL)%60UL)
#define GET_SEC(seconds)      (seconds % 60UL)
#define DIGIT1(d)             (d/10U)
#define DIGIT2(d)             (d%10U)

#define MAX_TIME  (864000UL)
#define INITIAL_CURR_TIME  ((10UL * 3600UL + 10UL * 60UL + 10UL) * 10UL)
#define INITIAL_ALARM_TIME  (8UL * 3600UL)

#define TICKING_CURR_TIME_ROW  0
#define TICKING_CURR_TIME_COL  3
#define CLOCK_SETTING_TIME_ROW 0
#define CLOCK_SETTING_TIME_COL 2
#define CLOCK_SETTING_TIME_HOUR_D1_COL 2
#define CLOCK_SETTING_TIME_HOUR_D2_COL 3
#define CLOCK_SETTING_TIME_MIN_D1_COL 5
#define CLOCK_SETTING_TIME_MIN_D2_COL 6
#define CLOCK_SETTING_TIME_SEC_D1_COL 8
#define CLOCK_SETTING_TIME_SEC_D2_COL 9
#define CLOCK_SETTING_TIME_FMT_COL     11
#define CLOCK_SETTING_ERR_MSG_ROW 1
#define CLOCK_SETTING_ERR_MSG_COL  4
#define CLOCK_SETTING_ERR_MSG_COL_END 9

#define ALARM_SETTING_CURR_TIME_ROW 1
#define ALARM_SETTING_CURR_TIME_COL  2
#define ALARM_SETTING_STATUS_ROW 0
#define ALARM_SETTING_STATUS_COL  4
#define ALARM_NOTIFY_MSG_ROW 0
#define ALARM_NOTIFY_MSG_COL 4

#define CS_ROW 0
#define CS_HOUR_D1_COL  2
/*.$declare${HSMs::Clock_Alarm_ctor} vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv*/
/*.${HSMs::Clock_Alarm_ctor} ...............................................*/
void Clock_Alarm_ctor(void);
/*.$enddecl${HSMs::Clock_Alarm_ctor} ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^*/
/*.$declare${HSMs::super_ClockAlarm} vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv*/
extern QHsm *const super_ClockAlarm;
/*.$enddecl${HSMs::super_ClockAlarm} ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^*/

#endif