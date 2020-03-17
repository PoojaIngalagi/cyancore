#include <status.h>
#include <arch.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <driver.h>
#include <driver/console.h>
#include <platform.h>

#if AUTOINIT==1
extern void platform_early_setup();
extern void platform_setup();
extern void platform_cpu_setup();
extern volatile uint32_t ArcVersion;
uint8_t boot_done;

char *ARC_LOGO = \
"< ! >=========================< ! >\n\
       ARC Framework V%04x\n\
< ! >=========================< ! >\n";

status_t autoinit()
{
	static uint8_t n_cpu_online = 0;
	static bool boot = false;
	
	arch_early_setup();
	arch_setup();

	if(!boot_done)
	{
		boot_done = 1;
		boot = true;
	}
	else
	{
		boot = false;
	}

	if(boot)
	{
		platform_early_setup();
		driver_setup("earlycon");
		printf(ARC_LOGO, ArcVersion);
		platform_setup();
		boot=false;
	}
	platform_cpu_setup();
	printf("< / > ARC: Boot complete!\n");

	n_cpu_online++;

	return success;
}
#endif