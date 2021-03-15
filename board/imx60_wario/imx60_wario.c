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

#include <common.h>
#include <asm/io.h>
#include <asm/arch/mx6.h>
#include <asm/arch/mx6_pins.h>
#include <asm/arch/mx6sl_pins.h>
#include <asm/arch/iomux-v3.h>
#include <asm/arch/gpio.h>
#include <asm/errno.h>

#include "wario_iomux/include/iomux_config.h"

#if defined(CONFIG_MXC_EPDC)
#include <lcd.h>
#endif

#ifdef CONFIG_IMX_ECSPI
#include <imx_spi.h>
#endif

#if CONFIG_I2C_MXC_LAB126
#include <i2c.h>
#endif

#ifdef CONFIG_MMC
#include <mmc.h>
#include <fsl_esdhc.h>
#endif

#ifdef CONFIG_ARCH_MMU
#include <asm/mmu.h>
#include <asm/arch/mmu.h>
#endif

#ifdef CONFIG_CMD_CLOCK
#include <asm/clock.h>
#endif

#if defined (CONFIG_CMD_IDME)
#include <idme.h>
#endif

#if defined(CONFIG_PMIC)
#include <pmic.h>
#endif

DECLARE_GLOBAL_DATA_PTR;

static u32 system_rev;
static enum boot_device boot_dev;

/* board id and serial number. */
static u8 serial_number[CONFIG_DSN_LEN+1];
static u8 board_id[CONFIG_PCBA_LEN+1];

#ifdef CONFIG_VIDEO_MX5
extern unsigned char fsl_bmp_600x400[];
extern int fsl_bmp_600x400_size;
extern int g_ipu_hw_rev;

#if defined(CONFIG_BMP_8BPP)
unsigned short colormap[256];
#elif defined(CONFIG_BMP_16BPP)
unsigned short colormap[65536];
#else
unsigned short colormap[16777216];
#endif

static int di = 1;

extern int ipuv3_fb_init(struct fb_videomode *mode, int di,
			int interface_pix_fmt,
			ipu_di_clk_parent_t di_clk_parent,
			int di_clk_val);

static struct fb_videomode lvds_xga = {
	 "XGA", 60, 1024, 768, 15385, 220, 40, 21, 7, 60, 10,
	 FB_SYNC_EXT,
	 FB_VMODE_NONINTERLACED,
	 0,
};

vidinfo_t panel_info;
#endif

#ifdef CONFIG_IRAM_BOOT
extern void lpddr2_init(int sz);
#define LPDDR2_INIT_512 1
#define LPDDR2_INIT_256 2
#endif

#define HAPTIC_IQC_TEST_STR             "haptic_iqc"

/*
 * Disable power down counter event before the memory test
 * to avoid the wachdog reset itself after 16 secs.
 */
static void disable_watchdog_power_count_down_event(void);

void set_unused_pins(void);

int board_info_valid (u8 *info, int len)
{
    int i;

    for (i = 0; i < len; i++) {
	if ((info[i] < '0') && 
	    (info[i] > '9') &&
	    (info[i] < 'A') &&
	    (info[i] > 'Z'))
	    return 0;
    }

    return 1;
}

/*************************************************************************
 * get_board_serial() - setup to pass kernel serial number information
 *      return: alphanumeric containing the serial number.
 *************************************************************************/
const u8 *get_board_serial(void)
{
    if (!board_info_valid(serial_number, CONFIG_DSN_LEN))
	return (u8 *) "0000000000000000";
    else
	return serial_number;
}

/*************************************************************************
 * get_board_id16() - setup to pass kernel board revision information
 *      16-byte alphanumeric containing the board revision.
 *************************************************************************/
const u8 *get_board_id16(void)
{
    if (!board_info_valid(board_id, CONFIG_PCBA_LEN))
	return (u8 *) "0000000000000000";
    else
	return board_id;
}

int setup_board_info(void)
{    
#if defined(CONFIG_CMD_IDME)
    idme_check_update();

    if (idme_get_var("pcbsn", (char *) board_id, sizeof(board_id))) 
#endif
    {
	/* not found: clean up garbage characters. */
	memset(board_id, 0, sizeof(board_id));
    }

#if defined(CONFIG_CMD_IDME)
    if (idme_get_var("serial", (char *) serial_number, sizeof(serial_number))) 
#endif
    {
	/* not found: clean up garbage characters. */
	memset(serial_number, 0, sizeof(serial_number));
    }

    return 0;
}

