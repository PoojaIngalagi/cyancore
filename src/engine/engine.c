/*
 * CYANCORE LICENSE
 * Copyrights (C) 2019, Cyancore Team
 *
 * File Name		: engine.c
 * Description		: This file contains sources of cyancore engine
 *			  It also defines cyancore insignia
 * Primary Author	: Akash Kollipara [akashkollipara@gmail.com]
 * Organisation		: Cyancore Core-Team
 */

#include <engine.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>
#include <compiler_macros.h>

volatile uint32_t FWVersion __attribute__((section(".version"))) = VERSION;

const char cyancore_ascii_insignia[] =
"\n\r    | | | | |\n\r\
---           ---\n\r\
---           ---\n\r\
---   < / >   ---\n\r\
--- Cyancore® ---\n\r\
---           ---\n\r\
    | | | | |\n\n\r";

const char cyancore_ascii_insignia_lite[] = "Cyancore® < / >";

_WEAK void plug()
{
	asm volatile("");
	return;
}

_WEAK void play()
{
	asm volatile("");
	return;
}

void engine()
{
	plug();
player:
	play();
	goto player;
}
