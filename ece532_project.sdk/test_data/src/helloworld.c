/******************************************************************************
*
* Copyright (C) 2009 - 2014 Xilinx, Inc.  All rights reserved.
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in
* all copies or substantial portions of the Software.
*
* Use of the Software is limited solely to applications:
* (a) running on a Xilinx device, or
* (b) that interact with a Xilinx device through a bus or interconnect.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
* XILINX  BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
* WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF
* OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
*
* Except as contained in this notice, the name of the Xilinx shall not be used
* in advertising or otherwise to promote the sale, use or other dealings in
* this Software without prior written authorization from Xilinx.
*
******************************************************************************/

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
#include "xil_printf.h"

volatile unsigned int * LED_CONTROL = (unsigned int *)0x40010000;
volatile unsigned int * SW_CONTROL 	= (unsigned int *)0x40000000;
volatile unsigned int * FTPS_VALID 	= (unsigned int *)0x40020000;
volatile unsigned int * FTPS_X 		= (unsigned int *)0x40030000;
volatile unsigned int * FTPS_Y 		= (unsigned int *)0x40040000;
int main()
{
    init_platform();
    int total_control;
    int ftps_valid;
    int ftps_x;
    int ftps_y;
    print("Hello World\n\r");
    while (1) {
    	*LED_CONTROL = *SW_CONTROL;
    	total_control = *SW_CONTROL;
    	if(total_control){
    		ftps_valid = (*FTPS_VALID)&0x1;
    		if (ftps_valid) {
    			ftps_x = ((*FTPS_X)&0b111111111)>>3;
    			ftps_y = ((*FTPS_Y)&0xff)>>3;
    			printf("X=%d ; Y=%d \n",ftps_x,ftps_y );
    			while (ftps_valid) {
    				ftps_valid = (*FTPS_VALID)&0x1;
    			}
    		}
    	}
    }
    cleanup_platform();
    return 0;
}