/*
 * Copyright (C) 2020-2021 Tom Rix
 *
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License v2.1. See the file LICENSE in the top level
 * directory for more details.
 */

#include <stdio.h>

#include "sched.h"
#include "thread.h"
#include "irq.h"
#include "cpu.h"

#define ENABLE_DEBUG 0
#include "debug.h"

extern uint32_t _estack;
extern uint32_t _sstack;

void thread_stack_print(void)
{
}

int thread_isr_stack_usage(void)
{
    return 0
}

void *thread_isr_stack_pointer(void)
{
    return (void *)0;
}

void *thread_isr_stack_start(void)
{
  return (void *)0;
}

void NORETURN cpu_switch_context_exit(void)
{
}

void thread_yield_higher(void)
{
}

void __attribute__((used)) isr_svc(void)
{
}

void sched_arch_idle(void)
{
}