static inline void setup_boot_device(void)
{
	uint soc_sbmr = readl(SRC_BASE_ADDR + 0x4);
	uint bt_mem_ctl = (soc_sbmr & 0x000000FF) >> 4 ;
	uint bt_mem_type = (soc_sbmr & 0x00000008) >> 3;

	switch (bt_mem_ctl) {
	case 0x0:
		if (bt_mem_type)
			boot_dev = ONE_NAND_BOOT;
		else
			boot_dev = WEIM_NOR_BOOT;
		break;
	case 0x2:
			boot_dev = SATA_BOOT;
		break;
	case 0x3:
		if (bt_mem_type)
			boot_dev = I2C_BOOT;
		else
			boot_dev = SPI_NOR_BOOT;
		break;
	case 0x4:
	case 0x5:
		boot_dev = SD_BOOT;
		break;
	case 0x6:
	case 0x7:
		boot_dev = MMC_BOOT;
		break;
	case 0x8 ... 0xf:
		boot_dev = NAND_BOOT;
		break;
	default:
		boot_dev = UNKNOWN_BOOT;
		break;
	}
}

enum boot_device get_boot_device(void)
{
	return boot_dev;
}

u32 get_board_rev(void)
{

#if defined CONFIG_MX6Q
	system_rev = 0x63000;
#elif defined CONFIG_MX6DL
	system_rev = 0x61000;
#else
	system_rev = 0x60000;
#endif
	return system_rev;
}


static const struct board_type *get_board_type(void) 
{
    int i;

    if (!board_info_valid(board_id, CONFIG_PCBA_LEN)) {
	printf("board inf invalid: %s\n", board_id);
	return NULL;
    }

    for (i = 0; i < NUM_KNOWN_BOARDS; i++) {
	if (strncmp((const char *) board_id, boards[i].id, strlen(boards[i].id)) == 0) {
	    return &(boards[i]);
	}
    }

    return NULL;
}

unsigned int get_dram_size(void) 
{
    int i;
    unsigned int size = 0;

    for (i=0; i<CONFIG_NR_DRAM_BANKS; i++) {
	size += gd->bd->bi_dram[i].size;
    }

    return size;
}

#ifdef CONFIG_FOR_FACTORY
static char boardid_input_buf[CONFIG_SYS_CBSIZE];
extern int readline_into_buffer (const char *const prompt, char * buffer);   
#endif

int dram_init(void)
{
	gd->bd->bi_dram[0].start = PHYS_SDRAM_1;

	while(1) {
		const struct board_type *board;

		board = get_board_type();

	    	if (board) {

#ifdef CONFIG_FOR_FACTORY
			gd->bd->bi_dram[0].size = PHYS_SDRAM_1_SIZE;
#else
			gd->bd->bi_dram[0].size = board->mem_size;
#endif

#ifdef CONFIG_IRAM_BOOT
	      		switch (board->mem_type) {
	        		case MEMORY_TYPE_LPDDR2:
          	    		if (board->mem_size == MEMORY_SIZE_256MB) {
                        		lpddr2_init(LPDDR2_INIT_256);
		    		} else if (board->mem_size == MEMORY_SIZE_512MB) {
		        		lpddr2_init(LPDDR2_INIT_512);
		    		} else {
		        		printf("Error! invalid memory config!\n"); 
		    		}
		    		break;
	        		default:
		    			printf("Error! unsupported memory type!\n"); 
	    		}
#endif		
			return 0;
	   	} 

#ifdef CONFIG_FOR_FACTORY
		/* Clear out buffer */
		memset(boardid_input_buf, 0, sizeof(boardid_input_buf));

		printf("Board ID is invalid!  Please enter a valid board id:\n");
		readline_into_buffer(">", boardid_input_buf);

		if (strlen(boardid_input_buf) != CONFIG_PCBA_LEN) {
			printf("\nError! Board ID must be %d chars long.\n\n", CONFIG_PCBA_LEN);
			continue;
		}

		idme_update_var("pcbsn", boardid_input_buf);

		/* Set bootmode to diags if this is the first boot */
		idme_update_var("bootmode", "uboot");
#else
		printf("Invalid board id!  Can't determine system type for RAM init.. bailing!\n");
		return 0;
#endif /* CONFIG_FOR_FACTORY */

	}

	return 0;
}

static void setup_uart(void)
{
	uart1_iomux_config();
}

