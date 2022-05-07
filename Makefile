################################################################################
# Automatically-generated file. Do not edit!
################################################################################

include paths.mk

clean_bsp:
	#make -f Uart_Example_Ps_bsp/Makefile clean -n
	cd ${BSP_DIR}; make clean

bsp: clean_bsp
	cd ${BSP_DIR}; make all
	#make -f Uart_Example_Ps_bsp/Makefile all -n

clean_app:
	rm -rf ${BUILD_DIR}
	cd ${APP_DIR_GEN}; make clean
	
clean: clean_bsp clean_app

all:
	mkdir -p ${BUILD_STAGE_1}; mkdir -p ${BUILD_STAGE_2}
	cd ${APP_DIR_GEN}; make all
