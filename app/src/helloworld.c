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
#include "xtime_l.h"

int main()
{
    init_platform();

    xil_printf("Hello World\n");
    //usleep_A9((unsigned long)1000000);
    XTime Xtime_Global;
    XTime_GetTime(&Xtime_Global);
    //xil_printf("Time = %lld\n", Xtime_Global);
    //xil_printf("Time = %lld\n", Xtime_Global);
    printf("Time = %lld\n", Xtime_Global);
    //usleep_A9((unsigned long)1000000);
    sleep(3);
    XTime_GetTime(&Xtime_Global);
    printf("Time = %lld\n", Xtime_Global);
    cleanup_platform();
	
    return 0;
}
