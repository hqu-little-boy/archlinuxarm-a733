/*
 * T-Head/Allwinner RISC-V Vendor-Specific CSR Definitions
 * Compatibility header for standard RISC-V toolchains
 */

#ifndef _CSR_COMPAT_H_
#define _CSR_COMPAT_H_

/* T-Head Extended Machine Status Registers */
#define CSR_MXSTATUS        0x7c0
#define CSR_MEXSTATUS       0x7e1

/* T-Head Machine Hardware Control Register */
#define CSR_MHCR            0x7c1

/* T-Head Vector Table and Interrupt Registers */
#define CSR_MTVT            0x307
#define CSR_MNXTI           0x345
#define CSR_MINTSTATUS      0x346

#endif /* _CSR_COMPAT_H_ */