#if defined (CONFIG_I2C_MXC_LAB126)
void setup_i2c(unsigned int module_base)
{
	unsigned int reg;

	switch (module_base) {
	case I2C1_BASE_ADDR:
		i2c1_iomux_config();
		
		/* Enable i2c clock */
		reg = readl(CCM_BASE_ADDR + CLKCTL_CCGR2);
		reg |= 0xC0;
		writel(reg, CCM_BASE_ADDR + CLKCTL_CCGR2);
		break;
	case I2C2_BASE_ADDR:
		i2c2_iomux_config();
		
		/* Enable i2c clock */
		reg = readl(CCM_BASE_ADDR + CLKCTL_CCGR2);
		reg |= 0x300;
		writel(reg, CCM_BASE_ADDR + CLKCTL_CCGR2);
		break;
	case I2C3_BASE_ADDR:
		/* GPIO_3 for I2C3_SCL */
		mxc_iomux_v3_setup_pad(MX6SL_PAD_EPDC_SDCE2__I2C3_SCL);
		/* GPIO_6 for I2C3_SDA */
		mxc_iomux_v3_setup_pad(MX6SL_PAD_EPDC_SDCE3__I2C3_SDA);
		/* Enable i2c clock */
		reg = readl(CCM_BASE_ADDR + CLKCTL_CCGR2);
		reg |= 0xC00;
		writel(reg, CCM_BASE_ADDR + CLKCTL_CCGR2);
		break;
	default:
		printf("Invalid I2C base: 0x%x\n", module_base);
		break;
	}
}
#endif

#ifdef CONFIG_NET_MULTI
int board_eth_init(bd_t *bis)
{
	int rc = -ENODEV;

	return rc;
}
#endif

#ifdef CONFIG_MMC

/* On this board, only SD3 can support 1.8V signalling
 * that is required for UHS-I mode of operation.
 * Last element in struct is used to indicate 1.8V support.
 */
struct fsl_esdhc_cfg usdhc_cfg[3] = {
    {USDHC1_BASE_ADDR, 1, 1, 52000000, 0, 0},
    {USDHC2_BASE_ADDR, 1, 1, 52000000, 0, 0},
    {USDHC3_BASE_ADDR, 1, 1, 52000000, 0, 0},
};

#ifdef CONFIG_DYNAMIC_MMC_DEVNO
int get_mmc_env_devno(void)
{
	uint soc_sbmr = readl(SRC_BASE_ADDR + 0x4);

	if (SD_BOOT == boot_dev || MMC_BOOT == boot_dev) {
		/* BOOT_CFG2[3] and BOOT_CFG2[4] */
		return (soc_sbmr & 0x00001800) >> 11;
	} else
		return -1;

}
#endif

#define MX6_WARIO_WIFI_PWD      IMX_GPIO_NR(3, 29)      /* KEY_ROW2 */

int usdhc_gpio_init(bd_t *bis)
{
	s32 status = 0;
	u32 index = 0;
	for (index = 0; index < CONFIG_SYS_FSL_ESDHC_NUM;
		++index) {
		switch (index) {
		case 0:
			usdhc1_iomux_config();
			break;
		case 1:
			usdhc2_iomux_config();
			break;
		case 2:
		{
			u32 reg;
			
			usdhc3_iomux_config();

			/* Set up for 1.8 V operation */
			reg = readl(USDHC3_BASE_ADDR + VENDORSPEC);
			reg |= VENDORSPEC_VSELECT;
			writel(reg, USDHC3_BASE_ADDR + VENDORSPEC);	

#if defined(CONFIG_CMD_MMC)
			/* enable wifi chip power */
			gpio_direction_output(MX6_WARIO_WIFI_PWD, 1);
#endif
			break;
		}
		default:
			printf("Warning: you configured more USDHC controllers"
				"(%d) then supported by the board (%d)\n",
				index+1, CONFIG_SYS_FSL_ESDHC_NUM);
			return status;
		}
		status |= fsl_esdhc_initialize(bis, &usdhc_cfg[index]);
	}

	return status;
}

int board_mmc_init(bd_t *bis)
{
	if (usdhc_gpio_init(bis)) {
		return -1;
	}

	return 0;
}

#ifdef CONFIG_MXC_EPDC
#ifdef CONFIG_SPLASH_SCREEN
int setup_splash_img()
{
#ifdef CONFIG_SPLASH_IS_IN_MMC
	int mmc_dev = get_mmc_env_devno();
	ulong offset = CONFIG_SPLASH_IMG_OFFSET;
	ulong size = CONFIG_SPLASH_IMG_SIZE;
	ulong addr = 0;
	char *s = NULL;
	struct mmc *mmc = find_mmc_device(mmc_dev);
	uint blk_start, blk_cnt, n;

	s = getenv("splashimage");

	if (NULL == s) {
		puts("env splashimage not found!\n");
		return -1;
	}
	addr = simple_strtoul(s, NULL, 16);

	if (!mmc) {
		printf("MMC Device %d not found\n",
			mmc_dev);
		return -1;
	}

	if (mmc_init(mmc)) {
		puts("MMC init failed\n");
		return  -1;
	}

	blk_start = ALIGN(offset, mmc->read_bl_len) / mmc->read_bl_len;
	blk_cnt   = ALIGN(size, mmc->read_bl_len) / mmc->read_bl_len;
	n = mmc->block_dev.block_read(mmc_dev, blk_start,
					blk_cnt, (u_char *)addr);
	flush_cache((ulong)addr, blk_cnt * mmc->read_bl_len);

	return (n == blk_cnt) ? 0 : -1;
#endif
}
#endif

