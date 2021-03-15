/*
 * cmd_vni.c  
 *
 * Copyright 2013 Amazon Technologies, Inc. All Rights Reserved.
 *
 * The code contained herein is licensed under the GNU General Public
 * License. You may obtain a copy of the GNU General Public License
 * Version 2 or later at the following locations:
 *
 * http://www.opensource.org/licenses/gpl-license.html
 * http://www.gnu.org/copyleft/gpl.html
 */

#include <common.h>
#include <command.h>
#include <linux/ctype.h>
#include <pmic.h>
#include <pmic_max77696.h>
#include <asm/io.h>
#include <asm/arch/mx6.h>
#include <asm/arch/mx6sl_pins.h>
#include <asm/arch/iomux-v3.h>
#include <asm/arch/gpio.h>
#include <asm/arch/board-mx6sl_wario.h>

#define atoi(x)         simple_strtoul(x,NULL,10)

extern int pmic_fg_otp_check(void);

int do_vni (cmd_tbl_t *cmdtp, int flag, int argc, char *argv[])
{
	int res = 1;  /* default is failure */
	unsigned short val = 0;
	int curr, temp;
	int brightness = 0;
	if(strcmp(argv[1], "vcom") == 0) {
	    if(strcmp(argv[2], "set") == 0 ){
			if(pmic_vcom_set(argv[3]) != PMIC_VNI_TEST_PASS ) {
				printf("Enable Vcom	failed!\n");
				res = 1;
			}else {									
				printf("Turn on VCOM\n");
			}
	    }
	    else if(strcmp(argv[2], "off") == 0 ) {
			if( pmic_enable_vcom(0) != PMIC_VNI_TEST_PASS )	{
				printf("disable Vcom  failed!\n");
				res = 1;
			}else{
				printf("Turn off VCOM\n");
			}
	   }else {
			cmd_usage(cmdtp);
			return 1;
	  }
	}else if(strcmp(argv[1], "batt") == 0) {
	/*will add read battery info here*/	
	    if(strcmp(argv[2], "vol") == 0 ){
			if(!pmic_fg_read_voltage(&val)) {
				printf("Read voltage failed!\n");
				res = 1;
			}else {									
				printf("FG voltage =%dmV\n",val);
			}
	    }
	    else if(strcmp(argv[2], "curr") == 0 ) {
			if(!pmic_fg_read_avg_current(&curr))	{
				printf("Read FG Current failed!\n");
				res = 1;
			}else{
				printf("FG Current = %dmA\n",curr);
			}
	   }
	   else if(strcmp(argv[2], "temp") == 0 ){
		    if(!pmic_fg_read_temperature(&temp)) {
				 printf("Read FG temperature failed!\n");
				 res = 1;
			 }else {								 
				printf("FG Temperature = %dC\n",temp);
			 }
		 }
	   else if(strcmp(argv[2], "cap") == 0 ) {
			 if(!pmic_fg_read_capacity(&val)) {
				 printf("Read FG capacity  failed!\n");
				 res = 1;
			 }else{
				 printf("FG Capacity = %d Percent\n",val);
			 }
		}
	   else {
		   cmd_usage(cmdtp);
		   return 1;

	   	}
	   
	}else if(strcmp(argv[1], "chg") == 0) {
  	       if(strcmp(argv[2], "trickle") == 0 ){
                    printf("Set charge current to 66.7mA\n");
                    pmic_charger_set_current(MAX77696_CHARGER_CURRENT_TRICKLE);
  	       }else if(strcmp(argv[2], "default") == 0 ) {
  	            printf("Set charge current to 300mA\n");
                    pmic_charger_set_current(MAX77696_CHARGER_CURRENT_DEFAULT);
               }else if(strcmp(argv[2], "fast") == 0 ) {
                    printf("Set charge current to 466mA\n");
	            pmic_charger_set_current(MAX77696_CHARGER_CURRENT_FAST);
               }else {
	            cmd_usage(cmdtp);
	            return 1;
	            }
	}else if(strcmp(argv[1], "gpio") == 0) {
		if ((argc == 4) && (strcmp(argv[2], "3gm_shutdown") == 0)) {
			curr = atoi(argv[3]) ? 1 : 0;
			printf("set 3gm_shutdown to %d\n", curr);
			gpio_direction_output(MX6_WARIO_3GM_SHUT_DOWN, curr);
		}

	} else if(strcmp(argv[1], "display") == 0) {
		unsigned int rail_enable;

		if (strcmp(argv[2], "on") == 0) {
			rail_enable = 1;
		} else {
			rail_enable = 0;
		}
		printf("set LSW4 to %d\n", rail_enable);
		pmic_enable_display_power_rail(rail_enable);

	}else if(strcmp(argv[1], "fl") == 0) {	         
             brightness = simple_strtoul(argv[2], NULL, 10); 
			 printf("set front light brightness:%d\n",brightness);
             pmic_fl_set(brightness);

    } else if(strcmp(argv[1], "fg") == 0) {
       if (strcmp(argv[2], "otpchk") == 0) {
            printf("MAX77696-FG OTP TIMER TEST\n");
            pmic_fg_otp_check();
       } else {
           cmd_usage(cmdtp);
           return 1;
       }
	}else {
	       cmd_usage(cmdtp);
	       return 1;
	}

	return 0;
}

