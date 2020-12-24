/*
 * Copyright (C) 2020 Tom Rix
 *
 * This file is subject to the terms and conditions of the GNU Lesser General
 * Public License v2.1. See the file LICENSE in the top level directory for more
 * details.
 */

#ifndef IRQ_ARCH_H
#define IRQ_ARCH_H

#include <stdint.h>
#include "cpu_conf.h"

unsigned int irq_disable(void);
unsigned int irq_enable(void);
void irq_restore(unsigned int state);
int irq_is_in(void);

#endif /* IRQ_ARCH_H */

