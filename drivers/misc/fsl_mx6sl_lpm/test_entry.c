/*
 * Copyright (C) 2010-2012 Freescale Semiconductor, Inc.
 *
 * See file CREDITS for list of people who contributed to this
 * project.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 * MA 02111-1307 USA
 */

#include "common.h"
#include "dram_api.h"
#include "config.h"
#include "low_power_mode.h"
#include "system_config.h"
#include <i2c.h>
#include "asm-arm/arch-mx6/regs-anadig.h"
#include <diag_struct.h>

#ifdef CONFIG_PMIC
#include <pmic.h>
#endif

#ifdef CONFIG_PMIC_MAX77696
#include <pmic_max77696.h>
#include <max77696_registers.h>
extern int pmic_fl_enable ( int enable);
#endif

extern config_t lpm_config[];
extern config_t system_config[];
extern void lpm_suspend_iomux_setup(void);

static void i2c_clock_enable(void)
{
	reg32_write(CCM_CCGR2, reg32_read(CCM_CCGR2) | 0x000000C0);
}

static void i2c_clock_disable(void)
{
	reg32_write(CCM_CCGR2, reg32_read(CCM_CCGR2) & (~0x000000C0));
}

void lower_arm_soc_voltages(void)
{
	// Set SoC LDO to Bypass
	update_config(system_config + SYS_CFG_ID_SOC_VOLTAGE     , 1500);
	//Lower ARM frequency
	update_config(system_config + SYS_CFG_ID_PLL_ARM_BYPASS     , 1);

	i2c_clock_enable();

	//Lower ARM & SoC voltages
#ifdef CONFIG_PMIC_MAX77696
	/*VDDCORE 0.95V: SW1*/
	pmic_write_reg(PM_GPIO_SADDR, BUCK_VOUT1_REG, (unsigned int)0x1C);
	/*VDDSOC 1.15V : SW2*/
	pmic_write_reg(PM_GPIO_SADDR, BUCK_VOUT2_REG, (unsigned int)0x2C);
#endif
	
	i2c_clock_disable();
}

// ---------------------------------------------------------------------
// main
// ---------------------------------------------------------------------
int test_entry (unsigned long)
    __attribute__ ((section (".low_power_code")));
int test_entry(unsigned long test_num)
{
	unsigned long action_id;
	unsigned int pmic_cnfg = 0x0;
	unsigned int pmic_glblcnfg0 = 0;

	asm ("ldr sp, =0x00960000"); // Change the stack pointer to IRAM

	action_id = test_num;
	/* Mask MMDC channel 0 Handshake */
	reg32_write(0x020c4004, 0x20000);

#ifdef CONFIG_PMIC_MAX77696
	/* disable FL */
        pmic_fl_enable(0);
#endif

	if(action_id == TEST_ID_SUSPEND_MODE) {	
#ifdef CONFIG_PMIC_MAX77696
		// set STBYEN bit
		pmic_read_reg(PM_GPIO_SADDR, (unsigned int)GLBLCNFG1_REG, &pmic_cnfg);
		pmic_write_reg(PM_GPIO_SADDR, (unsigned int)GLBLCNFG1_REG, 
			(unsigned int)(pmic_cnfg| 1<<GLBLCNFG1_STBYEN_SHIFT));

		// adjust LDO7 voltage down to 1.8 - maintain previous enabled/disabled state
		pmic_read_reg(PM_GPIO_SADDR, (unsigned int)LDO_L07_CNFG1_REG, &pmic_cnfg);
		pmic_write_reg(PM_GPIO_SADDR, (unsigned int)LDO_L07_CNFG1_REG,
			(unsigned int)( (pmic_cnfg & LDO_CNFG1_PWRMD_M) | 0x14) );
#endif
	}

        if(action_id == TEST_ID_SHIPPING_MODE) {
#ifdef CONFIG_PMIC_MAX77696
	       pmic_read_reg(PM_GPIO_SADDR, (unsigned int)GLBLCNFG0_REG, &pmic_glblcnfg0);
	       pmic_write_reg(PM_GPIO_SADDR, (unsigned int)GLBLCNFG0_REG, 
			(unsigned int)(pmic_glblcnfg0 | GLBLCNFG0_FSENT));

#endif		
       }

	lpm_config_init();
	system_config_init();

	reg32_write(ANATOP_BASE_ADDR + 0x150, reg32_read(ANATOP_BASE_ADDR + 0x150) | 0x00002000);

	switch(action_id)
	{
		case TEST_ID_SUSPEND_MODE:
			reg32_write(ANATOP_BASE_ADDR + 0x130, reg32_read(ANATOP_BASE_ADDR + 0x130) | 0x00000008);
			lpm_config_mode(LPM_LAB126_SUSPEND_MODE);
			lpm_enter_exit();
			reg32_write(ANATOP_BASE_ADDR + 0x130, reg32_read(ANATOP_BASE_ADDR + 0x130) & (~0x00000008));
			break;
		case TEST_ID_IDLE_MODE:
			pmic_enable_display_power_rail(1); //The 3v2 power gate will be enabled in idle.
			lpm_config_mode(LPM_LAB126_IDLE_2_MODE); /* Idle without ARM powergate mode */
			lower_arm_soc_voltages();
			lpm_enter_exit();
			break;
		default:
			break;
	}

	return 0;
}
