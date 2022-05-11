################################################################################
# Automatically-generated file. Do not edit!
################################################################################

include paths.mk

gen:
	mkdir -p ${BUILD_STAGE_1}/bsp ; mkdir -p ${BUILD_STAGE_2}

clean_bsp:
	rm -rf ${BUILD_STAGE_1}/bsp

bsp: gen
	cd ${BSP_DIR}; make all
	find ${BSP_DIR} -type f \( -name "*.a" -o -name "*.o" \) -exec mv {} ${BUILD_STAGE_1}/bsp/ \;

clean_app:
	rm -rf ${BUILD_DIR}
	cd ${APP_DIR_GEN}; make clean
	
clean: gen clean_app

all:
	cd ${APP_DIR_GEN}; make all
