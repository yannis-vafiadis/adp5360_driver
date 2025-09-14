/*
 * adp5360_reg.h
 *
 *  Created on: May 4, 2025
 *      Author: Yannis Vafiadis
 */

#ifndef ADP5360_REG_H_
#define ADP5360_REG_H_

#include <stdbool.h>
#include <stdint.h>

#define ADP5360_I2C_PORT    hi2c1
#define ADP5360_ADDRESS     0x46

#define ADP5360_I2C_TIMEOUT 50


typedef struct {
	uint8_t MODEL : 4; // Model identification: 0b0000
	uint8_t MANUF : 4; // Manufacturer identification: 0b0001
} REG00;

typedef struct {
	uint8_t REV : 4; // Silicon revision identification: 0b1000
    uint8_t RES : 4; // Reserved
} REG01;

typedef enum {
	V_ADPI_CHG4V4 = 0b010,
	V_ADPI_CHG4V5 = 0b011,
	V_ADPI_CHG4V6 = 0b100,
	V_ADPI_CHG4V7 = 0b101,
	V_ADPI_CHG4V8 = 0b110,
	V_ADPI_CHG4V9 = 0b111,

} V_ADPI_CHG;

typedef enum {
	V_TRM_PLUS_200 = 0b0,
	V5V = 0b1
} V_System;

#define ILIM_500  0b111
#define ILIM_400  0b110
#define ILIM_300  0b101
#define ILIM_250  0b100
#define ILIM_200  0b011
#define ILIM_150  0b010
#define ILIM_100  0b001
#define ILIM_50   0b000


typedef struct {
	uint8_t ILIM 		: 3; // VBUS Pin Input Current-Limit Programming Bus.
	V_System VSYSTEM 	: 1; // VSYS Voltage Programming.
	uint8_t RES 		: 1; // Reserved
	V_ADPI_CHG VADPICHG : 3; // Adaptive Current Limit to VBUS Voltage Threshold Programming
} REG02;

typedef enum {
	VTRM_3V56 = 0b000000,
	VTRM_3V58 = 0b000001,
	VTRM_3V60 = 0b000010,
	VTRM_3V62 = 0b000011,
	VTRM_3V64 = 0b000100,
	VTRM_3V66 = 0b000101,
	VTRM_3V68 = 0b000110,
	VTRM_3V70 = 0b000111,
	VTRM_3V72 = 0b001000,
	VTRM_3V74 = 0b001001,
	VTRM_3V76 = 0b001010,
	VTRM_3V78 = 0b001011,
	VTRM_3V80 = 0b001100,
	VTRM_3V82 = 0b001101,
	VTRM_3V84 = 0b001110,
	VTRM_3V86 = 0b001111,
	VTRM_3V88 = 0b010000,
	VTRM_3V90 = 0b010001,
	VTRM_3V92 = 0b010010,
	VTRM_3V94 = 0b010011,
	VTRM_3V96 = 0b010100,
	VTRM_3V98 = 0b010101,
	VTRM_4V00 = 0b010110,
	VTRM_4V02 = 0b010111,
	VTRM_4V04 = 0b011000,
	VTRM_4V06 = 0b011001,
	VTRM_4V08 = 0b011010,
	VTRM_4V10 = 0b011011,
	VTRM_4V12 = 0b011100,
	VTRM_4V14 = 0b011101,
	VTRM_4V16 = 0b011110,
	VTRM_4V18 = 0b011111,
	VTRM_4V20 = 0b100000,
	VTRM_4V22 = 0b100001,
	VTRM_4V24 = 0b100010,
	VTRM_4V26 = 0b100011,
	VTRM_4V28 = 0b100100,
	VTRM_4V30 = 0b100101,
	VTRM_4V32 = 0b100110,
	VTRM_4V34 = 0b100111,
	VTRM_4V36 = 0b101000,
	VTRM_4V38 = 0b101001,
	VTRM_4V40 = 0b101010,
	VTRM_4V42 = 0b101011,
	VTRM_4V44 = 0b101100,
	VTRM_4V46 = 0b101101,
	VTRM_4V48 = 0b101110,
	VTRM_4V50 = 0b101111,
	VTRM_4V52 = 0b110000,
	VTRM_4V54 = 0b110001,
	VTRM_4V56 = 0b110010,
	VTRM_4V58 = 0b110011,
	VTRM_4V60 = 0b110100,
	VTRM_4V62 = 0b110101,
	VTRM_4V64 = 0b110110,
	VTRM_4V66 = 0b111111,

} V_TRM;

typedef enum {
	ITRK_DEAD_1mA = 0b00,
	ITRK_DEAD_2_5mA = 0b01,
	ITRK_DEAD_5mA = 0b10,
	ITRK_DEAD_10mA = 0b11

} ITRK_DEAD;

typedef struct {
	ITRK_DEAD ITRK_DEAD : 2; // Trickle and Weak Charge Current Programming Bus.
	V_TRM VTRM 			: 6; // Termination Voltage Programming Bus.
} REG03;

typedef enum {
	IEND_5mA = 0b001,
	IEND_7_5mA = 0b010,
	IEND_12_5mA = 0b011,
	IEND_17_5mA = 0b100,
	IEND_22_5mA = 0b101,
	IEND_27_5mA = 0b110,
	IEND_35_5mA = 0b111,

} I_END;

