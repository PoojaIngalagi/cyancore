#
# CYANCORE LICENSE
# Copyrights (C) 2019, Cyancore Team
#
# File Name		: lobj.mk
# Description		: This file build sources to generate objects
#			  used to build library
# Primary Author	: Akash Kollipara [akashkollipara@gmail.com]
# Organisation		: Cyancore Core-Team
#

#*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*#
#--------< Library Object Builder >---------#
#*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*#

C_OBJS		:= $(wildcard $(DIR)/*.c)
CPP_OBJS	:= $(wildcard $(DIR)/*.cpp)
S_OBJS		:= $(wildcard $(DIR)/*.S)

C_OBJS		:= $(addprefix $(OUT)/,$(C_OBJS:.c=.o))
CPP_OBJS	:= $(addprefix $(OUT)/,$(CPP_OBJS:.cpp=.o))
S_OBJS		:= $(addprefix $(OUT)/,$(S_OBJS:.S=.o))

LIB_OBJS	+= $(C_OBJS) $(CPP_OBJS) $(S_OBJS)

.SECONDEXPANSION:
$(CPP_OBJS): $(OUT)/%.o: %.cpp | $$(@D)/
	@echo "Elf: Compiling $(@F:.o=.cpp) ..."
	$(CCP) $(CFLAGS) -c $< -o $@

$(C_OBJS): $(OUT)/%.o: %.c | $$(@D)/
	@echo "Lib: Compiling $(@F:.o=.c) ..."
	$(CC) $(CFLAGS) -c $< -o $@

$(S_OBJS): $(OUT)/%.o: %.S | $$(@D)/
	@echo "Lib: Assembling $(@F:.o=.S) ..."
	$(CC) -E $(CFLAGS) -c $< -o $(@:.o=.pS)
	$(AS) $(ASFLAGS) $(@:.o=.pS) -o $@
	rm $(@:.o=.pS)
