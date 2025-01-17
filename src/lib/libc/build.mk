#
# CYANCORE LICENSE
# Copyrights (C) 2019, Cyancore Team
#
# File Name		: build.mk
# Descrption		: This script accumulates all the sources of libc
#			  and build the library
# Primary Author	: Akash Kollipara [akashkollipara@gmail.com]
# Organisation		: Cyancore Core-Team
#

LIBC_PATH	:= $(GET_PATH)
LIB_OBJS	:=

LIB		:= libc.a
LIB_INCLUDE	+= $(LIBC_PATH)/include/
DEP_LIBS_ARG	+= -lc

DIR		:= $(LIBC_PATH)
include mk/lib.mk