typedef enum {
	ICHG_10mA  = 0b00000,
	ICHG_20mA  = 0b00001,
	ICHG_30mA  = 0b00010,
	ICHG_40mA  = 0b00011,
	ICHG_50mA  = 0b00100,
	ICHG_60mA  = 0b00101,
	ICHG_70mA  = 0b00110,
	ICHG_80mA  = 0b00111,
	ICHG_90mA  = 0b01000,
	ICHG_100mA = 0b01001,
	ICHG_110mA = 0b01010,
	ICHG_120mA = 0b01011,
	ICHG_130mA = 0b01100,
	ICHG_140mA = 0b01101,
	ICHG_150mA = 0b01110,
	ICHG_160mA = 0b01111,
	ICHG_170mA = 0b10000,
	ICHG_180mA = 0b10001,
	ICHG_190mA = 0b10010,
	ICHG_200mA = 0b10011,
	ICHG_210mA = 0b10100,
	ICHG_220mA = 0b10101,
	ICHG_230mA = 0b10110,
	ICHG_240mA = 0b10111,
	ICHG_250mA = 0b11000,
	ICHG_260mA = 0b11001,
	ICHG_270mA = 0b11010,
	ICHG_280mA = 0b11011,
	ICHG_290mA = 0b11100,
	ICHG_300mA = 0b11101,
	ICHG_310mA = 0b11110,
	ICHG_320mA = 0b11111
} I_CHG;

typedef struct {
	I_CHG ICHG 			: 5; // Fast Charge Current Programming Bus.
	I_END IEND 			: 3; // Termination Current Programming Bus.
} REG04;

typedef enum {
	VRCH_120mV = 0b01,
	VRCH_180mV = 0b10,
	VRCH_240mV = 0b11,
} V_RCH;

typedef enum {
	VTRK_DEAD_2V   = 0b00,
	VTRK_DEAD_2_5V = 0b01,
	VTRK_DEAD_2_6V = 0b10,
	VTRK_DEAD_2_9V = 0b11,
} VTRK_DEAD;

typedef enum {
	VWEAK_2_7V     = 0b000,
	VWEAK_2_8V     = 0b001,
	VWEAK_2_9V     = 0b010,
	VWEAK_3_0V     = 0b011,
	VWEAK_3_1V     = 0b100,
	VWEAK_3_2V     = 0b101,
	VWEAK_3_3V     = 0b110,
	VWEAK_3_4V     = 0b111,

} V_WEAK;

typedef struct {
	V_WEAK VWEAK 		: 3; // Weak Battery Voltage Rising Threshold.
	VTRK_DEAD VTRK_DEAD : 2; // Trickle to Fast Charge Dead Battery Voltage Programming Bus.
	V_RCH VRCH 			: 2; // Recharge Voltage Programming Bus.
	bool DIS_RCH 		: 1; // Recharge Function Disable.
} REG05;

typedef enum {
	CHG_TMR_PERIOD_TRK15_CHG150 = 0b00,
	CHG_TMR_PERIOD_TRK30_CHG300 = 0b01,
	CHG_TMR_PERIOD_TRK45_CHG450 = 0b10,
	CHG_TMR_PERIOD_TRK60_CHG600 = 0b11
} CHG_TMR_PERIOD;

typedef struct {
	CHG_TMR_PERIOD CHG_TMR_PERIOD 	: 2; // Weak Battery Voltage Rising Threshold.
	bool EN_CHG_TIMER  				: 1; // When high, the trickle charge timer (tTRK) and the fast charge timer (tCHG) are enabled. When low, tTRK and tCHG are disabled.
	bool EN_TEND  					: 1; // When low, this bit disables the charge complete timer (tEND), and a 32 ms deglitch timer (tDG) remains on this function.
	uint8_t RES 					: 4; // Reserved
} REG06;

typedef struct {
	bool EN_CHG    					: 1; // When high and EN_LDO = high, charging is enabled.
	bool EN_ADPICHG    				: 1; // When high, the VBUS adaptive current-limit function is enabled during charging.
	bool EN_EOC    					: 1; // When high, end of charge is allowed.
	bool EN_LDO   					: 1; // When low, the charge LDO is disabled. When high, the charge LDO is enabled.
	bool OFF_ISOFET		   			: 1; // When high, ISOFET is forced to turn off, and VSYS is shut down only when the battery is present.
	uint8_t RES 					: 1; // Reserved
	bool ILIM_JEITA_COOL   			: 1; // When in temperature cool mode, select the battery charging current. 0 = 50%; 1 = 10%;
	bool EN_JEITA  					: 1; // When low, this bit disables the JEITA Li-Ion temperature battery charging specification.

} REG07;

typedef enum {
	CHARGER_STATUS_OFF 				= 0b000,
	CHARGER_STATUS_TRICKLE		    = 0b001,
	CHARGER_STATUS_FAST_CHARGE_CC   = 0b010,
	CHARGER_STATUS_FAST_CHARGE_CV   = 0b011,
	CHARGER_STATUS_CHARGE_COMPLETE  = 0b100,
	CHARGER_STATUS_LDO 				= 0b101,
	CHARGER_STATUS_TIMER_EXPIRED 	= 0b110,
	CHARGER_STATUS_BAT_DETECTION 	= 0b111

} CHARGER_STATUS;

typedef struct {
	CHARGER_STATUS CHARGER_STATUS   : 3; // Charger Status Bus.
	uint8_t RES 					: 2; // Reserved
	bool VBUS_ILIM 		   			: 1; // When high, this bit indicates that the current into the VBUS pin is limited by the high voltage blocking FET and that the charger is not running at the full programmed ICHG.
	bool ADPICHG   					: 1; // When high, this bit indicates that the adaptive charge current is active.
	bool VBUS_OV   					: 1; // When high, this bit indicates that the VBUS voltage is over the threshold of VVBUS_OK.
} REG08;

