#pragma once
#include <stdio.h>
#include <stdint.h>

uint16_t SafeRead_16(FILE *fp);
uint32_t SafeRead_32(FILE *fp);
uint64_t SafeRead_64(FILE *fp);