vidinfo_t panel_info = {
	.vl_refresh = 85,
	.vl_col = 800,
	.vl_row = 600,
	.vl_pixclock = 26666667,
	.vl_left_margin = 8,
	.vl_right_margin = 100,
	.vl_upper_margin = 4,
	.vl_lower_margin = 8,
	.vl_hsync = 4,
	.vl_vsync = 1,
	.vl_sync = 0,
	.vl_mode = 0,
	.vl_flag = 0,
	.vl_bpix = 3,
	cmap:0,
};

struct epdc_timing_params panel_timings = {
	.vscan_holdoff = 4,
	.sdoed_width = 10,
	.sdoed_delay = 20,
	.sdoez_width = 10,
	.sdoez_delay = 20,
	.gdclk_hp_offs = 419,
	.gdsp_offs = 20,
	.gdoe_offs = 0,
	.gdclk_offs = 5,
	.num_ce = 1,
};

static void setup_epdc_power()
{
	unsigned int reg;

	/* Set as output */
	reg = readl(GPIO2_BASE_ADDR + GPIO_GDIR);
	reg |= (1 << 3);
	writel(reg, GPIO2_BASE_ADDR + GPIO_GDIR);

	/* Set as output */
	reg = readl(GPIO2_BASE_ADDR + GPIO_GDIR);
	reg |= (1 << 14);
	writel(reg, GPIO2_BASE_ADDR + GPIO_GDIR);

	/* Set as output */
	reg = readl(GPIO2_BASE_ADDR + GPIO_GDIR);
	reg |= (1 << 7);
	writel(reg, GPIO2_BASE_ADDR + GPIO_GDIR);
}

void epdc_power_on()
{
	unsigned int reg;

	/* Set EPD_PWR_CTL0 to high - enable EINK_VDD (3.15) */
	reg = readl(GPIO2_BASE_ADDR + GPIO_DR);
	reg |= (1 << 7);
	writel(reg, GPIO2_BASE_ADDR + GPIO_DR);

	/* Set PMIC Wakeup to high - enable Display power */
	reg = readl(GPIO2_BASE_ADDR + GPIO_DR);
	reg |= (1 << 14);
	writel(reg, GPIO2_BASE_ADDR + GPIO_DR);

	/* Wait for PWRGOOD == 1 */
	while (1) {
		reg = readl(GPIO2_BASE_ADDR + GPIO_DR);
		if (!(reg & (1 << 13)))
			break;

		udelay(100);
	}

	/* Enable VCOM */
	reg = readl(GPIO2_BASE_ADDR + GPIO_DR);
	reg |= (1 << 3);
	writel(reg, GPIO2_BASE_ADDR + GPIO_DR);

	reg = readl(GPIO2_BASE_ADDR + GPIO_DR);

	udelay(500);
}

void  epdc_power_off()
{
	unsigned int reg;
	/* Set PMIC Wakeup to low - disable Display power */
	reg = readl(GPIO2_BASE_ADDR + GPIO_DR);
	reg &= ~(1 << 14);
	writel(reg, GPIO2_BASE_ADDR + GPIO_DR);

	/* Disable VCOM */
	reg = readl(GPIO2_BASE_ADDR + GPIO_DR);
	reg &= ~(1 << 3);
	writel(reg, GPIO2_BASE_ADDR + GPIO_DR);

	/* Set EPD_PWR_CTL0 to low - disable EINK_VDD (3.15) */
	reg = readl(GPIO2_BASE_ADDR + GPIO_DR);
	reg &= ~(1 << 7);
	writel(reg, GPIO2_BASE_ADDR + GPIO_DR);
}

int setup_waveform_file()
{
#ifdef CONFIG_WAVEFORM_FILE_IN_MMC
	int mmc_dev = get_mmc_env_devno();
	ulong offset = CONFIG_WAVEFORM_FILE_OFFSET;
	ulong size = CONFIG_WAVEFORM_FILE_SIZE;
	ulong addr = CONFIG_WAVEFORM_BUF_ADDR;
	char *s = NULL;
	struct mmc *mmc = find_mmc_device(mmc_dev);
	uint blk_start, blk_cnt, n;

	if (!mmc) {
		printf("MMC Device %d not found\n",
			mmc_dev);
		return -1;
	}

	if (mmc_init(mmc)) {
		puts("MMC init failed\n");
		return -1;
	}

	blk_start = ALIGN(offset, mmc->read_bl_len) / mmc->read_bl_len;
	blk_cnt   = ALIGN(size, mmc->read_bl_len) / mmc->read_bl_len;
	n = mmc->block_dev.block_read(mmc_dev, blk_start,
		blk_cnt, (u_char *)addr);
	flush_cache((ulong)addr, blk_cnt * mmc->read_bl_len);

	return (n == blk_cnt) ? 0 : -1;
#else
	return -1;
#endif
}