typedef enum {
	THR_STATUS_OFF 		= 0b000,
	THR_STATUS_BAT_COLD = 0b001,
	THR_STATUS_BAT_COOL = 0b010,
	THR_STATUS_BAT_WARM = 0b011,
	THR_STATUS_BAT_HOT  = 0b100,
	THR_STATUS_THR_OKAY = 0b111,
} THR_STATUS;

typedef enum {
	BAT_CHG_STATUS_NORMAL 	  = 0b000,
	BAT_CHG_STATUS_NO_BAT	  = 0b001,
	BAT_CHG_STATUS_DEAD		  = 0b010,
	BAT_CHG_STATUS_WEAK 	  = 0b011,
	BAT_CHG_STATUS_CHG_NORMAL = 0b100

} BAT_CHG_STATUS;

typedef struct {
	BAT_CHG_STATUS BAT_CHG_STATUS   : 3; // Battery Status Bus.
	bool BAT_UV_STATUS 		   		: 1; // Battery Undervoltage Status.
	bool BAT_OV_STATUS    			: 1; // Battery Overvoltage Status.
	THR_STATUS THR_STATUS   		: 3; // THR Pin Status.
} REG09;

typedef enum {
	ITHR_60uA = 0b00,
	ITHR_12uA = 0b01,
	ITHR_6uA = 0b11
} I_THR;

typedef struct {
	bool EN_THR 	: 1; // When high, the ITHR current source is enabled even when the voltage at the VBUS pin is lower than VVBUS_OK.
	uint8_t RES 	: 5; // Reserved
	I_THR ITHR 		: 2; // Select Battery Thermistor NTC Resistance.
} REG0A;

typedef struct {
	uint8_t TEMP_HIGH_60 : 8; // Thermistor Voltage Threshold for 60°C. THERMISTOR_60C Voltage Threshold (V) = (TEMP_HIGH_60 × 0.002) (V)
} REG0B;

typedef struct {
	uint8_t TEMP_HIGH_45 : 8; // Thermistor Voltage Threshold for 45°C. THERMISTOR_45C Voltage Threshold (V) = (TEMP_HIGH_45 × 0.002) (V)
} REG0C;

typedef struct {
	uint8_t TEMP_HIGH_10 : 8; // Thermistor Voltage Threshold for 10°C. THERMISTOR_10C Voltage Threshold (V) = (TEMP_HIGH_10 × 0.002) (V)
} REG0D;

typedef struct {
	uint8_t TEMP_HIGH_0 : 8; // Thermistor Voltage Threshold for 0°C. THERMISTOR_0C Voltage Threshold (V) = (TEMP_HIGH_0 × 0.002) (V)
} REG0E;

typedef struct {
	uint8_t THR_V_LOW : 8; // 8-Bit Thermistor Node Voltage Low (mV). NTC = THR_V_x[11:0]/ITHR (kΩ)
} REG0F;

typedef struct {
	uint8_t RES 		: 4; // Reserved
	uint8_t THR_V_HIGH 	: 4; // 4-Bit Thermistor Node Voltage High (mV). NTC = THR_V_x[11:0]/ITHR (kΩ)
} REG10;

typedef struct {
	bool EN_BATPRO    	: 1; // When low, the battery protection function is disabled. When high, the battery protection function is enabled.
	bool EN_CHGLB   	: 1; // When low, the battery charge is not allowed with the battery undervoltage protection triggered. When high, the battery charge is allowed with the battery undervoltage protection triggered.
	bool OC_CHG_HICCUP  : 1; // Battery Charge Overcurrent Protection Mode Selection. LOW -> LATCH UP. HIGH -> HICCUP.
	bool OC_DIS_HICCUP  : 1; // Battery Discharge Overcurrent Protection Mode Selection. LOW -> LATCH UP. HIGH -> HICCUP.
	bool ISOFET_OVCHG 	: 1; // (LOW -> ISOFET turns on/ HIGH -> ISOFET turns off) when the battery charging overvoltage protection is triggered
	uint8_t RES 		: 3; // Reserved
} REG11;

typedef enum {
	UV_DISCH_2_05V = 0b0000,
	UV_DISCH_2_10V = 0b0001,
	UV_DISCH_2_15V = 0b0010,
	UV_DISCH_2_20V = 0b0011,
	UV_DISCH_2_25V = 0b0100,
	UV_DISCH_2_30V = 0b0101,
	UV_DISCH_2_35V = 0b0110,
	UV_DISCH_2_40V = 0b0111,
	UV_DISCH_2_45V = 0b1000,
	UV_DISCH_2_50V = 0b1001,
	UV_DISCH_2_55V = 0b1010,
	UV_DISCH_2_60V = 0b1011,
	UV_DISCH_2_65V = 0b1100,
	UV_DISCH_2_70V = 0b1101,
	UV_DISCH_2_75V = 0b1110,
	UV_DISCH_2_80V = 0b1111

} UV_DISCH;

typedef enum {
	HYS_UV_DISCH_2 = 0b00,
	HYS_UV_DISCH_4 = 0b01,
	HYS_UV_DISCH_6 = 0b10,
	HYS_UV_DISCH_8 = 0b11

} HYS_UV_DISCH;

typedef enum {
	DGT_UV_DISCH_30ms = 0b00,
	DGT_UV_DISCH_60ms = 0b01,
	DGT_UV_DISCH_120ms = 0b10,
	DGT_UV_DISCH_240ms = 0b11

} DGT_UV_DISCH;

typedef struct {
	DGT_UV_DISCH DGT_UV_DISCH : 2; // Battery Undervoltage Protection Deglitch Time.
	HYS_UV_DISCH HYS_UV_DISCH : 2; // Battery Undervoltage Protection for Overdischarge Hysteresis.
	UV_DISCH UV_DISCH 	: 4; // Battery Undervoltage Protection Threshold.
} REG12;

