
# To compile bsp
make clean_bsp bsp

# To compile app
make clean_app all

# To run QEMU
qemu-system-aarch64 -M arm-generic-fdt-7series -machine linux=off -serial /dev/null -serial mon:stdio -display none -kernel build/src/stage2/img.elf -dtb /tools/Xilinx/SDK/2018.3/data/qemu/zynq/zc702/system.dtb -nographic -semihosting
doc: https://docs.xilinx.com/v/u/2020.1-English/ug1169-xilinx-qemu
