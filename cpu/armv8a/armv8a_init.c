/*
 * Copyright (C) 2020-2021 Tom Rix
 *
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License v2.1. See the file LICENSE in the top level
 * directory for more details.
 */

#include "cpu.h"

/**
 * Interrupt vector base address, defined by the linker
 */
extern const void *_isr_vectors;

void armv8a_init_isr_priorities(void)
{
}

void armv8a_init_misc(void)
{
}

void armv8a_init(void)
{
}

bool cpu_check_address(volatile const char *address)
{
	return false;
}
