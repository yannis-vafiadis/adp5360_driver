/*
 * adp5360.c
 *
 *  Created on: May 4, 2025
 *      Author: Yannis Vafiadis
 */

#include "adp5360.h"


adp5360_regs_t adp5360_regs;

// Initialize the adp5360 registers: Customize to your own needs //
// IMPORTANT - CHANGE THE VTRM PARAM //
bool adp5360_init(){

	bool result = true;

	if(adp5360_read_registers(&adp5360_regs, 0x00, sizeof(adp5360_regs)) != HAL_OK){
		return false;
	}

	if(!adp5360_validate_presence(false)){
		return false;
	}

  	adp5360_regs.r02.VADPICHG = 0b100;
	adp5360_regs.r02.VSYSTEM = 0b0;

	/// --- IMPORTANT --- Set your charge current limit according to battery specification ///
	adp5360_regs.r02.ILIM = 0b100;

	/// !!! ///
	/// --- IMPORTANT --- Set your charge termination voltage  according to battery specification to avoid over charge ///
	adp5360_regs.r03.VTRM = 0b100000;
	/// --- IMPORTANT --- Set your charge termination voltage  according to battery specification to avoid over charge ///
	/// !!! ///

	adp5360_regs.r03.ITRK_DEAD = 0b10;

	adp5360_regs.r04.IEND = 0b001;
	adp5360_regs.r04.ICHG = 0b10001;

	adp5360_regs.r07.EN_CHG = 0b1;

	adp5360_regs.r0A.ITHR = 0b10;

	adp5360_regs.r11.EN_BATPRO = 0b1;
	adp5360_regs.r12.UV_DISCH = 0b1111;

	adp5360_regs.r13.OC_DISCH = 0b011;
	adp5360_regs.r14.OV_CHG = 0b01110;


	adp5360_regs.r16.V_SOC_0 = 0x60;
	adp5360_regs.r17.V_SOC_5 = 0x8B;
	adp5360_regs.r18.V_SOC_11 = 0x95;
	adp5360_regs.r19.V_SOC_19 = 0x99;
	adp5360_regs.r1A.V_SOC_28 = 0x9D;
	adp5360_regs.r1B.V_SOC_41 = 0xA3;
	adp5360_regs.r1C.V_SOC_55 = 0xA9;
	adp5360_regs.r1D.V_SOC_69 = 0xB4;
	adp5360_regs.r1E.V_SOC_84 = 0xC4;
	adp5360_regs.r1F.V_SOC_100 = 0xD4;

	//Set your battery capacity
	adp5360_regs.r20.BAT_CAP = 0b01011010;

	adp5360_regs.r27.EN_FG = 0b1;

	adp5360_regs.r2B.EN_BUCKBST = 0b1;

	//Set buck boost output voltage
	adp5360_regs.r2C.VOUT_BUCKBST = 0b110101;


	/// -- ENABLE INTERRUPTS -- ///
	adp5360_regs.r32.EN_SOCLOW_INT  = 0b1;
	adp5360_regs.r32.EN_SOCACM_INT  = 0b1;
	adp5360_regs.r32.EN_ADPICHG_INT  = 0b1;
	adp5360_regs.r32.EN_BATPRO_INT = 0b1;
	adp5360_regs.r32.EN_THR_INT  = 0b1;
	adp5360_regs.r32.EN_BAT_INT  = 0b1;
	adp5360_regs.r32.EN_CHG_INT = 0b1;
	adp5360_regs.r32.EN_VBUS_INT = 0b1;
	adp5360_regs.r33.EN_MR_INT  = 0b0;
	adp5360_regs.r33.EN_WD_INT  = 0b0;
	adp5360_regs.r33.EN_BUCKPG_INT = 0b0;
	adp5360_regs.r33.EN_BUCKBSTPG_INT  = 0b0;

	if(adp5360_write_registers(&adp5360_regs, 0x00, sizeof(adp5360_regs)) != HAL_OK){
		return false;
	}

	return result;
}

bool adp5360_validate_presence(bool read){
	if(read){
		if(adp5360_read_registers(&adp5360_regs, 0x00, 2) != HAL_OK){
			return false;
		}
	}

	if((adp5360_regs.r00.MANUF != 0b0001 && adp5360_regs.r00.MODEL != 0b0000) && (adp5360_regs.r01.REV = 0b1000)){
			return false;
	}

	return true;
}

bool adp5360_en_charging(bool enable){

	adp5360_regs.r07.EN_CHG = enable;

	if(adp5360_write_registers(&adp5360_regs, 0x07, 1) != HAL_OK){
		return false;
	}

	return true;
}

CHARGER_STATUS adp5360_get_charger_status(bool read){
	if(read){
		if(adp5360_read_registers(&adp5360_regs, 0x08, 1) != HAL_OK){
			//ERROR
		}
	}

	return adp5360_regs.r08.CHARGER_STATUS;
}

bool adp5360_is_charging(bool read){
	if(read){
		if(adp5360_read_registers(&adp5360_regs, 0x08, 1) != HAL_OK){
			//ERROR
		}
	}

	if(adp5360_regs.r08.CHARGER_STATUS == CHARGER_STATUS_TRICKLE ||
	adp5360_regs.r08.CHARGER_STATUS ==  CHARGER_STATUS_FAST_CHARGE_CC ||
	adp5360_regs.r08.CHARGER_STATUS ==CHARGER_STATUS_FAST_CHARGE_CV){
		return true;
	}

	return false;
}

