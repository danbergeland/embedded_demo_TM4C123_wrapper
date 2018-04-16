/*
 * poll_inputs.h
 *
 *  Created on: Apr 15, 2018
 *      Author: DB
 */

#ifndef HAL_H_
#define HAL_H_

void init_HAL(void);
void init_timer(void);

int get_low_water_sense(void);
int get_high_water_sense(void);

void set_fan(int);
void set_pump(int);
void set_light(int);

void set_led(int);

#endif /* HAL_H_ */
