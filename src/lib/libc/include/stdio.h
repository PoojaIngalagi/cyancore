/*
 * CYANCORE LICENSE
 * Copyrights (C) 2019, Cyancore Team
 *
 * File Name		: stdio.h
 * Description		: This file contains sources of libc-stdio
 *			  inspired from gnu-libc
 * Primary Author	: Akash Kollipara [akashkollipara@gmail.com]
 * Organisation		: Cyancore Core-Team
 */

#pragma once
#define _STDIO_H_

#include <stddef.h>
#include <stdint.h>

#define EOF		-1

int printf(const char *fmt, ...);
int snprintf(char *s, size_t n, const char *fmt, ...);
int putch(int c);
int puts(const char *s);

char getch();
char getchar();

#ifdef _STDARG_H_
int vprintf(const char *fmt, va_list args);
#endif
