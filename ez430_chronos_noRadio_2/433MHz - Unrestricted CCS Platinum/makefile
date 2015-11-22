################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

CG_TOOL_ROOT := E:/ti/ccsv6/tools/compiler/ti-cgt-msp430_4.4.2

ORDERED_OBJS += \
$(GEN_CMDS__FLAG) \
"./main.obj" \
"./logic/acceleration.obj" \
"./logic/battery.obj" \
"./logic/clock.obj" \
"./logic/date.obj" \
"./logic/menu.obj" \
"./logic/stopwatch.obj" \
"./logic/test.obj" \
"./logic/user.obj" \
"./driver/adc12.obj" \
"./driver/as.obj" \
"./driver/bmp_as.obj" \
"./driver/buzzer.obj" \
"./driver/display.obj" \
"./driver/pmm.obj" \
"./driver/ports.obj" \
"./driver/timer.obj" \
"../lnk_cc430f6137.cmd" \
-l"rts430x.lib" \
-l"libmath.a" \

-include ../makefile.init

RM := DEL /F
RMDIR := RMDIR /S/Q

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir_vars.mk
-include logic/subdir_vars.mk
-include driver/subdir_vars.mk
-include subdir_rules.mk
-include logic/subdir_rules.mk
-include driver/subdir_rules.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(S62_DEPS)),)
-include $(S62_DEPS)
endif
ifneq ($(strip $(C64_DEPS)),)
-include $(C64_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(S55_DEPS)),)
-include $(S55_DEPS)
endif
ifneq ($(strip $(C67_DEPS)),)
-include $(C67_DEPS)
endif
ifneq ($(strip $(C??_DEPS)),)
-include $(C??_DEPS)
endif
ifneq ($(strip $(CLA_DEPS)),)
-include $(CLA_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(S??_DEPS)),)
-include $(S??_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(C62_DEPS)),)
-include $(C62_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(K_DEPS)),)
-include $(K_DEPS)
endif
ifneq ($(strip $(C43_DEPS)),)
-include $(C43_DEPS)
endif
ifneq ($(strip $(S67_DEPS)),)
-include $(S67_DEPS)
endif
ifneq ($(strip $(SA_DEPS)),)
-include $(SA_DEPS)
endif
ifneq ($(strip $(S43_DEPS)),)
-include $(S43_DEPS)
endif
ifneq ($(strip $(OPT_DEPS)),)
-include $(OPT_DEPS)
endif
ifneq ($(strip $(S64_DEPS)),)
-include $(S64_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(C55_DEPS)),)
-include $(C55_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXE_OUTPUTS += \
SIT\ UP_433MHz.out \

EXE_OUTPUTS__QUOTED += \
"SIT UP_433MHz.out" \

BIN_OUTPUTS += \
SIT\ UP_433MHz.hex \

BIN_OUTPUTS__QUOTED += \
"SIT UP_433MHz.hex" \


# All Target
all: SIT\ UP_433MHz.out

# Tool invocations
SIT\ UP_433MHz.out: $(OBJS) $(CMD_SRCS) $(GEN_CMDS)
	@echo 'Building target: $@'
	@echo 'Invoking: MSP430 Linker'
	"E:/ti/ccsv6/tools/compiler/ti-cgt-msp430_4.4.2/bin/cl430" -vmspx --abi=coffabi -O4 --opt_for_speed=0 --use_hw_mpy=F5 -g --define=__CC430F6137__ --define=__CCE__ --define=ISM_LF --define=MRFI_CC430 --diag_warning=225 --display_error_number --diag_wrap=off --silicon_errata=CPU18 --silicon_errata=CPU21 --silicon_errata=CPU22 --silicon_errata=CPU23 --silicon_errata=CPU40 --call_assumptions=0 --gen_opt_info=2 --printf_support=minimal -z -m"SIT UP_433MHz.map" --heap_size=80 --stack_size=80 --cinit_hold_wdt=on -i"E:/ti/ccsv6/ccs_base/msp430/include" -i"E:/ti/ccsv6/tools/compiler/ti-cgt-msp430_4.4.2/lib" -i"E:/ti/ccsv6/tools/compiler/ti-cgt-msp430_4.4.2/include" -i"E:/ti/ccsv6/ccs_base/msp430/lib" -i"E:/ti/ccsv6/ccs_base/msp430/lib/5xx_6xx_FRxx" --reread_libs --warn_sections --display_error_number --diag_wrap=off --xml_link_info="SIT UP_433MHz_linkInfo.xml" --rom_model -o "SIT UP_433MHz.out" $(ORDERED_OBJS)
	@echo 'Finished building target: $@'
	@echo ' '
	@$(MAKE) --no-print-directory post-build

SIT\ UP_433MHz.hex: $(EXE_OUTPUTS)
	@echo 'Invoking: MSP430 Hex Utility'
	"E:/ti/ccsv6/tools/compiler/ti-cgt-msp430_4.4.2/bin/hex430" --memwidth=8 --romwidth=8 -o "SIT UP_433MHz.hex" $(EXE_OUTPUTS__QUOTED)
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(EXE_OUTPUTS__QUOTED)$(BIN_OUTPUTS__QUOTED)
	-$(RM) "main.pp" "logic\acceleration.pp" "logic\battery.pp" "logic\clock.pp" "logic\date.pp" "logic\menu.pp" "logic\stopwatch.pp" "logic\test.pp" "logic\user.pp" "driver\adc12.pp" "driver\as.pp" "driver\bmp_as.pp" "driver\buzzer.pp" "driver\display.pp" "driver\pmm.pp" "driver\ports.pp" "driver\timer.pp" 
	-$(RM) "main.obj" "logic\acceleration.obj" "logic\battery.obj" "logic\clock.obj" "logic\date.obj" "logic\menu.obj" "logic\stopwatch.obj" "logic\test.obj" "logic\user.obj" "driver\adc12.obj" "driver\as.obj" "driver\bmp_as.obj" "driver\buzzer.obj" "driver\display.obj" "driver\pmm.obj" "driver\ports.obj" "driver\timer.obj" 
	-@echo 'Finished clean'
	-@echo ' '

post-build:
	-@echo 'Create flash image: TI-TXT'
	-"E:/ti/ccsv6/tools/compiler/ti-cgt-msp430_4.4.2/bin/hex430.exe" --ti_txt "SIT UP_433MHz.out" -o "SIT UP_433MHz.txt" -order MS -romwidth 16
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY: post-build

-include ../makefile.targets

