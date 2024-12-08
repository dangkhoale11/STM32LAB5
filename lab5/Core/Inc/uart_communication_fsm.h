/*
 * uart_communication_fsm.h
 *
 *  Created on: Dec 8, 2024
 *      Author: ADMIN
 */

#ifndef INC_UART_COMMUNICATION_FSM_H_
#define INC_UART_COMMUNICATION_FSM_H_

#include "stdio.h"
#include "command_parser_fsm.h"
#include "software_timer.h"

extern uint32_t ADC_value;
extern char str[30];
extern uint8_t countdown_state;
extern uint32_t previous_tick;

void uart_communication_fsm_run();
void send_uart_message(char *msg);

#endif /* INC_UART_COMMUNICATION_FSM_H_ */
