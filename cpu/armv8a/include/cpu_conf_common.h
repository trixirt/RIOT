/*
 * Copyright (C) 2020-2021 Tom Rix
 *
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License v2.1. See the file LICENSE in the top level
 * directory for more details.
 */

#ifndef CPU_CONF_COMMON_H
#define CPU_CONF_COMMON_H

/**
 * @brief    Configuration of default stack sizes
 *
 * If needed, you can overwrite these values the the `cpu_conf.h` file of the
 * specific CPU implementation.
 *
 * @{
 */
#ifndef THREAD_EXTRA_STACKSIZE_PRINTF
#define THREAD_EXTRA_STACKSIZE_PRINTF   (512)
#endif
#ifndef THREAD_STACKSIZE_DEFAULT
#define THREAD_STACKSIZE_DEFAULT        (1024)
#endif
#ifndef THREAD_STACKSIZE_IDLE
#define THREAD_STACKSIZE_IDLE           (256)
#endif
/** @} */

/**
 * @brief   Stack size used for the exception (ISR) stack
 * @{
 */
#ifndef ISR_STACKSIZE
#define ISR_STACKSIZE                   (512U)
#endif
/** @} */

/**
 * @brief   Attribute for memory sections required by SRAM PUF
 */
#define PUF_SRAM_ATTRIBUTES __attribute__((used, section(".puf")))

#if CPU_HAS_BACKUP_RAM
/**
 * @brief   Memory marked with this attribute is retained during deep sleep
 *          and initialized with 0 on cold boot.
 */
#define BACKUP_RAM      __attribute__((section(".backup.bss")))

/**
 * @brief   Memory marked with this attribute is retained during deep sleep
 *          and initialized with user provided data on cold boot.
 */
#define BACKUP_RAM_DATA __attribute__((section(".backup.data")))
#endif /* CPU_HAS_BACKUP_RAM */

#endif /* CPU_CONF_COMMON_H */
/** @} */
