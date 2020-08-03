#include "SafeRead.h"

uint16_t SafeRead_16(FILE *fp)
{
	return	((uint16_t)fgetc(fp) << 0) |
			((uint16_t)fgetc(fp) << 8);
}

uint32_t SafeRead_32(FILE *fp)
{
	return	((uint32_t)fgetc(fp) << 0) |
			((uint32_t)fgetc(fp) << 8) |
			((uint32_t)fgetc(fp) << 16) |
			((uint32_t)fgetc(fp) << 24);
}

uint64_t SafeRead_64(FILE *fp)
{
	return	((uint64_t)fgetc(fp) << 0) |
			((uint64_t)fgetc(fp) << 8) |
			((uint64_t)fgetc(fp) << 16) |
			((uint64_t)fgetc(fp) << 24) |
			((uint64_t)fgetc(fp) << 32) |
			((uint64_t)fgetc(fp) << 40) |
			((uint64_t)fgetc(fp) << 48) |
			((uint64_t)fgetc(fp) << 56);
}
