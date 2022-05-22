//Example of triggering interrupts by simulating software generated interrupt.

#include <stdio.h>
#include <stdlib.h>
#include "xil_io.h"
#include "xil_exception.h"
#include "xil_cache.h"
#include "xil_types.h"
#include "xscugic.h"

#define INTC_DEVICE_ID		XPAR_SCUGIC_0_DEVICE_ID
#define INTC_DEVICE_INT_ID	0x0E
#define INTC_DEVICE_INT_ID_BIS	0x0F

int ScuGicExample(u16 DeviceId, XScuGic InterruptController, XScuGic_Config *GicConfig);
int SetUpInterruptSystem(XScuGic *XScuGicInstancePtr);
void DeviceDriverHandler(void *CallbackRef);
void DeviceDriverHandlerBis(void *CallbackRef);