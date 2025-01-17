#
# CYANCORE LICENSE
# Copyrights (C) 2019, Cyancore Team
#
# File Name		: mk_helper.mk
# Description		: This file defines make helper utilities
# Primary Author	: Akash Kollipara [akashkollipara@gmail.com]
# Organisation		: Cyancore Core-Team
#

#*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.#
#-----------< Helpers >------------#
#*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.#

define add_define
	CFLAGS	+= -D$(1)=$($(1))
endef

define add_include
	INCLUDE	+= $(1)
endef

define add_cflag
	CFLAGS	+= $(1)
endef

define add_ldflag
	LD_FLAGS	+= $(1)
endef
