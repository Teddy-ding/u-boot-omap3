/*
 * (C) Copyright 2006-2008
 * Texas Instruments, <www.ti.com>
 * Richard Woodruff <r-woodruff2@ti.com>
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

#ifndef _MEM_H_
#define _MEM_H_

#define CS0		0x0
#define CS1		0x1 /* mirror CS1 regs appear offset 0x30 from CS0 */

#ifndef __ASSEMBLY__
enum {
	STACKED = 0,
	IP_DDR = 1,
	COMBO_DDR = 2,
	IP_SDR = 3,
};
#endif /* __ASSEMBLY__ */

#define EARLY_INIT	1

/* Slower full frequency range default timings for x32 operation*/
#define SDRC_SHARING	0x00000100
#define SDRC_MR_0_SDR	0x00000031

#define DLL_OFFSET		0
#define DLL_WRITEDDRCLKX2DIS	1
#define DLL_ENADLL		1
#define DLL_LOCKDLL		0
#define DLL_DLLPHASE_72		0
#define DLL_DLLPHASE_90		1

/* rkw - need to find of 90/72 degree recommendation for speed like before */
#define SDP_SDRC_DLLAB_CTRL	((DLL_ENADLL << 3) | \
				(DLL_LOCKDLL << 2) | (DLL_DLLPHASE_90 << 1))

/* Infineon part of 3430SDP (165MHz optimized) 6.06ns
 *   ACTIMA
 *	TDAL = Twr/Tck + Trp/tck = 15/6 + 18/6 = 2.5 + 3 = 5.5 -> 6
 *	TDPL (Twr) = 15/6	= 2.5 -> 3
 *	TRRD = 12/6	= 2
 *	TRCD = 18/6	= 3
 *	TRP = 18/6	= 3
 *	TRAS = 42/6	= 7
 *	TRC = 60/6	= 10
 *	TRFC = 72/6	= 12
 *   ACTIMB
 *	TCKE = 2
 *	XSR = 120/6 = 20
 */
#define INFINEON_TDAL_165	6
#define INFINEON_TDPL_165	3
#define INFINEON_TRRD_165	2
#define INFINEON_TRCD_165	3
#define INFINEON_TRP_165	3
#define INFINEON_TRAS_165	7
#define INFINEON_TRC_165	10
#define INFINEON_TRFC_165	12
#define INFINEON_V_ACTIMA_165	((INFINEON_TRFC_165 << 27) |		\
		(INFINEON_TRC_165 << 22) | (INFINEON_TRAS_165 << 18) |	\
		(INFINEON_TRP_165 << 15) | (INFINEON_TRCD_165 << 12) |	\
		(INFINEON_TRRD_165 << 9) | (INFINEON_TDPL_165 << 6) |	\
		(INFINEON_TDAL_165))

#define INFINEON_TWTR_165	1
#define INFINEON_TCKE_165	2
#define INFINEON_TXP_165	2
#define INFINEON_XSR_165	20
#define INFINEON_V_ACTIMB_165	((INFINEON_TCKE_165 << 12) |		\
		(INFINEON_XSR_165 << 0) | (INFINEON_TXP_165 << 8) |	\
		(INFINEON_TWTR_165 << 16))

/* Micron part of 3430 EVM (165MHz optimized) 6.06ns
 * ACTIMA
 *	TDAL = Twr/Tck + Trp/tck= 15/6 + 18 /6 = 2.5 + 3 = 5.5 -> 6
 *	TDPL (Twr)	= 15/6	= 2.5 -> 3
 *	TRRD		= 12/6	= 2
 *	TRCD		= 18/6	= 3
 *	TRP		= 18/6	= 3
 *	TRAS		= 42/6	= 7
 *	TRC		= 60/6	= 10
 *	TRFC		= 125/6	= 21
 * ACTIMB
 *	TWTR		= 1
 *	TCKE		= 1
 *	TXSR		= 138/6	= 23
 *	TXP		= 25/6	= 4.1 ~5
 */