void mx60_wan4v2_ldo_gpio(int on)
{
	mxc_iomux_v3_setup_pad(MX6SL_PAD_EPDC_PWRCTRL3__GPIO_2_10);
	/* set as output high */
	gpio_direction_output(MX6SL_ARM2_EPDC_PWRCTRL3, on);
}
void mx60_wan4v2_fet_gpio(int on)
{
	mxc_iomux_v3_setup_pad(MX6SL_PAD_EPDC_PWRCTRL1__GPIO_2_8);
	/* set as output high */
	gpio_direction_output(MX6SL_ARM2_EPDC_PWRCTRL1, on);
}

int do_wan4v2 (cmd_tbl_t *cmdtp, int flag, int argc, char *argv[])
{
	
	if(strcmp(argv[1], "ldo") == 0) {
	    mx60_wan4v2_fet_gpio(0);//turn off fet first
	    udelay(500000);//delay 500ms to wait for fet is off
	    mx60_wan4v2_ldo_gpio(1);//turn on ldo
	    printf("Turn on 3GM_LDO_EN\n");
	}
	else if (strcmp(argv[1], "fet") == 0) {
	    mx60_wan4v2_ldo_gpio(0);//turn off ldo
	    udelay(500000);//delay 500ms to wait for fet is off
	    mx60_wan4v2_fet_gpio(1);//turn on fet 
	    printf("Turn on 3GM_FET_EN\n");
	}
	else if (strcmp(argv[1], "off") == 0) {
	    mx60_wan4v2_ldo_gpio(0);//turn off ldo
	    udelay(500000);//delay 500ms to wait for fet is off
	    mx60_wan4v2_fet_gpio(0);//turn off fet 
	    printf("Turn off 3GM_FET_EN and 3GM_LDO_EN\n");
	}
	else {
	    cmd_usage(cmdtp);
	    return 1;

	}
        return 0;
}


/***************************************************/

U_BOOT_CMD(
	vni,	5,	1,	do_vni,
	"vni    - vni pmic test\n",
	"[vcom|batt|chg|fg] args...\n"
	"vcom set <vaule> or <off>\n"
	"    - set vcom value/turn off vcom\n"
	"batt [vol|temp|curr|cap]\n"
	"    - read battery infomation\n"
	"chg [trickle|default|fast]\n"
	"    - set fast charge current\n"
	"gpio 3gm_shutdown [0/1]\n"
	"display [on/off]\n"
	"fg otpchk\n"
);

U_BOOT_CMD(
	wan4v2,	2,	1,	do_wan4v2,
	"wan4v2    - WAN module 4V2 control\n",
	"[fet|ldo|off] args...\n"
	"wan4v2 fet\n"
	"    - turn off ldo then turn on fet\n"
	"wan4v2 ldo\n"
	"    - turn off fet then turn on ldo \n"
	"wan4v2 off\n"
	"    - turn off fet and ldo\n"
);

