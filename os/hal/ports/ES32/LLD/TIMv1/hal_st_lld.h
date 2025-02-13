/*
    Copyright (C) 2020 Yaotian Feng

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under SYST_RVRthe License.
*/

/**
 * @file    hal_st_lld.h
 * @brief   PLATFORM ST subsystem low level driver header.
 * @details This header is designed to be include-able without having to
 *          include other files from the HAL.
 *
 * @addtogroup ST
 * @{
 */

#ifndef HAL_ST_LLD_H
#define HAL_ST_LLD_H

#include "mcuconf.h"

/*===========================================================================*/
/* Driver constants.                                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Driver pre-compile time settings.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Derived constants and error checks.                                       */
/*===========================================================================*/

/*===========================================================================*/
/* Driver data structures and types.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Driver macros.                                                            */
/*===========================================================================*/

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

#ifdef __cplusplus
extern "C" {
#endif
void st_lld_init(void);
#ifdef __cplusplus
}
#endif

/*===========================================================================*/
/* Driver inline functions.                                                  */
/*===========================================================================*/

#define SYST_CSR    (*((volatile uint32_t*)0xE000E010))
#define SYST_RVR    (*((volatile uint32_t*)0xE000E014))
#define SYST_CVR    (*((volatile uint32_t*)0xE000E018))
#define SYST_CALIB  (*((volatile uint32_t*)0xE000E01C))

/**
 * @brief   Returns the time counter value.
 *
 * @return              The counter value.
 *
 * @notapi
 */
static inline systime_t st_lld_get_counter(void)
{
    return 0;//(systime_t) SYST_CVR;
}

/**
 * @brief   Starts the alarm.
 * @note    Makes sure that no spurious alarms are triggered after
 *          this call.
 *
 * @param[in] abstime   the time to be set for the first alarm
 *
 * @notapi
 */
static inline void st_lld_start_alarm(systime_t abstime)
{
//    SYST_RVR = (uint32_t)abstime;
//    SYST_CSR = 0b111;
//    SYST_CVR = 0; // Trigger reload
}

/**
 * @brief   Stops the alarm interrupt.
 *
 * @notapi
 */
static inline void st_lld_stop_alarm(void)
{
//    SYST_CVR &= ~((uint32_t)0b10);
}

/**
 * @brief   Sets the alarm time.
 *
 * @param[in] abstime   the time to be set for the next alarm
 *
 * @notapi
 */
static inline void st_lld_set_alarm(systime_t abstime)
{
//    SYST_RVR = (uint32_t)abstime;
}

/**
 * @brief   Returns the current alarm time.
 *
 * @return              The currently set alarm time.
 *
 * @notapi
 */
static inline systime_t st_lld_get_alarm(void)
{
    return 0;//(systime_t)SYST_RVR;
}

/**
 * @brief   Determines if the alarm is active.
 *
 * @return              The alarm status.
 * @retval false        if the alarm is not active.
 * @retval true         is the alarm is active
 *
 * @notapi
 */
static inline bool st_lld_is_alarm_active(void)
{
    return 0;//((SYST_CVR & 0b10) != 0);
}

#endif /* HAL_ST_LLD_H */

/** @} */