#define MICRON_TDAL_165		6
#define MICRON_TDPL_165		3
#define MICRON_TRRD_165		2
#define MICRON_TRCD_165		3
#define MICRON_TRP_165		3
#define MICRON_TRAS_165		7
#define MICRON_TRC_165		10
#define MICRON_TRFC_165		21
#define MICRON_V_ACTIMA_165 ((MICRON_TRFC_165 << 27) |			\
		(MICRON_TRC_165 << 22) | (MICRON_TRAS_165 << 18) |	\
		(MICRON_TRP_165 << 15) | (MICRON_TRCD_165 << 12) |	\
		(MICRON_TRRD_165 << 9) | (MICRON_TDPL_165 << 6) |	\
		(MICRON_TDAL_165))

#define MICRON_TWTR_165		1
#define MICRON_TCKE_165		1
#define MICRON_XSR_165		23
#define MICRON_TXP_165		5
#define MICRON_V_ACTIMB_165 ((MICRON_TCKE_165 << 12) |			\
		(MICRON_XSR_165 << 0) | (MICRON_TXP_165 << 8) |	\
		(MICRON_TWTR_165 << 16))

/* Issi part of 3430 EVM (165MHz optimized) 6.06ns
					 *   ACTIMA
					 *	TDAL = Twr/Tck + Trp/tck = 15/6 + 18 /6 = 2.5 + 3 = 5.5 -> 6
					 *	TDPL (Twr) = 15/6	= 2.5 -> 3
					 *	TRRD = 12/6	= 2
					 *	TRCD = 18/6 = 3
					 *	TRP = 18/6	= 3
					 *	TRAS = 42/6	= 7
					 *	TRC = 60/6	= 10
					 *	TRFC = 72/6	= 12
					 *   ACTIMB
					 *	TWTR =  2
					 *	TCKE =  1
					 *	TXSR =  120/6  = 20
					 *	TXP  =  1
					 */
					 #define ISSI_TDAL_165   6
					#define ISSI_TDPL_165   3
					#define ISSI_TRRD_165   2
					#define ISSI_TRCD_165   3
					#define ISSI_TRP_165    3
					#define ISSI_TRAS_165   7
					#define ISSI_TRC_165   10
					#define ISSI_TRFC_165  12
					#define ISSI_V_ACTIMA_165 ((ISSI_TRFC_165 << 27) | (ISSI_TRC_165 << 22) | (ISSI_TRAS_165 << 18) \
							| (ISSI_TRP_165 << 15) | (ISSI_TRCD_165 << 12) |(ISSI_TRRD_165 << 9) | \
							(ISSI_TDPL_165 << 6) | (ISSI_TDAL_165))

					#define ISSI_TWTR_165   2
					#define ISSI_TCKE_165   1
					#define ISSI_TXP_165    1
					#define ISSI_XSR_165    20
					#define ISSI_V_ACTIMB_165 ((ISSI_TCKE_165 << 12) | (ISSI_XSR_165 << 0)) | \
									(ISSI_TXP_165 << 8) | (ISSI_TWTR_165 << 16)

#ifdef CONFIG_OMAP3_INFINEON_DDR
#define V_ACTIMA_165 INFINEON_V_ACTIMA_165
#define V_ACTIMB_165 INFINEON_V_ACTIMB_165
#endif
#ifdef CONFIG_OMAP3_MICRON_DDR
#define V_ACTIMA_165 MICRON_V_ACTIMA_165
#define V_ACTIMB_165 MICRON_V_ACTIMB_165
#endif
#ifdef CONFIG_OMAP3_ISSI_DDR
#define V_ACTIMA_165 ISSI_V_ACTIMA_165
#define V_ACTIMB_165 ISSI_V_ACTIMB_165
#endif


#if !defined(V_ACTIMA_165) || !defined(V_ACTIMB_165)
#error "Please choose the right DDR type in config header"
#endif


