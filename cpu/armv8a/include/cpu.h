/*
 * Copyright (C) 2020-2021 Tom Rix
 *
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License v2.1. See the file LICENSE in the top level
 * directory for more details.
 */

#ifndef CPU_H
#define CPU_H

#include <stdio.h>

#include "irq.h"
#include "sched.h"
#include "thread.h"
#include "cpu_conf.h"

void cpu_init(void);
void cpu_print_last_instruction(void);

void armv8a_init(void);
void armv8a_init_fpu(void);
void armv8a_init_isr_priorities(void);
void armv8a_init_misc(void);

#endif /* CPU_H */