BAT_CHG_STATUS adp5360_get_battery_status(bool read){
	if(read){
		if(adp5360_read_registers(&adp5360_regs, 0x09, 1) != HAL_OK){
			//ERROR
		}
	}

	return adp5360_regs.r09.BAT_CHG_STATUS;
}

bool adp5360_is_battery_ok(bool read){
	if(read){
		if(adp5360_read_registers(&adp5360_regs, 0x09, 1) != HAL_OK){
			//ERROR
		}
	}

	if(adp5360_regs.r09.BAT_OV_STATUS || adp5360_regs.r09.BAT_UV_STATUS){
		return false;
	}

	if(adp5360_regs.r09.THR_STATUS == THR_STATUS_BAT_HOT){
		return false;
	}

	if(adp5360_regs.r09.BAT_CHG_STATUS == BAT_CHG_STATUS_NO_BAT){
		return false;
	}

	return true;
}

bool adp5360_en_buck(bool enable){
	adp5360_regs.r29.EN_BUCK = enable;
	if(adp5360_write_registers(&adp5360_regs, 0x29, 1) != HAL_OK){
		return false;
	}
	return true;
}



bool adp5360_en_buck_boost(bool enable){

	if(adp5360_regs.r2B.EN_BUCKBST == enable){
		return true;
	}

	adp5360_regs.r2B.EN_BUCKBST = enable;
	if(adp5360_write_registers(&adp5360_regs, 0x2B, 1) != HAL_OK){
		return false;
	}
	return true;
}


// Create your logic to call this function when the IRQ pin of the adp5360 in pulled LOW
void adp5360_interrupt_handler(void){
	adp5360_read_registers(&adp5360_regs, 0x34, 2);

	if(adp5360_regs.r34.SOCLOW_INT){
		// interrupt caused by low battery voltage
	}

	if(adp5360_regs.r34.SOCACM_INT){
		// interrupt caused by state of charge accumulation to 4096 points and an overflow of points.
	}

	if(adp5360_regs.r34.ADPICHG_INT){
		// interrupt caused by VBUS input current-limit adaptive regulation.


		// The ADPICHG_INT interrupt flag doesn't clear automatically
		adp5360_regs.r34.ADPICHG_INT = false;
		if(adp5360_write_registers(&adp5360_regs, 0x34, 1) != HAL_OK){
			// ERROR
		}
	}

	if(adp5360_regs.r34.BATPRO_INT){
		// interrupt caused by battery protection triggered with battery fault events.
	}

	if(adp5360_regs.r34.THR_INT){
			// interrupt caused by THR temperature thresholds.
	}

	if(adp5360_regs.r34.BAT_INT){
			// interrupt caused by battery voltage thresholds.
		}

	if(adp5360_regs.r34.CHG_INT){
		// interrupt caused by a charger mode change.
	}

	if(adp5360_regs.r34.VBUS_INT){
		// interrupt caused by VBUS voltage threshold.

		/* ILIM must be set every time power is connected,
		   so we write the value when we receive an VBUS interrupt
		*/
		if(adp5360_write_registers(&adp5360_regs, 0x02, 1) != HAL_OK){
			// ERROR
		}
	}

	if(adp5360_regs.r35.MR_INT){
		// interrupt caused by the MR press.
	}

	if(adp5360_regs.r35.WD_INT){
		// interrupt caused by the watchdog alarm.
	}

	if(adp5360_regs.r35.BUCKPG_INT){
		// interrupt caused by a VOUT1OK trigger
	}

	if(adp5360_regs.r35.BUCKBSTPG_INT){
		// interrupt caused by a VOUT2OK trigger
	}
}


/// --- LOW LEVEL I2C FUNCTIONS --- ///

HAL_StatusTypeDef adp5360_read_registers(
    adp5360_regs_t *regs,
    uint8_t start_reg,
    uint8_t count
) {
    // Validate register range
    if (start_reg + count > sizeof(adp5360_regs_t)) {
        return HAL_ERROR;
    }

    // Calculate destination address in the struct
    uint8_t *dest = (uint8_t *)regs + start_reg;

    // Read registers via I2C
    return HAL_I2C_Mem_Read(
    	&ADP5360_I2C_PORT,
		ADP5360_ADDRESS << 1,
        start_reg,
        I2C_MEMADD_SIZE_8BIT,
        dest,
        count,
		ADP5360_I2C_TIMEOUT
    );
}

HAL_StatusTypeDef adp5360_write_registers(
    adp5360_regs_t *regs,
    uint8_t start_reg,
    uint8_t count
) {
    // Validate register range
    if (start_reg + count > sizeof(adp5360_regs_t)) {
        return HAL_ERROR;
    }

    // Calculate destination address in the struct
    uint8_t *dest = (uint8_t *)regs + start_reg;

    // WRITE registers via I2C
    return HAL_I2C_Mem_Write(
    	&ADP5360_I2C_PORT,
		ADP5360_ADDRESS << 1,
        start_reg,
        I2C_MEMADD_SIZE_8BIT,
        dest,
        count,
		ADP5360_I2C_TIMEOUT
    );
}
/// --- END LOW LEVEL I2C FUNCTIONS --- ///
