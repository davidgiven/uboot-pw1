/*
 * Copyright (C) 2012 Freescale Semiconductor, Inc.
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

#include <config.h>

.globl lpddr2_init
lpddr2_init:
    stmdb sp!, {r1, r8, lr}

    /* get size */
    mov r4, r0

/*
 * CCM Configuration
 */
    ldr r0, =CCM_BASE_ADDR

/*MXC_DCD_ITEM(1, CCM_BASE_ADDR + 0x018, 0x00260324)*/
    ldr r1, =0x00260324
    str r1, [r0,#0x18]


/*
 * IOMUX Configuration
 */
    ldr r0, =IOMUXC_BASE_ADDR

/* DDR IO TYPE */
/*MXC_DCD_ITEM(2, IOMUXC_BASE_ADDR + 0x5c0, 0x00020000)*/
    ldr r1, =0x00020000
    str r1, [r0, #0x5c0]

/*MXC_DCD_ITEM(3, IOMUXC_BASE_ADDR + 0x5b4, 0x00000000)*/
    ldr r1, =0x00000000
    str r1, [r0, #0x5b4]

/* CLOCK */
/*MXC_DCD_ITEM(4, IOMUXC_BASE_ADDR + 0x338, 0x00000020)*/
    ldr r1, =0x00000020
    str r1, [r0, #0x338]

/* CONTROL */
/*MXC_DCD_ITEM(5, IOMUXC_BASE_ADDR + 0x300, 0x00000020)*/
    ldr r1, =0x00000020
    str r1, [r0, #0x300]

/*MXC_DCD_ITEM(6, IOMUXC_BASE_ADDR + 0x31c, 0x00000020)*/
    ldr r1, =0x00000020
    str r1, [r0, #0x31c]

/*MXC_DCD_ITEM(7, IOMUXC_BASE_ADDR + 0x320, 0x00080020)*/
    ldr r1, =0x00080020
    str r1, [r0, #0x320]

/*MXC_DCD_ITEM(8, IOMUXC_BASE_ADDR + 0x330, 0x00000020)*/
    ldr r1, =0x00000020
    str r1, [r0, #0x330]

/*MXC_DCD_ITEM(9, IOMUXC_BASE_ADDR + 0x334, 0x00000020)*/
    ldr r1, =0x00000020
    str r1, [r0, #0x334]

/*MXC_DCD_ITEM(10, IOMUXC_BASE_ADDR + 0x32c, 0x00000000)*/
    ldr r1, =0x00000000
    str r1, [r0, #0x32c]

/*MXC_DCD_ITEM(11, IOMUXC_BASE_ADDR + 0x33c, 0x00000008)*/
    ldr r1, =0x00000008
    str r1, [r0, #0x33c]

/*MXC_DCD_ITEM(12, IOMUXC_BASE_ADDR + 0x340, 0x00000008)*/
    ldr r1, =0x00000008
    str r1, [r0, #0x340]

/*MXC_DCD_ITEM(13, IOMUXC_BASE_ADDR + 0x5ac, 0x00000020)*/
    ldr r1, =0x00000020
    str r1, [r0, #0x5ac]

/*MXC_DCD_ITEM(14, IOMUXC_BASE_ADDR + 0x5c8, 0x00000020)*/
    ldr r1, =0x00000020
    str r1, [r0, #0x5c8]

/* DATA STROBES */
/*MXC_DCD_ITEM(15, IOMUXC_BASE_ADDR + 0x5b0, 0x00020000)*/
    ldr r1, =0x00020000
    str r1, [r0, #0x5b0]

/*MXC_DCD_ITEM(16, IOMUXC_BASE_ADDR + 0x344, 0x00003020)*/
    ldr r1, =0x00003020
    str r1, [r0, #0x344]

/*MXC_DCD_ITEM(17, IOMUXC_BASE_ADDR + 0x348, 0x00003020)*/
    ldr r1, =0x00003020
    str r1, [r0, #0x348]

/*MXC_DCD_ITEM(18, IOMUXC_BASE_ADDR + 0x34c, 0x00003020)*/
    ldr r1, =0x00003020
    str r1, [r0, #0x34c]

/*MXC_DCD_ITEM(19, IOMUXC_BASE_ADDR + 0x350, 0x00003020)*/
    ldr r1, =0x00003020
    str r1, [r0, #0x350]

/* DATA */
/*MXC_DCD_ITEM(20, IOMUXC_BASE_ADDR + 0x5d0, 0x00080000)*/
    ldr r1, =0x00080000
    str r1, [r0, #0x5d0]

/*MXC_DCD_ITEM(21, IOMUXC_BASE_ADDR + 0x5c4, 0x00000020)*/
    ldr r1, =0x00000020
    str r1, [r0, #0x5c4]

/*MXC_DCD_ITEM(22, IOMUXC_BASE_ADDR + 0x5cc, 0x00000020)*/
    ldr r1, =0x00000020
    str r1, [r0, #0x5cc]

/*MXC_DCD_ITEM(23, IOMUXC_BASE_ADDR + 0x5d4, 0x00000020)*/
    ldr r1, =0x00000020
    str r1, [r0, #0x5d4]

/*MXC_DCD_ITEM(24, IOMUXC_BASE_ADDR + 0x5d8, 0x00000020)*/
    ldr r1, =0x00000020
    str r1, [r0, #0x5d8]

/*MXC_DCD_ITEM(25, IOMUXC_BASE_ADDR + 0x30c, 0x00000020)*/
    ldr r1, =0x00000020
    str r1, [r0, #0x30c]

/*MXC_DCD_ITEM(26, IOMUXC_BASE_ADDR + 0x310, 0x00000020)*/
    ldr r1, =0x00000020
    str r1, [r0, #0x310]

/*MXC_DCD_ITEM(27, IOMUXC_BASE_ADDR + 0x314, 0x00000020)*/
    ldr r1, =0x00000020
    str r1, [r0, #0x314]

/*MXC_DCD_ITEM(28, IOMUXC_BASE_ADDR + 0x318, 0x00000020)*/
    ldr r1, =0x00000020
    str r1, [r0, #0x318]


/*
 * MMDC Configuration
 */
    ldr r0, =MMDC_P0_BASE_ADDR
/*MXC_DCD_ITEM(29, MMDC_P0_BASE_ADDR + 0x01c, 0x00008000)*/
    ldr r1, =0x00008000
    str r1, [r0, #0x01c]

/*MXC_DCD_ITEM(30, MMDC_P0_BASE_ADDR + 0x85c, 0x1b4700c7)*/
    ldr r1, =0x1b4700c7
    str r1, [r0, #0x85c]

/*MXC_DCD_ITEM(31, MMDC_P0_BASE_ADDR + 0x800, 0xa1390003)*/
    ldr r1, =0xa1390003
    str r1, [r0, #0x800]

/*MXC_DCD_ITEM(32, MMDC_P0_BASE_ADDR + 0x890, 0x00400000)*/
    ldr r1, =0x00400000
    str r1, [r0, #0x890]

/*MXC_DCD_ITEM(33, MMDC_P0_BASE_ADDR + 0x8b8, 0x00000800)*/
    ldr r1, =0x00000800
    str r1, [r0, #0x8b8]

/*MXC_DCD_ITEM(34, MMDC_P0_BASE_ADDR + 0x81c, 0x33333333)*/
    ldr r1, =0x33333333
    str r1, [r0, #0x81c]

/*MXC_DCD_ITEM(35, MMDC_P0_BASE_ADDR + 0x820, 0x33333333)*/
    ldr r1, =0x33333333
    str r1, [r0, #0x820]

/*MXC_DCD_ITEM(36, MMDC_P0_BASE_ADDR + 0x824, 0x33333333)*/
    ldr r1, =0x33333333
    str r1, [r0, #0x824]

/*MXC_DCD_ITEM(37, MMDC_P0_BASE_ADDR + 0x828, 0x33333333)*/
    ldr r1, =0x33333333
    str r1, [r0, #0x828]

/*MXC_DCD_ITEM(38, MMDC_P0_BASE_ADDR + 0x82c, 0xf3333333)*/
    ldr r1, =0xf3333333
    str r1, [r0, #0x82c]

/*MXC_DCD_ITEM(39, MMDC_P0_BASE_ADDR + 0x830, 0xf3333333)*/
    ldr r1, =0xf3333333
    str r1, [r0, #0x830]

/*MXC_DCD_ITEM(40, MMDC_P0_BASE_ADDR + 0x834, 0xf3333333)*/
    ldr r1, =0xf3333333
    str r1, [r0, #0x834]

/*MXC_DCD_ITEM(41, MMDC_P0_BASE_ADDR + 0x838, 0xf3333333)*/
    ldr r1, =0xf3333333
    str r1, [r0, #0x838]

/*MXC_DCD_ITEM(42, MMDC_P0_BASE_ADDR + 0x848, 0x4241444a)*/
    ldr r1, =0x4241444a
    str r1, [r0, #0x848]

/*MXC_DCD_ITEM(43, MMDC_P0_BASE_ADDR + 0x850, 0x3030312b)*/
    ldr r1, =0x3030312b
    str r1, [r0, #0x850]

/*MXC_DCD_ITEM(44, MMDC_P0_BASE_ADDR + 0x83c, 0x20000000)*/
    ldr r1, =0x20000000
    str r1, [r0, #0x83c]

/*MXC_DCD_ITEM(45, MMDC_P0_BASE_ADDR + 0x840, 0x0)*/
    ldr r1, =0x0
    str r1, [r0, #0x840]

/*MXC_DCD_ITEM(44, MMDC_P0_BASE_ADDR + 0x8c0, 0x24911492)*/
    ldr r1, =0x24911492
    str r1, [r0, #0x8c0]
    
/*MXC_DCD_ITEM(46, MMDC_P0_BASE_ADDR + 0x8b8, 0x00000800)*/
    ldr r1, =0x00000800
    str r1, [r0, #0x8b8]

/*MXC_DCD_ITEM(47, MMDC_P0_BASE_ADDR + 0x00c, 0x33374133)*/
    ldr r1, =0x33374133
    str r1, [r0, #0x00c]

/*MXC_DCD_ITEM(48, MMDC_P0_BASE_ADDR + 0x004, 0x00020024)*/
    ldr r1, =0x00020024
    str r1, [r0, #0x004]

/*MXC_DCD_ITEM(49, MMDC_P0_BASE_ADDR + 0x010, 0x00100A82)*/
    ldr r1, =0x00100A82
    str r1, [r0, #0x010]

/*MXC_DCD_ITEM(50, MMDC_P0_BASE_ADDR + 0x014, 0x00000093)*/
    ldr r1, =0x00000093
    str r1, [r0, #0x014]

/*MXC_DCD_ITEM(51, MMDC_P0_BASE_ADDR + 0x018, 0x00001688)*/
    ldr r1, =0x00001688
    str r1, [r0, #0x018]

/*MXC_DCD_ITEM(52, MMDC_P0_BASE_ADDR + 0x02c, 0x0f9f26d2)*/
    ldr r1, =0x0f9f26d2
    str r1, [r0, #0x02c]

/*MXC_DCD_ITEM(53, MMDC_P0_BASE_ADDR + 0x030, 0x0000020e)*/
    ldr r1, =0x0000020e
    str r1, [r0, #0x030]

/*MXC_DCD_ITEM(54, MMDC_P0_BASE_ADDR + 0x038, 0x00190778)*/
    ldr r1, =0x00190778
    str r1, [r0, #0x038]

/*MXC_DCD_ITEM(55, MMDC_P0_BASE_ADDR + 0x008, 0x00000000)*/
    ldr r1, =0x00000000
    str r1, [r0, #0x008]

/*MXC_DCD_ITEM(56, MMDC_P0_BASE_ADDR + 0x040, 0x0000004f)*/
    ldr r1, =0x0000004f
    str r1, [r0, #0x040]

/*MXC_DCD_ITEM(57, MMDC_P0_BASE_ADDR + 0x000, 0xc3110000)*/
    ldr r1, =0xc3110000
    /* check for size */
    cmp r4, #0x2
    bne default
    ldr r1, =0xc3010000
default:
    str r1, [r0, #0x000]

/*MXC_DCD_ITEM(58, MMDC_P0_BASE_ADDR + 0x01c, 0x003f8030)*/
    ldr r1, =0x003f8030
    str r1, [r0, #0x01c]

/*MXC_DCD_ITEM(59, MMDC_P0_BASE_ADDR + 0x01c, 0xff0a8030)*/
    ldr r1, =0xff0a8030
    str r1, [r0, #0x01c]

/*MXC_DCD_ITEM(60, MMDC_P0_BASE_ADDR + 0x01c, 0x82018030)*/
    ldr r1, =0x82018030
    str r1, [r0, #0x01c]

/*MXC_DCD_ITEM(61, MMDC_P0_BASE_ADDR + 0x01c, 0x04028030)*/
    ldr r1, =0x04028030
    str r1, [r0, #0x01c]

/*MXC_DCD_ITEM(62, MMDC_P0_BASE_ADDR + 0x01c, 0x03038030)*/
    ldr r1, =0x03038030
    str r1, [r0, #0x01c]

/*MXC_DCD_ITEM(63, MMDC_P0_BASE_ADDR + 0x01c, 0xff0a8038)*/
    ldr r1, =0xff0a8038
    str r1, [r0, #0x01c]

/*MXC_DCD_ITEM(64, MMDC_P0_BASE_ADDR + 0x01c, 0x82018038)*/
    ldr r1, =0x82018038
    str r1, [r0, #0x01c]

/*MXC_DCD_ITEM(65, MMDC_P0_BASE_ADDR + 0x01c, 0x04028038)*/
    ldr r1, =0x04028038
    str r1, [r0, #0x01c]

/*MXC_DCD_ITEM(66, MMDC_P0_BASE_ADDR + 0x01c, 0x02038038)*/
    ldr r1, =0x02038038
    str r1, [r0, #0x01c]

/*MXC_DCD_ITEM(67, MMDC_P0_BASE_ADDR + 0x800, 0xa1310003)*/
    ldr r1, =0xa1310003
    str r1, [r0, #0x800]

/*MXC_DCD_ITEM(68, MMDC_P0_BASE_ADDR + 0x020, 0x00001800)*/
    ldr r1, =0x00001800
    str r1, [r0, #0x020]

/*MXC_DCD_ITEM(69, MMDC_P0_BASE_ADDR + 0x818, 0x00000000)*/
    ldr r1, =0x00000000
    str r1, [r0, #0x818]

/*MXC_DCD_ITEM(70, MMDC_P0_BASE_ADDR + 0x8b8, 0x00000800)*/
    ldr r1, =0x00000800
    str r1, [r0, #0x8b8]

/*MXC_DCD_ITEM(71, MMDC_P0_BASE_ADDR + 0x004, 0x00025564)*/
    ldr r1, =0x00025564
    str r1, [r0, #0x004]

/*MXC_DCD_ITEM(72, MMDC_P0_BASE_ADDR + 0x404, 0x00011006)*/
    ldr r1, =0x00011006
    str r1, [r0, #0x404]

/*MXC_DCD_ITEM(73, MMDC_P0_BASE_ADDR + 0x01c, 0x00000000)*/
    ldr r1, =0x00000000
    str r1, [r0, #0x01c]

    ldmia sp!, {r0, r8, pc}