typedef enum {
	OC_DISCH_50mA = 0b000,
	OC_DISCH_100mA = 0b001,
	OC_DISCH_150mA = 0b010,
	OC_DISCH_200mA = 0b011,
	OC_DISCH_300mA = 0b100,
	OC_DISCH_400mA = 0b101,
	OC_DISCH_500mA = 0b110,
	OC_DISCH_600mA = 0b111,

} OC_DISCH;

typedef enum {
	DGT_OC_DISCH_0_5ms = 0b001,
	DGT_OC_DISCH_1ms = 0b010,
	DGT_OC_DISCH_5ms = 0b011,
	DGT_OC_DISCH_10ms = 0b100,
	DGT_OC_DISCH_20ms = 0b101,
	DGT_OC_DISCH_50ms = 0b110,
	DGT_OC_DISCH_100ms = 0b111,

} DGT_OC_DISCH;

typedef struct {
	uint8_t RES1 				: 1; // Reserved
	DGT_OC_DISCH DGT_OC_DISCH 	: 3; // Battery Discharge Overcurrent Protection Deglitch Time Setting.
	uint8_t RES 				: 1; // Reserved
	OC_DISCH OC_DISCH 			: 3; // Battery Overcurrent Protection for Overdischarge Threshold
} REG13;

typedef enum {
	OV_CHG_3_55V = 0b00000,
	OV_CHG_3_60V = 0b00001,
	OV_CHG_3_65V = 0b00010,
	OV_CHG_3_70V = 0b00011,
	OV_CHG_3_75V = 0b00100,
	OV_CHG_3_80V = 0b00101,
	OV_CHG_3_85V = 0b00110,
	OV_CHG_3_90V = 0b00111,
	OV_CHG_3_95V = 0b01000,
	OV_CHG_4_00V = 0b01001,
	OV_CHG_4_05V = 0b01010,
	OV_CHG_4_10V = 0b01011,
	OV_CHG_4_15V = 0b01100,
	OV_CHG_4_20V = 0b01101,
	OV_CHG_4_25V = 0b01110,
	OV_CHG_4_30V = 0b01111,
	OV_CHG_4_35V = 0b10000,
	OV_CHG_4_40V = 0b10001,
	OV_CHG_4_45V = 0b10010,
	OV_CHG_4_50V = 0b10011,
	OV_CHG_4_55V = 0b10100,
	OV_CHG_4_60V = 0b10101,
	OV_CHG_4_65V = 0b10110,
	OV_CHG_4_70V = 0b10111,
	OV_CHG_4_75V = 0b11000,
	OV_CHG_4_80V = 0b11111,

} OV_CHG;

typedef enum {
	HYS_OV_CHG_2 = 0b00,
	HYS_OV_CHG_4 = 0b01,
	HYS_OV_CHG_6 = 0b10,
	HYS_OV_CHG_8 = 0b11,

} HYS_OV_CHG;

typedef enum {
	DGT_OV_CHG_0_5s = 0b0,
	DGT_OV_CHG_1s = 0b1,

} DGT_OV_CHG;

typedef struct {
	DGT_OV_CHG DGT_OV_CHG 	: 1; // Battery Overvoltage Protection Deglitch Time.
	HYS_OV_CHG HYS_OV_CHG 	: 2; // Battery Overvoltage Protection for Charge Hysteresis.
	OV_CHG OV_CHG 			: 5; // Battery Overvoltage Protection Threshold.
} REG14;

typedef enum {
	OC_CHG_25mA = 0b000,
	OC_CHG_50mA = 0b001,
	OC_CHG_100mA = 0b010,
	OC_CHG_150mA = 0b011,
	OC_CHG_200mA = 0b100,
	OC_CHG_250mA = 0b101,
	OC_CHG_300mA = 0b110,
	OC_CHG_400mA = 0b111,

} OC_CHG;

typedef enum {
	DGT_OC_CHG_5ms = 0b00,
	DGT_OC_CHG_10ms = 0b01,
	DGT_OC_CHG_20ms = 0b10,
	DGT_OC_CHG_40ms = 0b11,

} DGT_OC_CHG;

typedef struct {
	uint8_t RES 			: 3; // Reserved
	DGT_OC_CHG DGT_OC_CHG 	: 2; // Battery Charge Overcurrent Protection Deglitch Time Setting.
	OC_CHG OC_CHG 			: 3; // Battery Overcurrent Protection for Overdischarge Threshold.
} REG15;

typedef struct {
	uint8_t V_SOC_0 : 8; // Battery Voltage When State of Charge = 0%. Battery voltage (V) = (2.5 + V_SOC_0 × 0.008) (V).
} REG16;

typedef struct {
	uint8_t V_SOC_5 : 8; // Battery Voltage When State of Charge = 5%.
} REG17;

typedef struct {
	uint8_t V_SOC_11 : 8; // Battery Voltage When State of Charge = 11%.
} REG18;

typedef struct {
	uint8_t V_SOC_19 : 8; // Battery Voltage When State of Charge = 19%.
} REG19;

typedef struct {
	uint8_t V_SOC_28 : 8; // Battery Voltage When State of Charge = 28%.
} REG1A;

typedef struct {
	uint8_t V_SOC_41 : 8; // Battery Voltage When State of Charge = 41%.
} REG1B;

typedef struct {
	uint8_t V_SOC_55 : 8; // Battery Voltage When State of Charge = 55%.
} REG1C;

typedef struct {
	uint8_t V_SOC_69 : 8; // Battery Voltage When State of Charge = 69%.
} REG1D;

