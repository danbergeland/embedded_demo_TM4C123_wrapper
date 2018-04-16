/*
 * task_runner.c
 *
 *  Created on: Apr 15, 2018
 *      Author: DB
 */
#include <stdbool.h>
#include <stdint.h>

#include "driverlib/timer.h"
#include "driverlib/interrupt.h"
#include "driverlib/sysctl.h"

#include "inc/hw_memmap.h"
#include "inc/hw_ints.h"

#include "embedded_demo/hydro.h"
#include <HAL.h>

hydro_state global_hydro_state;
int led_code;

//Configure the timer to call back every 1 second
//Faster base rate on the timer will change execution speed
void handle_second_tick(void){
    //Reset the interrupt flag so it can be called again
    TimerIntClear(TIMER0_BASE, TIMER_TIMA_TIMEOUT);

    //Change the LED color, just for fun
    led_code += 1;
    if(led_code>7){
        led_code = 1;
    }
    set_led(led_code);

    //Increment the second counter on the state struct
    global_hydro_state.timer_seconds += 1;
    //Get inputs
    global_hydro_state = read_hydro_inputs(global_hydro_state);

    //Run the control function
    global_hydro_state = next_hydro_state(global_hydro_state);

    //Update Outputs
    set_hydro_outputs(global_hydro_state);
}


void init_task_runner(void){

    global_hydro_state = init_hydro();
    led_code = 1;
    set_led(led_code);

    //Enable the timer peripheral
    SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER0);

    //Enable interrupts
    IntMasterEnable();

    //Configure the timer to be periodic (resets when it hits 0)
    TimerConfigure(TIMER0_BASE,TIMER_CFG_PERIODIC);

    //Tell timer 0A to use the system control clock frequency
    //By loading the set time to be equal to the clock frequency, it will timeout every second
    //i.e. if the clock is 1kHz, a value of 1000 will accumulate every second.
    TimerLoadSet(TIMER0_BASE,TIMER_A,SysCtlClockGet());

    //Set interrupt for INT_TIMER0A to be on.
    //The interrupt vector is mapped in the "tm4c123gh6pm_startup_css.c" file
    IntEnable(INT_TIMER0A_TM4C123);
    //Enable the timer timeout interrupt
    TimerIntEnable(TIMER0_BASE,TIMER_TIMA_TIMEOUT);

    //Turn the timer on...
    TimerEnable(TIMER0_BASE, TIMER_A);
}
