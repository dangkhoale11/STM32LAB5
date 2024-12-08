/*
 * software_timer.h
 *
 *  Created on: Dec 8, 2024
 *      Author: ADMIN
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

extern int timer_flag[10];
extern int timer_counter[10];
void setTimer(int index, int counter);
void timerRun();


#endif /* INC_SOFTWARE_TIMER_H_ */