static void setup_epdc()
{
	unsigned int reg;

	/* epdc iomux settings */
	epdc_iomux_config();

	/*** Set pixel clock rates for EPDC ***/

	/* EPDC AXI clk from PFD_400M, set to 396/2 = 198MHz */
	reg = readl(CCM_BASE_ADDR + CLKCTL_CHSCCDR);
	reg &= ~0x3F000;
	reg |= (0x4 << 15) | (1 << 12);
	writel(reg, CCM_BASE_ADDR + CLKCTL_CHSCCDR);

	/* EPDC AXI clk enable */
	reg = readl(CCM_BASE_ADDR + CLKCTL_CCGR3);
	reg |= 0x0030;
	writel(reg, CCM_BASE_ADDR + CLKCTL_CCGR3);

	/* EPDC PIX clk from PFD_540M, set to 540/4/5 = 27MHz */
	reg = readl(CCM_BASE_ADDR + CLKCTL_CSCDR2);
	reg &= ~0x03F000;
	reg |= (0x5 << 15) | (4 << 12);
	writel(reg, CCM_BASE_ADDR + CLKCTL_CSCDR2);

	reg = readl(CCM_BASE_ADDR + CLKCTL_CBCMR);
	reg &= ~0x03800000;
	reg |= (0x3 << 23);
	writel(reg, CCM_BASE_ADDR + CLKCTL_CBCMR);

	/* EPDC PIX clk enable */
	reg = readl(CCM_BASE_ADDR + CLKCTL_CCGR3);
	reg |= 0x0C00;
	writel(reg, CCM_BASE_ADDR + CLKCTL_CCGR3);

	panel_info.epdc_data.working_buf_addr = CONFIG_WORKING_BUF_ADDR;
	panel_info.epdc_data.waveform_buf_addr = CONFIG_WAVEFORM_BUF_ADDR;

	panel_info.epdc_data.wv_modes.mode_init = 0;
	panel_info.epdc_data.wv_modes.mode_du = 1;
	panel_info.epdc_data.wv_modes.mode_gc4 = 3;
	panel_info.epdc_data.wv_modes.mode_gc8 = 2;
	panel_info.epdc_data.wv_modes.mode_gc16 = 2;
	panel_info.epdc_data.wv_modes.mode_gc32 = 2;

	panel_info.epdc_data.epdc_timings = panel_timings;

	setup_epdc_power();

	/* Assign fb_base */
	gd->fb_base = CONFIG_FB_BASE;
}
#endif

/* For DDR mode operation, provide target delay parameter for each SD port.
 * Use cfg->esdhc_base to distinguish the SD port #. The delay for each port
 * is dependent on signal layout for that particular port.  If the following
 * CONFIG is not defined, then the default target delay value will be used.
 */
#ifdef CONFIG_GET_DDR_TARGET_DELAY
u32 get_ddr_delay(struct fsl_esdhc_cfg *cfg)
{
	/* No delay required on ARM2 board SD ports */
	return 0;
}
#endif
#endif

#ifdef CONFIG_IMX_ECSPI
s32 board_spi_get_cfg(struct imx_spi_dev_t *dev)
{
	switch (dev->slave.cs) {
	case 0:
		/* Panel flash */
		dev->base = ECSPI1_BASE_ADDR;
		dev->freq = 1000000;
		dev->ss_pol = IMX_SPI_ACTIVE_LOW;
		dev->ss = 0;
		dev->fifo_sz = 64 * 4;
		dev->us_delay = 0;
		dev->version = IMX_SPI_VERSION_2_3;
		break;
	default:
		printf("Invalid Bus ID!\n");
		break;
	}

	return 0;
}

void board_spi_io_init(struct imx_spi_dev_t *dev)
{
	u32 reg;

	switch (dev->base) {
	case ECSPI1_BASE_ADDR:
		/* Enable clock */
		reg = readl(CCM_BASE_ADDR + CLKCTL_CCGR1);
		reg |= 0x3;
		writel(reg, CCM_BASE_ADDR + CLKCTL_CCGR1);

		ecspi1_iomux_config();
		break;
	case ECSPI2_BASE_ADDR:
	case ECSPI3_BASE_ADDR:
		/* ecspi2-3 fall through */
		break;
	default:
		break;
	}
}
#endif

