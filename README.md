# To compile app
make clean bsp all

# To run QEMU
qemu-system-aarch64 -M arm-generic-fdt-7series -machine linux=off -serial /dev/null -serial mon:stdio -display none -kernel build/src/stage2/img.elf -dtb /tools/Xilinx/SDK/2018.3/data/qemu/zynq/zc702/system.dtb -nographic -semihosting
doc: https://docs.xilinx.com/v/u/2020.1-English/ug1169-xilinx-qemu
Redirection to file
qemu-system-aarch64 -M arm-generic-fdt-7series -machine linux=off -serial /dev/null -serial file:serial.log -display none -kernel build/src/stage2/img.elf -dtb /tools/Xilinx/SDK/2018.3/data/qemu/zynq/zc702/system.dtb -semihosting

# To run QEMU and debug
Terminal 1
qemu-system-arm -M xilinx-zynq-a9 -cpu cortex-a9 -serial /dev/null -serial mon:stdio -display none -device loader,file=build/src/stage2/img.elf,cpu-num=0 -dtb /tools/Xilinx/SDK/2018.3/data/qemu/zynq/zc702/system.dtb -nographic -semihosting -s -S

Terminal 2
/tools/Xilinx/SDK/2018.3/gnu/aarch64/lin/aarch64-linux/bin/aarch64-linux-gnu-gdb -q build/src/stage2/img.elf --command=test.gdb
test.gdb contient une liste de commande a executer au demarrage de gdb
For a graphical view: ddd --debugger /tools/Xilinx/SDK/2018.3/gnu/aarch64/lin/aarch64-linux/bin/aarch64-linux-gnu-gdb build/src/stage2/img.elf --command=test.gdb



