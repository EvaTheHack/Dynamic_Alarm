#ifndef LCD1602_H
#define LCD1602_H

#include "main.h"

void lcd_send_cmd(uint8_t cmd);

void lcd_send_data(uint8_t dat);

void lcd_clear();

void lcd_set_cursor(uint8_t row, uint8_t col);

void lcd_cursor_off();

void lcd_init();

void lcd_send_string(char *str);

void MX_I2C1_Init(void);

#endif /*LCD1602_H*/