/* Hynix part of AM/DM37xEVM (200MHz optimized)
 *   ACTIMA
 *	TDAL		= 6
 *	TDPL (Twr)	= 3
 *	TRRD		= 2
 *	TRCD		= 4
 *	TRP		= 3
 *	TRAS		= 8
 *	TRC		= 11
 *	TRFC		= 18
 *   ACTIMB
 *	TWTR		= 2
 *	TCKE		= 2
 *	TXP		= 1
 *	TXSR		= 28
 */
#define TDAL_200	6
#define TDPL_200	3
#define TRRD_200	2
#define TRCD_200	4
#define TRP_200		3
#define TRAS_200	8
#define TRC_200		11
#define TRFC_200	18
#define V_ACTIMA_200	((TRFC_200 << 27) | (TRC_200 << 22) | \
			(TRAS_200 << 18) | (TRP_200 << 15) |  \
			(TRCD_200 << 12) | (TRRD_200 << 9) |  \
			(TDPL_200 << 6) | (TDAL_200))

#define TWTR_200	2
#define TCKE_200	1
#define TXP_200		1
#define XSR_200		28
#define V_ACTIMB_200	(((TCKE_200 << 12) | (XSR_200 << 0)) |	\
			(TXP_200 << 8) | (TWTR_200 << 16))

#define EVM_SDRC_ACTIM_CTRLA_0	V_ACTIMA_200
#define EVM_SDRC_ACTIM_CTRLB_0	V_ACTIMB_200


/*
 * GPMC settings -
 * Definitions is as per the following format
 * #define <PART>_GPMC_CONFIG<x> <value>
 * Where:
 * PART is the part name e.g. STNOR - Intel Strata Flash
 * x is GPMC config registers from 1 to 6 (there will be 6 macros)
 * Value is corresponding value
 *
 * For every valid PRCM configuration there should be only one definition of
 * the same. if values are independent of the board, this definition will be
 * present in this file if values are dependent on the board, then this should
 * go into corresponding mem-boardName.h file
 *
 * Currently valid part Names are (PART):
 * STNOR - Intel Strata Flash
 * SMNAND - Samsung NAND
 * MPDB - H4 MPDB board
 * SBNOR - Sibley NOR
 * MNAND - Micron Large page x16 NAND
 * ONNAND - Samsung One NAND
 *
 * include/configs/file.h contains the defn - for all CS we are interested
 * #define OMAP34XX_GPMC_CSx PART
 * #define OMAP34XX_GPMC_CSx_SIZE Size
 * #define OMAP34XX_GPMC_CSx_MAP Map
 * Where:
 * x - CS number
 * PART - Part Name as defined above
 * SIZE - how big is the mapping to be
 *   GPMC_SIZE_128M - 0x8
 *   GPMC_SIZE_64M  - 0xC
 *   GPMC_SIZE_32M  - 0xE
 *   GPMC_SIZE_16M  - 0xF
 * MAP  - Map this CS to which address(GPMC address space)- Absolute address
 *   >>24 before being used.
 */
#define GPMC_SIZE_128M	0x8
#define GPMC_SIZE_64M	0xC
#define GPMC_SIZE_32M	0xE
#define GPMC_SIZE_16M	0xF

#define SMNAND_GPMC_CONFIG1	0x00000800
#define SMNAND_GPMC_CONFIG2	0x00141400
#define SMNAND_GPMC_CONFIG3	0x00141400
#define SMNAND_GPMC_CONFIG4	0x0F010F01
#define SMNAND_GPMC_CONFIG5	0x010C1414
#define SMNAND_GPMC_CONFIG6	0x1F0F0A80
#define SMNAND_GPMC_CONFIG7	0x00000C44

#define M_NAND_GPMC_CONFIG1	0x00001800
#define M_NAND_GPMC_CONFIG2	0x00141400
#define M_NAND_GPMC_CONFIG3	0x00141400
#define M_NAND_GPMC_CONFIG4	0x0F010F01
#define M_NAND_GPMC_CONFIG5	0x010C1414
#define M_NAND_GPMC_CONFIG6	0x1f0f0A80
#define M_NAND_GPMC_CONFIG7	0x00000C44

/*
 * Configuration required for AM3517EVM PC28F640P30B85 Flash
 */
