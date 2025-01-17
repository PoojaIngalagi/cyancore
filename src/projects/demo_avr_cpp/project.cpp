/*
 * CYANCORE LICENSE
 * Copyrights (C) 2019, Cyancore Team
 *
 * File Name		: project.cpp
 * Description		: This file consists of project srouces in cpp
 * Primary Author	: Akash Kollipara [akashkollipara@gmail.com]
 * Organisation		: Cyancore Core-Team
 */

/* Include C headers incapsulated in 'extern "C"' */
extern "C"
{
	#include <stdio.h>
	#include <status.h>
	#include <insignia.h>
	#include <terravisor/platform.h>
	#include <terravisor/bootstrap.h>
	#include <driver.h>
	#include <hal/gpio.h>
}

#include "gpio.h"


class onBoardLed led;

/* Use EXPORT_C macro for calling cpp functoin in c file */
EXPORT_C(void plug())
{
	bootstrap();
	driver_setup("earlycon");
	printf("Reset Status: %d\n", platform_get_reset_syndrome());
	cyancore_insignia_lite();

	/* call the setup member of led object */
	led.setup();

	printf("Demo Program!\n");
	printf("< ! > Running Blinky ... [");
	return;
}

char progress[] = "-\\|/";

void delay(unsigned long d)
{
	unsigned long c;
	for(c = 0; c < d; c++)
		asm volatile("nop");
}

EXPORT_C(void play())
{
	static int i = 0;

	/* call the toggle member of led object */
	led.toggle();
	printf("%c]", progress[i++]);
	i = i > 3 ? 0 : i;
	delay(500000);
	printf("\b\b");
	return;
}