#ifdef CONFIG_IRAM_BOOT
/* should be called after RAM init and POST */
u8 get_ddr_mfginfo(void)
{
	u32 mapsr, madpcr0, mdscr, mdmrr;
	u8 mfgid = 0x0;
	const char * rev = (const char *) get_board_id16();

#define MMDC0_MAPSR (MMDC_P0_BASE_ADDR + 0x0404)
#define MMDC0_MADPCR0 (MMDC_P0_BASE_ADDR + 0x0410)
#define MMDC0_MDSCR (MMDC_P0_BASE_ADDR + 0x001C)
#define MMDC0_MDMRR (MMDC_P0_BASE_ADDR + 0x0034)

	// save registers
	mapsr = __raw_readl(MMDC0_MAPSR);
	madpcr0 = __raw_readl(MMDC0_MADPCR0);
	mdscr = __raw_readl(MMDC0_MDSCR);

	//disable MMDC automatic power savings
	__raw_writel(0x1, MMDC0_MAPSR);
	//set SBS_EN bit
	__raw_writel(0x100, MMDC0_MADPCR0);
	//set CON_REQ bit
	__raw_writel(0x8000, MMDC0_MDSCR);
	
	//wait for CON_ACK!
	while(!(__raw_readl(MMDC0_MDSCR) & 0x4000)) ;
	
	//allow IP access, precharge all
	__raw_writel(0x00008050, MMDC0_MDSCR);
	//set MRR cmd and addr as MR5
	__raw_writel(0x00058060, MMDC0_MDSCR);

	//poll for read data valid
	while(!(__raw_readl(MMDC0_MDSCR) & 0x400)) ;

	mdmrr = __raw_readl(MMDC0_MDMRR);
	
	if(BOARD_IS_WARIO(rev)) {
		mfgid = mdmrr & 0xFF;
	} else {
		/* On Pinot--
		   swap bits according to dataline mapping
		   --lower 16-bits map(which we care)--
		   |  SoC    |  LPDDR2 |
		   | D0-D15  |  D15-D0 | */
	
		//reverse bits - from 'Bit Twiddling Hacks'
		u16 r, v;
		r = v = mdmrr & 0xFFFF;
		int s = (sizeof(v) * 8) - 1; // extra shift needed at end
	
		for (v >>= 1; v; v >>= 1)
		{
			r <<= 1; r |= v & 1; s--;
		}
		r <<= s; // shift remaining when highest bits are zero

		//get just LSB which has mfgid
		mfgid = r & 0xFF;
	}
	
	//restore
	__raw_writel(mapsr, MMDC0_MAPSR);
	__raw_writel(madpcr0, MMDC0_MADPCR0);
	__raw_writel(mdscr, MMDC0_MDSCR);

	return mfgid;
}
#endif /*ifdef CONFIG_IRAM_BOOT */

int board_init(void)
{
#ifdef CONFIG_MFGTOOL_MODE
/* MFG firmware need reset usb to avoid host crash firstly */
#define USBCMD 0x140
	int val = readl(OTG_BASE_ADDR + USBCMD);
	val &= ~0x1;		/*RS bit */
	writel(val, OTG_BASE_ADDR + USBCMD);
#endif

	gpio_direction_output( IMX_GPIO_NR(1, 15) , 1); //SDDO8
	gpio_direction_output( IMX_GPIO_NR(1, 16) , 1); //SDDO9

	mxc_iomux_v3_init((void *)IOMUXC_BASE_ADDR);
#ifdef CONFIG_IRAM_BOOT
	//iomux setup needs to be done only once
	iomux_config();
	set_unused_pins();
	//Keeper circuit soln.
	gpio_direction_output(IMX_GPIO_NR(1,22), 1);

	//GPIO(pin EPDC_SDCE1) for PMIC LPM - disabled by default
	gpio_direction_output(IMX_GPIO_NR(1,28), 0);

	//some delay to stabilise
	udelay(2000);
#endif

	setup_boot_device();

	/* board id for linux */
	gd->bd->bi_arch_number = MACH_TYPE_MX6SL_ARM2;

	/* address of boot parameters */
	gd->bd->bi_boot_params = PHYS_SDRAM_1 + 0x100;

	setup_uart();

#ifdef CONFIG_I2C_MXC
	setup_i2c(CONFIG_SYS_I2C_PORT);
#endif

#ifdef CONFIG_MXC_EPDC
	setup_epdc();
#endif
	disable_watchdog_power_count_down_event();
	return 0;
}

