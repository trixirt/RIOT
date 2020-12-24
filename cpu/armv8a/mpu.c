/*
 * Copyright (C) 2020-2021 Tom Rix
 *
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License v2.1. See the file LICENSE in the top level
 * directory for more details.
 */

#include "cpu.h"
#include "mpu.h"

int mpu_disable(void) {
}

int mpu_enable(void) {
    return -1;
}

bool mpu_enabled(void) {
    return false;
}

int mpu_configure(uint_fast8_t region, uintptr_t base, uint_fast32_t attr) {
    return -1;
}
