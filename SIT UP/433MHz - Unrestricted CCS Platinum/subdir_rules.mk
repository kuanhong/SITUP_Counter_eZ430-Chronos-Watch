################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
main.obj: ../main.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP430 Compiler'
	"E:/ti/ccsv6/tools/compiler/ti-cgt-msp430_4.4.2/bin/cl430" -vmspx --abi=coffabi -O4 --opt_for_speed=0 --use_hw_mpy=F5 --include_path="E:/ti/ccsv6/ccs_base/msp430/include" --include_path="E:/ti/ccsv6/tools/compiler/ti-cgt-msp430_4.4.2/include" --include_path="C:/Users/darkdanito/Documents/GitHub/Land-of-Hope/SIT UP/include" --include_path="C:/Users/darkdanito/Documents/GitHub/Land-of-Hope/SIT UP/logic" --include_path="C:/Users/darkdanito/Documents/GitHub/Land-of-Hope/SIT UP/driver" -g --define=__CC430F6137__ --define=__CCE__ --define=ISM_LF --define=MRFI_CC430 --diag_warning=225 --display_error_number --diag_wrap=off --silicon_errata=CPU18 --silicon_errata=CPU21 --silicon_errata=CPU22 --silicon_errata=CPU23 --silicon_errata=CPU40 --call_assumptions=0 --gen_opt_info=2 --printf_support=minimal --preproc_with_compile --preproc_dependency="main.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


