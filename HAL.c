/*
 * poll_inputs.c
 *
 *  Created on: Apr 15, 2018
 *      Author: DB
 */

#include <HAL.h>
#include <stdbool.h>
#include <stdint.h>
//Be sure to add compiler AND linker to build properties
#include "driverlib/gpio.h"
#include "driverlib/timer.h"
#include "driverlib/interrupt.h"
#include "driverlib/sysctl.h"

#include "inc/hw_memmap.h"
#include "inc/hw_ints.h"

void init_HAL(void){

    //Low_water_sense input PF0
    GPIOPinTypeGPIOInput(GPIO_PORTF_BASE, GPIO_PIN_0);
    //High_water_sense input PE0
    GPIOPinTypeGPIOInput(GPIO_PORTE_BASE, GPIO_PIN_0);

    //Light output PA4
    GPIOPinTypeGPIOOutput(GPIO_PORTA_BASE, GPIO_PIN_4);
    //Pump output PA3
    GPIOPinTypeGPIOOutput(GPIO_PORTA_BASE, GPIO_PIN_3);
    //FAN output pin PA2
    GPIOPinTypeGPIOOutput(GPIO_PORTA_BASE, GPIO_PIN_2);


}

int get_high_water_sense(void){
    return (int)GPIOPinRead(GPIO_PORTE_BASE, GPIO_PIN_0);
}

int get_low_water_sense(void){
    return (int)GPIOPinRead(GPIO_PORTF_BASE, GPIO_PIN_0);
}

void set_fan(int enable){
    GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_2, (uint8_t)enable);
}

void set_pump(int enable){
    GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_3, (uint8_t)enable);
}

void set_light(int enable){
    GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_4, (uint8_t)enable);
}