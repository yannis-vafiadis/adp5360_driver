/*
 * adp5360.h
 *
 *  Created on: May 4, 2025
 *      Author: Yannis Vafiadis
 */

#ifndef ADP5360_H_
#define ADP5360_H_

#include "adp5360_reg.h"

#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "stm32u0xx_hal.h"


extern I2C_HandleTypeDef ADP5360_I2C_PORT;

typedef struct {
    /// - CHIP ID REGISTERS - ///
    REG00 r00; // Manufacture and Model ID
    REG01 r01; // Silicon Revision

    /// - CHARGER REGISTERS - ///
    REG02 r02; // CHARGER_VBUS_ILIM
    REG03 r03; // CHARGER_TERMINATION_SETTING
    REG04 r04; // CHARGER_CURRENT_SETTING
    REG05 r05; // CHARGER_VOLTAGE_THRESHOLD
    REG06 r06; // CHARGER_TIMER_SETTING
    REG07 r07; // CHARGER_FUNCTION_SETTING
    REG08 r08; // CHARGER_STATUS1
    REG09 r09; // CHARGER_STATUS2
    REG0A r0A; // BATTERY_THERMISTOR_CONTROL
    REG0B r0B; // THERMISTOR_60C
    REG0C r0C; // THERMISTOR_45C
    REG0D r0D; // THERMISTOR_10C
    REG0E r0E; // THERMISTOR_0C
    REG0F r0F; // THR_VOLTAGE Low
    REG10 r10; // THR_VOLTAGE High

    /// - BATTERY PROTECTION REGISTERS - ///
    REG11 r11; // Battery Protection Control
    REG12 r12; // Battery Protection Undervoltage Setting
    REG13 r13; // Battery Protection Overcharge Setting
    REG14 r14; // Battery Protection Overvoltage Setting
    REG15 r15; // Battery Protection Charge Overcharge Setting,

    /// - FUEL GAUGE REGISTERS - ///
    REG16 r16; // V_SOC_0
    REG17 r17; // V_SOC_5
    REG18 r18; // V_SOC_11
    REG19 r19; // V_SOC_19
    REG1A r1A; // V_SOC_28
    REG1B r1B; // V_SOC_41
    REG1C r1C; // V_SOC_55
    REG1D r1D; // V_SOC_69
    REG1E r1E; // V_SOC_84
    REG1F r1F; // V_SOC_100
    REG20 r20; // BAT_CAP
    REG21 r21; // BAT_SOC
    REG22 r22; // BAT_SOCACM_CTL
    REG23 r23; // BAT_SOCACM_H
    REG24 r24; // BAT_SOCACM_L
    REG25 r25; // VBAT_READ_H
    REG26 r26; // VBAT_READ_L
    REG27 r27; // FUEL_GAUGE_MODE
    REG28 r28; // SOC_RESET

    /// - BUCK SWITCHING REGULATOR REGISTERS - ///
    REG29 r29; // Buck Configure
    REG2A r2A; // Buck Output Voltage Setting

    /// - BUCK BOOST SWITCHING REGULATOR REGISTERS - ///
    REG2B r2B; // Buck Boost Configure
    REG2C r2C; // Buck Boost Output Voltage Setting

    /// - SUPERVISORY REGISTERS - ///
    REG2D r2D; // Supervisory Setting

    /// - STATUS AND FAULT REGISTER - ///
    REG2E r2E; // Fault
    REG2F r2F; // PGOOD_STATUS Register
    REG30 r30; // PGOOD1_MASK Register
    REG31 r31; // PGOOD2_MASK Register
    REG32 r32; // INTERRUPT_ENABLE1 Register
    REG33 r33; // INTERRUPT_ENABLE2 Register
    REG34 r34; // INTERRUPT_FLAG1 Register
    REG35 r35; // INTERRUPT_FLAG2 Register
    REG36 r36; // SHIPMODE Register

} adp5360_regs_t;

extern adp5360_regs_t adp5360_regs;

bool adp5360_init();

bool adp5360_validate_presence(bool read);

bool adp5360_en_charging(bool enable);

CHARGER_STATUS adp5360_get_charger_status(bool read);
bool adp5360_is_charging(bool read);

BAT_CHG_STATUS adp5360_get_battery_status(bool read);
bool adp5360_is_battery_ok(bool read);

bool adp5360_en_buck(bool enable);
bool adp5360_en_buck_boost(bool enable);

void adp5360_interrupt_handler(void);


HAL_StatusTypeDef adp5360_read_registers(
    adp5360_regs_t *regs,
    uint8_t start_reg,
    uint8_t count
);

HAL_StatusTypeDef adp5360_write_registers(
    adp5360_regs_t *regs,
    uint8_t start_reg,
    uint8_t count
);


#endif /* ADP5360_H_ */
