/*
 * helloworld.c: simple test application
 *
 * This application configures UART 16550 to baud rate 9600.
 * PS7 UART (Zynq) is not initialized by this application, since
 * bootrom/bsp configures it to baud rate 115200
 *
 * ------------------------------------------------
 * | UART TYPE   BAUD RATE                        |
 * ------------------------------------------------
 *   uartns550   9600
 *   uartlite    Configurable only in HW design
 *   ps7_uart    115200 (configured by bootrom/bsp)
 */

#include <stdio.h>
#include "platform.h"
/* Include Files */
#include "xparameters.h"
#include "xil_printf.h"

int main()
{
    init_platform();

    xil_printf("Hello World\n");
    
    cleanup_platform();
	// Code to automatically close qemu at the end
	register int reg0 asm("r0");
	register int reg1 asm("r1");

	reg0 = 0x18;    // angel_SWIreason_ReportException
	reg1 = 0x20026; // ADP_Stopped_ApplicationExit

	asm("svc 0x00123456");  // make semihosting call
    return 0;
}