typedef struct {
	uint8_t V_SOC_84 : 8; // Battery Voltage When State of Charge = 84%.
} REG1E;

typedef struct {
	uint8_t V_SOC_100 : 8; // Battery Voltage When State of Charge = 100%.
} REG1F;

typedef struct {
	uint8_t BAT_CAP : 8; // Battery Capacity Input. Battery Capacity = (BAT_CAP × 2) mAh
} REG20;

typedef struct {
	uint8_t BAT_SOC : 7; // Battery State of Charge Output
	uint8_t RES 	: 1; // Reserved
} REG21;

typedef enum {
	BATCAP_AGE_0_8 = 0b00,
	BATCAP_AGE_1_5 = 0b01,
	BATCAP_AGE_3_1 = 0b10,
	BATCAP_AGE_6_3 = 0b11,

} BATCAP_AGE;

typedef enum {
	BATCAP_TEMP_0_2 = 0b00,
	BATCAP_TEMP_0_4 = 0b01,
	BATCAP_TEMP_0_6 = 0b10,
	BATCAP_TEMP_0_8 = 0b11,

} BATCAP_TEMP;


typedef struct {
	bool EN_BATCAP_AGE 		: 1; // Battery Capacity Aging Compensation Function Selection.
	bool EN_BATCAP_TEMP 	: 1; // Battery Capacity Temperature Compensation Function Selection.
	uint8_t RES 			: 2; // Reserved
	BATCAP_TEMP BATCAP_TEMP : 2; // Battery Capacity Compensation with Temperature Coefficient.
	BATCAP_AGE BATCAP_AGE 	: 2; // Battery Capacity Reduction Percentage When BAT_SOCACM Overflows.
} REG22;

typedef struct {
	uint8_t BAT_SOCACM_H : 8; // Highest Eight Bits of an 8-Bit Accumulation of the Charge State. Number of Times for Charging = BAT_SOCACM[11:0]/100
} REG23;

typedef struct {
	uint8_t RES 		 : 4; // Reserved
	uint8_t BAT_SOCACM_L : 4; // Lowest Four Bits of a 4-Bit Accumulation of the Charge State. Number of Times for Charging = BAT_SOCACM[11:0]/100
} REG24;

typedef struct {
	uint8_t VBAT_READ_H : 8; // Battery Voltage Reading of the Highest Eight Bits (mV)
} REG25;

typedef struct {
	uint8_t RES 		 : 3; // Reserved
	uint8_t VBAT_READ_L  : 5; // Battery Voltage Reading of the Lowest Five Bits (mV)
} REG26;

typedef enum {
	SOC_LOW_TH_6 = 0b00,
	SOC_LOW_TH_11 = 0b01,
	SOC_LOW_TH_21 = 0b10,
	SOC_LOW_TH_31 = 0b11,

} SOC_LOW_TH;

typedef enum {
	SLP_CURR_5mA = 0b00,
	SLP_CURR_10mA = 0b01,
	SLP_CURR_20mA = 0b10,
	SLP_CURR_40mA = 0b11,

} SLP_CURR;

typedef enum {
	SLP_TIME_1min = 0b00,
	SLP_TIME_4min = 0b01,
	SLP_TIME_8min = 0b10,
	SLP_TIME_16min = 0b11,

} SLP_TIME;

typedef struct {
	bool EN_FG 				: 1; // Fuel Gauge Enable
	bool FG_MODE 			: 1; // Fuel Gauge Operation Mode Selection. HIGH -> SLEEP, LOW -> ACTIVE.
	SLP_TIME SLP_TIME 		: 2; // Fuel Gauge Update Rate Of The Sleep Mode
	SLP_CURR SLP_CURR 		: 2; // Fuel Gauge Sleep Mode Current Threshold
	SOC_LOW_TH SOC_LOW_TH   : 2; // Indication of Low State of Charge Threshold
} REG27;

typedef struct {
	uint8_t RES 	: 7; // Reserved
	bool SOC_RESET 	: 1; // Write 1, then write 0 to refresh the BAT_SOC, VBAT_READ_H, and VBAT_READ_L registers.
} REG28;

typedef enum {
	BUCK_SS_1ms = 0b00,
	BUCK_SS_8ms = 0b01,
	BUCK_SS_64ms = 0b10,
	BUCK_SS_512ms = 0b11,

} BUCK_SS;

typedef enum {
	BUCK_ILIM_100mA = 0b00,
	BUCK_ILIM_200mA = 0b01,
	BUCK_ILIM_300mA = 0b10,
	BUCK_ILIM_400mA = 0b11,

} BUCK_ILIM;

typedef enum {
	BUCK_MODE_HYSTERSIS = 0b0,
	BUCK_MODE_FPWM = 0b1,
} BUCK_MODE;

typedef struct {
	bool EN_BUCK 		: 1; // Buck Enable Control.
	bool DISCHG_BUCK  	: 1; // Configure Output Discharge Functionality for Buck.
	bool STP_BUCK  		: 1; // Enable Stop Feature to Buck Regulator.
	BUCK_MODE BUCK_MODE : 1; // Buck Operate Mode Selection.
	BUCK_ILIM BUCK_ILIM : 2; // Buck Regulator Peak Current Limit.
	BUCK_SS BUCK_SS 	: 2; // Buck Regulator Output Soft Start Time.
} REG29;

typedef enum {
	BUCK_DLY_0us = 0b00,
	BUCK_DLY_5us = 0b01,
	BUCK_DLY_10us = 0b10,
	BUCK_DLY_20us = 0b11,

} BUCK_DLY;

