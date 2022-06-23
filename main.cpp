/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"
#include "DS1820.h"

#define WAIT_TIME_MS 1000 
DS1820  ds1820(PC_6); 

int main()
{
    printf("This is the bare metal blinky example running on Mbed OS %d.%d.%d.\n", MBED_MAJOR_VERSION, MBED_MINOR_VERSION, MBED_PATCH_VERSION);

  if(ds1820.begin()) {
        while(1) {
            ds1820.startConversion();     // start temperature conversion
            thread_sleep_for(WAIT_TIME_MS);
            printf("temp = %3.1f\r\n", ds1820.read());     // read temperature
        }
    } else
       printf("No DS1820 sensor found!\r\n");
}