inline int check_boot_mode(void) 
{
	char boot_mode[20];
	char boot_cmd[20];

#ifdef CONFIG_BIST
	setenv("bootdelay", "-1");
#endif

#if defined(CONFIG_CMD_IDME)
	if (idme_get_var("bootmode", boot_mode, 20)) 
#endif
	{
	    return -1;
	}

	boot_cmd[0] = 0;

	if (!strncmp(boot_mode, "diags", 5)) {
	    printf ("BOOTMODE OVERRIDE: DIAGS\n");
	    strcpy(boot_cmd, "run bootcmd_diags");
	} else if (!strncmp(boot_mode, "fastboot", 8)) {
	    printf ("BOOTMODE OVERRIDE: FASTBOOT\n");
	    strcpy(boot_cmd, "run bootcmd_fastboot");
	} else if (!strncmp(boot_mode, "uboot", strlen("uboot"))) {
	    printf ("BOOTMODE OVERRIDE: UBOOT\n");
	    strcpy(boot_cmd, "bist");
	} else if (!strncmp(boot_mode, "factory", 7)) {
#if defined(CONFIG_PMIC)
	    if (pmic_charging()) {
		char *cmd = (char *) CONFIG_BISTCMD_LOCATION;		
		/* Ignore any bist commands */
		cmd[0] = 0;

		printf ("BOOTMODE OVERRIDE OVERRIDE: DIAGS\n");

#if defined(CONFIG_CMD_IDME)
		/* Update bootmode idme var */
		idme_update_var("bootmode", "diags");
#endif
		/* Set the bootcmd to diags and boot immediately */
		setenv("bootcmd", "run bootcmd_diags");
		setenv("bootdelay", "0");
		
		return 0;
	    }
#endif	//CONFIG_PMIC
	    printf ("BOOTMODE OVERRIDE: FACTORY\n");
	    strcpy(boot_cmd, "run bootcmd_factory");
	} else if (!strncmp(boot_mode, "reset", 7)) {
	    printf ("BOOTMODE OVERRIDE: RESET\n");
	    strcpy(boot_cmd, "bist reset");
	} else if (!strncmp(boot_mode, "main", 4)) {
	    /* clear bootargs */
	    setenv("bootargs", "\0");

	    /* set bootcmd back to default */
	    sprintf(boot_cmd, "bootm 0x%x", CONFIG_MMC_BOOTFLASH_ADDR);
	    return 0;
    } else if (!strncmp(boot_mode, HAPTIC_IQC_TEST_STR, strlen(HAPTIC_IQC_TEST_STR))) {
	    /* Automatic go to bist and run the haptic iqc test at IQC station  */
	    sprintf(boot_cmd, "bist haptic"); 
	    /* Passing the boot_mode variable to preserve the string. The extra character
	     * can be used to select differrent waveform.  Ex: haptic_iqc0 can select waveform
             * ID 0, haptic_iqc1, for waveform ID 1, etc 
             */
	    setenv("haptic_test", boot_mode);
	} else {
	    return 0;
	}
	
	setenv("bootcmd", boot_cmd);

	return 0;
}

void board_power_off(void) 
{
#ifdef CONFIG_PMIC
    printf("Halting...");
    pmic_power_off();
    while(1);
#endif
}

    /* disable PDE to avoid glitch seen in WDOG line */

static void disable_watchdog_power_count_down_event(void)
{
    __raw_writew(~0x1, (WDOG1_BASE_ADDR+0x08));
}

int board_late_init(void)
{
    check_boot_mode();

#if defined(CONFIG_PMIC)
    if (pmic_init()) {
	    unsigned short voltage = BATTERY_INVALID_VOLTAGE;

	    if (pmic_adc_read_voltage(&voltage)) {
		    printf("Battery voltage: %d mV\n\n", voltage);
	    } else {
		    printf("Battery voltage read fail!\n\n");
	    }
    }
#endif

    return 0;
}

int checkboard(void)
{
	const char *sn, *rev;
	const struct board_type *board;

	printf("Board: ");

	board = get_board_type();
	if (board) {
	    printf("%s\n", board->name);
	} else {
	    printf("Unknown\n");
	}

	printf("Boot Reason: [ ");

	switch (__REG(SRC_BASE_ADDR + 0x8)) {
	case 0x0001:
		printf("POR");
		break;
	case 0x0009:
		printf("RST");
		break;
	case 0x0010:
	case 0x0011:
		printf("WDOG");
		break;
	default:
		printf("unknown");
	}
	printf(" ]\n");

	printf("Boot Device: ");
	switch (get_boot_device()) {
	case WEIM_NOR_BOOT:
		printf("NOR\n");
		break;
	case ONE_NAND_BOOT:
		printf("ONE NAND\n");
		break;
	case PATA_BOOT:
		printf("PATA\n");
		break;
	case SATA_BOOT:
		printf("SATA\n");
		break;
	case I2C_BOOT:
		printf("I2C\n");
		break;
	case SPI_NOR_BOOT:
		printf("SPI NOR\n");
		break;
	case SD_BOOT:
		printf("SD\n");
		break;
	case MMC_BOOT:
		printf("MMC\n");
		break;
	case NAND_BOOT:
		printf("NAND\n");
		break;
	case UNKNOWN_BOOT:
	default:
		printf("UNKNOWN\n");
		break;
	}

	/* serial number and board id */
	sn = (char *) get_board_serial();
	rev = (char *) get_board_id16();

	if (rev)
		printf ("Board Id: %.*s\n", CONFIG_PCBA_LEN, rev);

	if (sn)
		printf ("S/N: %.*s\n", CONFIG_DSN_LEN, sn);

	return 0;
}