typedef enum {
	VOUT_BUCK_0_60V = 0b000000,
	VOUT_BUCK_0_65V = 0b000001,
	VOUT_BUCK_0_70V = 0b000010,
	VOUT_BUCK_0_75V = 0b000011,
	VOUT_BUCK_0_80V = 0b000100,
	VOUT_BUCK_0_85V = 0b000101,
	VOUT_BUCK_0_90V = 0b000110,
	VOUT_BUCK_0_95V = 0b000111,
	VOUT_BUCK_1_00V = 0b001000,
	VOUT_BUCK_1_05V = 0b001001,
	VOUT_BUCK_1_10V = 0b001010,
	VOUT_BUCK_1_15V = 0b001011,
	VOUT_BUCK_1_20V = 0b001100,
	VOUT_BUCK_1_25V = 0b001101,
	VOUT_BUCK_1_30V = 0b001110,
	VOUT_BUCK_1_35V = 0b001111,
	VOUT_BUCK_1_40V = 0b010000,
	VOUT_BUCK_1_45V = 0b010001,
	VOUT_BUCK_1_50V = 0b010010,
	VOUT_BUCK_1_55V = 0b010011,
	VOUT_BUCK_1_60V = 0b010100,
	VOUT_BUCK_1_65V = 0b010101,
	VOUT_BUCK_1_70V = 0b010110,
	VOUT_BUCK_1_75V = 0b010111,
	VOUT_BUCK_1_80V = 0b011000,
	VOUT_BUCK_1_85V = 0b011001,
	VOUT_BUCK_1_90V = 0b011010,
	VOUT_BUCK_1_95V = 0b011011,
	VOUT_BUCK_2_00V = 0b011100,
	VOUT_BUCK_2_05V = 0b011101,
	VOUT_BUCK_2_10V = 0b011110,
	VOUT_BUCK_2_15V = 0b011111,
	VOUT_BUCK_2_20V = 0b100000,
	VOUT_BUCK_2_25V = 0b100001,
	VOUT_BUCK_2_30V = 0b100010,
	VOUT_BUCK_2_35V = 0b100011,
	VOUT_BUCK_2_40V = 0b100100,
	VOUT_BUCK_2_45V = 0b100101,
	VOUT_BUCK_2_50V = 0b100110,
	VOUT_BUCK_2_55V = 0b100111,
	VOUT_BUCK_2_60V = 0b101000,
	VOUT_BUCK_2_65V = 0b101001,
	VOUT_BUCK_2_70V = 0b101010,
	VOUT_BUCK_2_75V = 0b101011,
	VOUT_BUCK_2_80V = 0b101100,
	VOUT_BUCK_2_85V = 0b101101,
	VOUT_BUCK_2_90V = 0b101110,
	VOUT_BUCK_2_95V = 0b101111,
	VOUT_BUCK_3_00V = 0b110000,
	VOUT_BUCK_3_05V = 0b110001,
	VOUT_BUCK_3_10V = 0b110010,
	VOUT_BUCK_3_15V = 0b110011,
	VOUT_BUCK_3_20V = 0b110100,
	VOUT_BUCK_3_25V = 0b110101,
	VOUT_BUCK_3_30V = 0b110110,
	VOUT_BUCK_3_35V = 0b110111,
	VOUT_BUCK_3_40V = 0b111000,
	VOUT_BUCK_3_45V = 0b111001,
	VOUT_BUCK_3_50V = 0b111010,
	VOUT_BUCK_3_55V = 0b111011,
	VOUT_BUCK_3_60V = 0b111100,
	VOUT_BUCK_3_65V = 0b111101,
	VOUT_BUCK_3_70V = 0b111110,
	VOUT_BUCK_3_75V = 0b111111,

} VOUT_BUCK;

typedef struct {
	VOUT_BUCK VOUT_BUCK : 6; // Buck Output Voltage Setting.
	BUCK_DLY BUCK_DLY 	: 2; // Buck Switch Delay Time in Hystersis.
} REG2A;

typedef enum {
	BUCKBST_SS_1ms = 0b00,
	BUCKBST_SS_8ms = 0b01,
	BUCKBST_SS_64ms = 0b10,
	BUCKBST_SS_512ms = 0b11,

} BUCKBST_SS;

typedef enum {
	BUCKBST_ILIM_100mA = 0b000,
	BUCKBST_ILIM_200mA = 0b001,
	BUCKBST_ILIM_300mA = 0b010,
	BUCKBST_ILIM_400mA = 0b011,
	BUCKBST_ILIM_500mA = 0b100,
	BUCKBST_ILIM_600mA = 0b101,
	BUCKBST_ILIM_700mA = 0b110,
	BUCKBST_ILIM_800mA = 0b111,

} BUCKBST_ILIM;

typedef struct {
	bool EN_BUCKBST  			: 1; // Buck Boost Enable Control.
	bool DISCHG_BUCKBST 		: 1; // Configure Output Discharge Functionality for Buck Boost.
	bool STP_BUCKBST  			: 1; // Enable Stop Feature to Buck Boost Regulator.
	BUCKBST_ILIM BUCKBST_ILIM 	: 3; // Buck Boost Regulator Peak Current Limit.
	BUCKBST_SS BUCKBST_SS 		: 2; // Buck Boost Regulator Output Soft Start Time.
} REG2B;

typedef enum {
	BUCKBST_DLY_0us = 0b00,
	BUCKBST_DLY_5us = 0b01,
	BUCKBST_DLY_10us = 0b10,
	BUCKBST_DLY_20us = 0b11,

} BUCKBST_DLY;

