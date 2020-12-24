/*
 * Copyright (C) 2020-2021 Tom Rix
 *
 * This file is subject to the terms and conditions of the GNU Lesser General
 * Public License v2.1. See the file LICENSE in the top level directory for more
 * details.
 */

#include "cpu.h"
#include "periph_conf.h"
#include "periph/init.h"
#include "stdio_base.h"

void cpu_init(void)
{
    /* initialize the Armv8a core */
    armv8a_init();
    /* initialize stdio prior to periph_init() to allow use of DEBUG() there */
    stdio_init();
    /* trigger static peripheral initialization */
    periph_init();
}