inline int check_post_mode(void) 
{
	char post_mode[20];

#if defined(CONFIG_CMD_IDME)
	if (idme_get_var("postmode", post_mode, 20)) 
#endif
	{
		return -1;
	}

	if (!strncmp(post_mode, "normal", 6)) {
		setenv("post_hotkeys", "0");
	} else if (!strncmp(post_mode, "slow", 4)) {
		setenv("post_hotkeys", "1");
	} else if (!strncmp(post_mode, "factory", 7)) {
		setenv("bootdelay", "-1");
	}

	return 0;
}

#ifdef CONFIG_MX6SL
void udc_pins_setting(void)
{
}
#endif

#ifdef CONFIG_POST
int post_hotkeys_pressed(void)
{
    char *value;
    int ret;

    check_post_mode();

    ret = ctrlc();
    if (!ret) {
        value = getenv("post_hotkeys");
        if (value != NULL)
	    ret = simple_strtoul(value, NULL, 10);
    }
    return ret;
}
#endif

#if defined(CONFIG_POST) || defined(CONFIG_LOGBUFFER)
void post_word_store (ulong a)
{
	volatile ulong *save_addr =
		(volatile ulong *)(CONFIG_SYS_POST_WORD_ADDR);
	*save_addr = a;
}
ulong post_word_load (void)
{
  volatile ulong *save_addr =
		(volatile ulong *)(CONFIG_SYS_POST_WORD_ADDR);
  return *save_addr;
}
#endif

#ifdef CONFIG_LOGBUFFER
unsigned long logbuffer_base(void)
{
  /* OOPS_SAVE_BASE + PAGE_SIZE in linux/include/asm-arm/arch/boot_globals.h */
  return CONFIG_SYS_SDRAM_BASE + (2*4096);
}
#endif

static iomux_v3_cfg_t set_unused_pads[] = {
	//3V3
	MX6SL_PAD_KEY_COL0__GPIO_3_24,
	MX6SL_PAD_KEY_COL1__GPIO_3_26,
	MX6SL_PAD_SD1_DAT7__GPIO_5_10,
	MX6SL_PAD_SD1_DAT6__GPIO_5_7,
	MX6SL_PAD_EPDC_D10__GPIO_1_17,
	MX6SL_PAD_EPDC_D11__GPIO_1_18,
	MX6SL_PAD_EPDC_D12__GPIO_1_19,
	//1V8
	MX6SL_PAD_ECSPI2_SS0__GPIO_4_15,
	MX6SL_PAD_EPDC_PWRCOM__GPIO_2_11,
	MX6SL_PAD_FEC_RXD1__GPIO_4_18
};

void set_unused_pins(void)
{
	iomux_v3_cfg_t *p = set_unused_pads;
	int i;
	/* Set PADCTRL to 0 for all IOMUX */
	for (i = 0; i < ARRAY_SIZE(set_unused_pads); i++) {
		*p &= ~MUX_PAD_CTRL_MASK;
		*p |= ((u64)0x3000 << MUX_PAD_CTRL_SHIFT); /* enable Pull and PD */
		p++;
	}
	mxc_iomux_v3_setup_multiple_pads(set_unused_pads,
			ARRAY_SIZE(set_unused_pads));

	/* PMIC nFID pin */
	mxc_iomux_v3_setup_pad(MX6SL_PAD_FEC_TX_CLK__GPIO_4_21);	

	udelay(100);

	//Set unused GPIOs to input
	gpio_direction_input(IMX_GPIO_NR(3,24));
	gpio_direction_input(IMX_GPIO_NR(3,26));
	gpio_direction_input(IMX_GPIO_NR(5,10));
	gpio_direction_input(IMX_GPIO_NR(5,7));
	gpio_direction_input(IMX_GPIO_NR(1,17));
	gpio_direction_input(IMX_GPIO_NR(1,18));
	gpio_direction_input(IMX_GPIO_NR(1,19));
	gpio_direction_input(IMX_GPIO_NR(4,15));
	gpio_direction_input(IMX_GPIO_NR(2,11));
	gpio_direction_input(IMX_GPIO_NR(4,18));
}
