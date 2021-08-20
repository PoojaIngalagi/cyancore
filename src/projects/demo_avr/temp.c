#include <arch.h>
#include <mmio.h>
#include <stdio.h>

void print_arch_reg()
{
	arch_gpr_t *gpr;
	gpr = arch_gpr_readout();
	for(int i = 0; i < 32; i++)
		printf("r%d = 0x%x\n", i, MMIO8(((uint8_t*)gpr)+i));
}
