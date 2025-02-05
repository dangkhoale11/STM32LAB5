/*
 * command_parser_fsm.c
 *
 *  Created on: Dec 8, 2024
 *      Author: ADMIN
 */


#include "command_parser_fsm.h"

CPS state;
uint8_t cmd_idx = 0;
uint8_t cmd_rst = 0;
uint8_t cmd_ok = 0;
uint8_t tmp =0;
void command_parser_fsm_run() {
    switch (state) {
    case IDLE:
        if (buffer[cmd_idx] == '!') {
             // Lưu vị trí của '!'
        	tmp = cmd_idx;
            cmd_idx++;
            state = RECEIVING;

        }
        break;

    case RECEIVING:
        if (buffer[cmd_idx] == '#') {
            // Tính độ dài lệnh từ '!' đến '#'
            int len = cmd_idx - tmp + 1;
            if (len >= 4 && len <= 6) {
                char temp_command[6]; // Lệnh tối đa "!RST#"
                strncpy(temp_command, (char*)&buffer[tmp], len);
                temp_command[len] = '\0';

                if (strncmp(temp_command, "!RST#", 5) == 0) {
                    cmd_rst = 1;  // Lệnh reset
                } else if (strncmp(temp_command, "!OK#", 4) == 0) {
                    cmd_ok = 1;   // Lệnh OK
                }
            }
            state = DONE;
        }
        else cmd_idx++;
        break;

    case DONE:
        cmd_idx = 0;
        index_buffer = 0;
        state = IDLE;
        break;

    default:
        break;
    }
}