#define STNOR_GPMC_CONFIG1	0x00001210
#define STNOR_GPMC_CONFIG2	0x00101001
#define STNOR_GPMC_CONFIG3	0x00020201
#define STNOR_GPMC_CONFIG4	0x0f031003
#define STNOR_GPMC_CONFIG5	0x000f1111
#define STNOR_GPMC_CONFIG6	0x0f030080

#define SIBNOR_GPMC_CONFIG1	0x1200
#define SIBNOR_GPMC_CONFIG2	0x001f1f00
#define SIBNOR_GPMC_CONFIG3	0x00080802
#define SIBNOR_GPMC_CONFIG4	0x1C091C09
#define SIBNOR_GPMC_CONFIG5	0x01131F1F
#define SIBNOR_GPMC_CONFIG6	0x1F0F03C2

#define SDPV2_MPDB_GPMC_CONFIG1	0x00611200
#define SDPV2_MPDB_GPMC_CONFIG2	0x001F1F01
#define SDPV2_MPDB_GPMC_CONFIG3	0x00080803
#define SDPV2_MPDB_GPMC_CONFIG4	0x1D091D09
#define SDPV2_MPDB_GPMC_CONFIG5	0x041D1F1F
#define SDPV2_MPDB_GPMC_CONFIG6	0x1D0904C4

#define MPDB_GPMC_CONFIG1	0x00011000
#define MPDB_GPMC_CONFIG2	0x001f1f01
#define MPDB_GPMC_CONFIG3	0x00080803
#define MPDB_GPMC_CONFIG4	0x1c0b1c0a
#define MPDB_GPMC_CONFIG5	0x041f1F1F
#define MPDB_GPMC_CONFIG6	0x1F0F04C4

#define P2_GPMC_CONFIG1	0x0
#define P2_GPMC_CONFIG2	0x0
#define P2_GPMC_CONFIG3	0x0
#define P2_GPMC_CONFIG4	0x0
#define P2_GPMC_CONFIG5	0x0
#define P2_GPMC_CONFIG6	0x0

#define ONENAND_GPMC_CONFIG1	0x00001200
#define ONENAND_GPMC_CONFIG2	0x000F0F01
#define ONENAND_GPMC_CONFIG3	0x00030301
#define ONENAND_GPMC_CONFIG4	0x0F040F04
#define ONENAND_GPMC_CONFIG5	0x010F1010
#define ONENAND_GPMC_CONFIG6	0x1F060000

#define NET_GPMC_CONFIG1	0x00001000
#define NET_GPMC_CONFIG2	0x001e1e01
#define NET_GPMC_CONFIG3	0x00080300
#define NET_GPMC_CONFIG4	0x1c091c09
#define NET_GPMC_CONFIG5	0x04181f1f
#define NET_GPMC_CONFIG6	0x00000FCF
#define NET_GPMC_CONFIG7	0x00000f6c

/* max number of GPMC Chip Selects */
#define GPMC_MAX_CS	8
/* max number of GPMC regs */
#define GPMC_MAX_REG	7

#define PISMO1_NOR	1
#define PISMO1_NAND	2
#define PISMO2_CS0	3
#define PISMO2_CS1	4
#define PISMO1_ONENAND	5
#define DBG_MPDB	6
#define PISMO2_NAND_CS0 7
#define PISMO2_NAND_CS1 8

/* make it readable for the gpmc_init */
#define PISMO1_NOR_BASE		FLASH_BASE
#define PISMO1_NAND_BASE	NAND_BASE
#define PISMO2_CS0_BASE		PISMO2_MAP1
#define PISMO1_ONEN_BASE	ONENAND_MAP
#define DBG_MPDB_BASE		DEBUG_BASE

#ifndef __ASSEMBLY__

/* Function prototypes */
void mem_init(void);

u32 is_mem_sdr(void);
u32 mem_ok(u32 cs);

u32 get_sdr_cs_size(u32);
u32 get_sdr_cs_offset(u32);

#endif	/* __ASSEMBLY__ */

#endif /* endif _MEM_H_ */
