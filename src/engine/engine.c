#include <engine.h>
#include <project.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

volatile uint32_t FWVersion __attribute__((section(".version"))) = VERSION;

char cyancore_logo[] =
"\n    | | | | |\n\r\
---           ---\n\r\
---           ---\n\r\
---   < / >   ---\n\r\
--- Cyancore® ---\n\r\
---           ---\n\r\
    | | | | |\n\n\r";

void engine()
{
	project_setup();
	while(true)
		project_loop();

	exit(EXIT_FAILURE);
}