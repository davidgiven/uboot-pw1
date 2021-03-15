/*
 * inventory.c 
 *
 * Copyright 2012 Amazon Technologies, Inc. All Rights Reserved.
 *
 * The code contained herein is licensed under the GNU General Public
 * License. You may obtain a copy of the GNU General Public License
 * Version 2 or later at the following locations:
 *
 * http://www.opensource.org/licenses/gpl-license.html
 * http://www.gnu.org/copyleft/gpl.html
 */


#include <common.h>
#include <post.h>

#include <asm/io.h>
#include <asm/arch/mx6.h>
#include <asm/arch/mx6sl_pins.h>
#include <asm/arch/iomux-v3.h>
#include <asm/arch/gpio.h>

#include "lab126_mxc_i2c.h"

#include <boardid.h>

#ifdef CONFIG_PMIC
#include <pmic.h>
#endif

#ifdef CONFIG_PMIC_MAX77696
#include <pmic_max77696.h>
#endif

extern const u8 *get_board_id16(void);

#if CONFIG_POST

#define MAX77696_FG_REG_CONFIG        0x1D
#define MAX77696_UIC_REG_ENUCTRL      0x0C
#define MAX77696_EPD_REG_EPDINTM      0x63
#define MAX77696_RTC_REG_RTCDOWAX     0x11

typedef struct{
    uint origin_val;
    uint test_val;
    uint now_val; 
}pmic_inventory;

/* Read register value from i2c slave.
 *
 * unsigned char saddr ----slave address
 * unsigned int reg    ----register to read
 * unsigned int *val   ----register value
 */
int pmic_i2c_read_reg(unsigned char saddr,unsigned int reg,unsigned int *val)
{
    int retry = 3;
    while(retry--)
    {
        if(board_pmic_read_reg(saddr,reg,val))
        {
            break;
        }        
    }
    if(retry <=0 )
    {
        return 1;
    }
    udelay(100);

    return 0;
}
/* Write value to i2c slave.
 *
 * unsigned char saddr ----slave address
 * unsigned int reg    ----register to write to
 * unsigned int *val   ----register value
 */
int pmic_i2c_write_reg(unsigned char saddr,unsigned int reg,unsigned int val)
{
    int retry = 3;
    while( retry-- )
    {
        if( board_pmic_write_reg(saddr,reg,val))
        {
            break;
        }        
    }
    if(retry<=0)
    {
        return 1;
    }
    udelay(100);
    return 0;
}
enum
{
    I2C_PASS           = 0,
    I2C_FAIL           = -1,
    I2C_TEST_NOT_MATCH = -2
};
 /* test max77696 i2c slave.
 *
 * uint saddr       ----slave address
 * uchar reg        ----register to read
 * uint check_val   ----write this value to the register,then read it again then check.
 * 1. read the value from the register, save it
 * 2. write the check_val to the register, then read that register again to check the
 *    vaule is equal to the check_val or not, if equal, then pass, not will fail
 * 3. write the original value back to the register, make sure it does destroy anything
 */ 
int check_max77696 (uint saddr,uchar reg,uint check_val)
{
    int ret = I2C_FAIL;
    //int bus;   
    pmic_inventory temp;
    temp.test_val = check_val;

    //bus = i2c_get_bus_num();
    
    if( pmic_i2c_read_reg(saddr,reg,&temp.origin_val) == 0)
    {
        if( pmic_i2c_write_reg(saddr,reg,temp.test_val) == 0 )
        {
            if( pmic_i2c_read_reg(saddr,reg,&temp.now_val) == 0 )
            {
                if(temp.test_val == temp.now_val)
                {
                    ret = I2C_PASS;
                }
                else
                {
                    ret = I2C_TEST_NOT_MATCH;
                }
            }
            /** 
             Restore the original value no matter if it pass or fail
             */ 
            if( pmic_i2c_write_reg(saddr,reg,temp.origin_val) )
            {
                ret = I2C_FAIL;
            }
        }
    }
    
    switch (ret)
    {
        case I2C_PASS:
            printf("PASS\n");
            break;
        case I2C_TEST_NOT_MATCH:
            printf("Test value mismatch\n");
            break;
        case I2C_FAIL:
        default:
            printf("I2C bus failed\n");
            break;
    }
    //i2c_set_bus_num(bus);
    return ret;
}                              
/* check fuel gauge.
 *
 * unsigned char saddr ----0x34
 * unsigned int reg    ----0x1d
 * unsigned int *val   ----0x5555
 */                          
int check_max77696_fuelgauge (void)
{

    printf("Max77696 FG ");
    return check_max77696(FG_SADDR,MAX77696_FG_REG_CONFIG,0x5555);
}  
/* check usb interface circuit.
 *
 * unsigned char saddr ----0x35
 * unsigned int reg    ----0x0c
 * unsigned int *val   ----0x03
 */ 
int check_max77696_uic (void)
{
    printf("\nMax77696 UIC ");
    return check_max77696(USBIF_SADDR,MAX77696_UIC_REG_ENUCTRL,0x03);
}                          
 /* check max77696 core(io/eink display supplies/..).
 *
 * unsigned char saddr ----0x3c
 * unsigned int reg    ----0x63
 * unsigned int *val   ----0x03
 */ 
int check_max77696_core (void)
{
    printf("Max77696 Core ");
    return check_max77696(PM_GPIO_SADDR,MAX77696_EPD_REG_EPDINTM,0x03);
} 

 /* check rtc.
 *
 * unsigned char saddr ----0x68
 * unsigned int reg    ----0x11
 * unsigned int *val   ----0x03
 */ 
int check_max77696_rtc (void)
{
    printf("Max77696 RTC "); 
    return check_max77696(RTC_SADDR,MAX77696_RTC_REG_RTCDOWAX,0x03);
} 

#define MX6_WARIO_I2C1_EN	 IMX_GPIO_NR(4, 17)


int inventory_post_test (int flags)
{
    const char *rev;
    int ret   = 0;

    /* Set i2c1 enable line gpio4_17 pull high*/
    mxc_iomux_v3_setup_pad(MX6SL_PAD_FEC_RXD0__GPIO_4_17);
    /* set as output high */
    gpio_direction_output(MX6_WARIO_I2C1_EN, 1);

    rev = (char *) get_board_id16();
    if ( BOARD_IS_WARIO(rev) )  
    {
        
        ret |= check_max77696_uic();    
        ret |= check_max77696_fuelgauge();       
        ret |= check_max77696_rtc();  
        ret |= check_max77696_core();
        //ret |= check_usbmux();
    }

    else if ( BOARD_IS_PINOT(rev) || BOARD_IS_PINOT_WFO(rev) )
    {
        ret |= check_max77696_uic();    
        ret |= check_max77696_fuelgauge();       
        ret |= check_max77696_rtc();  
        ret |= check_max77696_core();	
    }

    else
    {
        printf("Device type not found!\n");
    }
    return ret;
}

#endif /* CONFIG_POST */