typedef enum {
	VOUT_BUCKBST_1_80V = 0b000000,
	VOUT_BUCKBST_1_90V = 0b000001,
	VOUT_BUCKBST_2_00V = 0b000010,
	VOUT_BUCKBST_2_10V = 0b000011,
	VOUT_BUCKBST_2_20V = 0b000100,
	VOUT_BUCKBST_2_30V = 0b000101,
	VOUT_BUCKBST_2_40V = 0b000110,
	VOUT_BUCKBST_2_50V = 0b000111,
	VOUT_BUCKBST_2_60V = 0b001000,
	VOUT_BUCKBST_2_70V = 0b001001,
	VOUT_BUCKBST_2_80V = 0b001010,
	VOUT_BUCKBST_2_90V = 0b001011,
	//1.80V - 2.90V -> 100mV step; 2.90V - 5.50V -> 50mV step;
	VOUT_BUCKBST_2_95V = 0b001100,
	VOUT_BUCKBST_3_00V = 0b001101,
	VOUT_BUCKBST_3_05V = 0b001110,
	VOUT_BUCKBST_3_10V = 0b001111,
	VOUT_BUCKBST_3_15V = 0b010000,
	VOUT_BUCKBST_3_20V = 0b010001,
	VOUT_BUCKBST_3_25V = 0b010010,
	VOUT_BUCKBST_3_30V = 0b010011,
	VOUT_BUCKBST_3_35V = 0b010100,
	VOUT_BUCKBST_3_40V = 0b010101,
	VOUT_BUCKBST_3_45V = 0b010110,
	VOUT_BUCKBST_3_50V = 0b010111,
	VOUT_BUCKBST_3_55V = 0b011000,
	VOUT_BUCKBST_3_60V = 0b011001,
	VOUT_BUCKBST_3_65V = 0b011010,
	VOUT_BUCKBST_3_70V = 0b011011,
	VOUT_BUCKBST_3_75V = 0b011100,
	VOUT_BUCKBST_3_80V = 0b011101,
	VOUT_BUCKBST_3_85V = 0b011110,
	VOUT_BUCKBST_3_90V = 0b011111,
	VOUT_BUCKBST_3_95V = 0b100000,
	VOUT_BUCKBST_4_00V = 0b100001,
	VOUT_BUCKBST_4_05V = 0b100010,
	VOUT_BUCKBST_4_10V = 0b100011,
	VOUT_BUCKBST_4_15V = 0b100100,
	VOUT_BUCKBST_4_20V = 0b100101,
	VOUT_BUCKBST_4_25V = 0b100110,
	VOUT_BUCKBST_4_30V = 0b100111,
	VOUT_BUCKBST_4_35V = 0b101000,
	VOUT_BUCKBST_4_40V = 0b101001,
	VOUT_BUCKBST_4_45V = 0b101010,
	VOUT_BUCKBST_4_50V = 0b101011,
	VOUT_BUCKBST_4_55V = 0b101100,
	VOUT_BUCKBST_4_60V = 0b101101,
	VOUT_BUCKBST_4_65V = 0b101110,
	VOUT_BUCKBST_4_70V = 0b101111,
	VOUT_BUCKBST_4_75V = 0b110000,
	VOUT_BUCKBST_4_80V = 0b110001,
	VOUT_BUCKBST_4_85V = 0b110010,
	VOUT_BUCKBST_4_90V = 0b110011,
	VOUT_BUCKBST_4_95V = 0b110100,
	VOUT_BUCKBST_5_00V = 0b110101,
	VOUT_BUCKBST_5_05V = 0b110110,
	VOUT_BUCKBST_5_10V = 0b110111,
	VOUT_BUCKBST_5_15V = 0b111000,
	VOUT_BUCKBST_5_20V = 0b111001,
	VOUT_BUCKBST_5_25V = 0b111010,
	VOUT_BUCKBST_5_30V = 0b111011,
	VOUT_BUCKBST_5_35V = 0b111100,
	VOUT_BUCKBST_5_40V = 0b111101,
	VOUT_BUCKBST_5_45V = 0b111110,
	VOUT_BUCKBST_5_50V = 0b111111,

} VOUT_BUCKBST;

typedef struct {
	VOUT_BUCKBST VOUT_BUCKBST 	: 6; // Buck Boost Output Voltage Setting.
	BUCKBST_DLY BUCKBST_DLY 	: 2; // Buck Boost Switch Delay Time in Hystersis
} REG2C;

typedef enum {
	RESET_TIME_200ms = 0b0,
	RESET_TIME_1600ms = 0b1
} RESET_TIME;

typedef enum {
	WD_TIME_12_5s = 0b00,
	WD_TIME_25_6s = 0b01,
	WD_TIME_50_0s = 0b10,
	WD_TIME_100_0s = 0b11,

} WD_TIME;

typedef struct {
	bool RESET_WD 			: 1; // When high, the watchdog safety timer resets. The RESET_WD bit is reset automatically.
	bool EN_MR_SD 			: 1; // When high, the device enters shipment mode after MR presses low for 12 sec.
	bool EN_WD  			: 1; // When high, the watchdog timer function is enabled.
	WD_TIME WD_TIME 		: 2; // Watchdog Timeout Period Selection.
	RESET_TIME RESET_TIME 	: 1; // RESET Timeout Period Selection.
	bool VOUT2_RST  		: 1; // Buck Boost Output Voltage Monitor to RESET Selection.
	bool VOUT1_RST  		: 1; // Buck Output Voltage Monitor to RESET Selection.
} REG2D;

