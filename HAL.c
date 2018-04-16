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

    //LED pins
    //Red
    GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_1);
    //Blue
    GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_2);
    //Green
    GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_3);

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

void set_led(int bit_code){
    ///bits: Red is LSB, Blue is <<1, Green is <<2
    if(bit_code>7){
        bit_code = 7;
    }
    if(bit_code < 0){
        bit_code = 0;
    }
    int red = bit_code & 1;
    int blue = bit_code & 2;
    int green = bit_code & 4;

    GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1, red);
    GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_2, blue);
    GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_3, green);
}
