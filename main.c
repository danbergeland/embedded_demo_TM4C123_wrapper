

/**
 * main.c
 *
 * This is an application that will run a hydroponic system
 * It measures water levels to turn a pump on and off
 * It sets a light on and off based on a timer
 *
 */

#include <task_runner.h>
#include <HAL.h>

int main(void)
{
    init_HAL();
    set_led(3);
    init_task_runner();
    while(1){}
}