typedef struct {
	bool TSD110 		: 1; // When high, the temperature shutdown fault occurs.
	uint8_t RES1 		: 1; // Reserved
	bool WD_TIMEOUT 	: 1; // When high, watchdog timeout occurred.
	uint8_t RES 		: 1; // Reserved
	bool BAT_CHGOV 		: 1; // When high, this bit indicates that the battery is overvoltage during overcharge.
	bool BAT_CHGOC 		: 1; // When high, this bit indicates that the battery is overcurrent during overcharge.
	bool BAT_OC  		: 1; // When high, this bit indicates that the battery is overcurrent during overdischarge.
	bool BAT_UV  		: 1; // When high, this bit indicates that the battery is undervoltage when overdischarging.
} REG2E;

typedef struct {
	bool VOUT1OK   		: 1; // This bit shows real-time power-good status for the buck regulator.
	bool VOUT2OK  		: 1; // This bit shows real-time power good status for the buck boost regulator
	bool BATOK   		: 1; // This bit shows the real-time status of the battery voltage. !!ONLY ACTIVE WHEN fuel gauge function is enabled.!!
	bool VBUSOK  		: 1; // This bit shows the real-time status of the VBUS pin voltage.
	bool CHG_CMPLT 		: 1; // This bit shows battery charge complete.
	bool MR_PRESS   	: 1; // When high, this bit indicates that the MR pin is pulled to low after tDG.
	uint8_t RES 		: 2; // Reserved
} REG2F;

typedef struct {
	bool VOUT1OK_MASK1   	: 1; // This bit configures the external PGOOD1 pin.
	bool VOUT2OK_MASK1   	: 1; // This bit configures the external PGOOD1 pin.
	bool BATOK_MASK1   		: 1; // This bit configures the external PGOOD1 pin.
	bool VBUSOK_MASK1   	: 1; // This bit configures the external PGOOD1 pin.
	bool CHGCMPLT_MASK1 	: 1; // This bit configures the external PGOOD1 pin.
	uint8_t RES 			: 2; // Reserved
	bool PG1_REV    		: 1; // This bit configures the active low output of the PGOOD1 pin.
} REG30;

typedef struct {
	bool VOUT1OK_MASK2   	: 1; // This bit configures the external PGOOD2 pin.
	bool VOUT2OK_MASK2   	: 1; // This bit configures the external PGOOD2 pin.
	bool BATOK_MASK2   		: 1; // This bit configures the external PGOOD2 pin.
	bool VBUSOK_MASK2   	: 1; // This bit configures the external PGOOD2 pin.
	bool CHGCMPLT_MASK2 	: 1; // This bit configures the external PGOOD2 pin.
	uint8_t RES 			: 2; // Reserved
	bool PG2_REV    		: 1; // This bit configures the active low output of the PGOOD2 pin.
} REG31;

typedef struct {
	bool EN_VBUS_INT    : 1; // When high, the VBUS pin voltage threshold interrupt is allowed.
	bool EN_CHG_INT    	: 1; // When high, the charger mode change interrupt is allowed.
	bool EN_BAT_INT    	: 1; // When high, the battery voltage threshold interrupt is allowed.
	bool EN_THR_INT    	: 1; // When high, the THR temperature threshold interrupt is allowed.
	bool EN_BATPRO_INT 	: 1; // When high, the battery protection interrupt is allowed.
	bool EN_ADPICHG_INT : 1; // When high, the VBUS adaptive charge current-limit interrupt is allowed.
	bool EN_SOCACM_INT  : 1; // When high, the state of e tcharge accumulation interrupt is allowed.
	bool EN_SOCLOW_INT  : 1; // When high, the battery low state of the charge interrupt is allowed.
} REG32;

typedef struct {
	uint8_t RES 			: 4; // Reserved
	bool EN_BUCKBSTPG_INT  	: 1; // When high, the VOUT2OK change interrupt is allowed.
	bool EN_BUCKPG_INT  	: 1; // When high, the VOUT1OK change interrupt is allowed.
	bool EN_WD_INT  		: 1; // When high, the watchdog alarm interrupt is allowed.
	bool EN_MR_INT  		: 1; // When high, the MR press interrupt is allowed.
} REG33;

typedef struct {
	bool VBUS_INT    	: 1; // When high, this bit indicates an interrupt caused by VBUS voltage threshold.
	bool CHG_INT    	: 1; //When high, this bit indicates an interrupt caused by a charger mode change.
	bool BAT_INT    	: 1; // When high, this bit indicates an interrupt caused by battery voltage thresholds.
	bool THR_INT    	: 1; // When high, this bit indicates an interrupt caused by THR temperature thresholds.
	bool BATPRO_INT 	: 1; // When high, this bit indicates an interrupt caused by battery protection triggered with battery fault events.
	bool ADPICHG_INT 	: 1; // When high, this bit indicates an interrupt caused by VBUS input current-limit adaptive regulation.
	bool SOCACM_INT  	: 1; // When high, this bit indicates an interrupt caused by state of charge accumulation to 4096 points and an overflow of points.
	bool SOCLOW_INT  	: 1; // When high, this bit indicates an interrupt caused by low battery voltage.
} REG34;

typedef struct {
	uint8_t RES 			: 4; // Reserved
	bool BUCKBSTPG_INT  	: 1; // When high, this bit indicates an interrupt caused by a VOUT2OK trigger.
	bool BUCKPG_INT  		: 1; // When high, this bit indicates an interrupt caused by a VOUT1OK trigger.
	bool WD_INT  			: 1; // When high, this bit indicates an interrupt caused by the watchdog alarm.
	bool MR_INT  			: 1; // When high, this bit indicates an interrupt caused by the MR press.
} REG35;

typedef struct {
	bool EN_SHIPMODE  		: 1; // When high, the ADP5360 enters shipment mode. When low, shipment mode is disabled.
	uint8_t RES 			: 7; // Reserved
} REG36;

#endif /* ADP5360_REG_H_ */
