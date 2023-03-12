#include "lcd1602.h"
#include <stdint.h>

I2C_HandleTypeDef hi2c1;
#define LCD_1602_SLAVE_ADRESS (0x27 << 1)

void lcd_send_cmd(uint8_t cmd)
{
    uint8_t upper_half_byte;
    uint8_t lower_half_byte;
    uint8_t data[4];

    upper_half_byte = cmd & 0xf0;
    lower_half_byte = (cmd << 4) & 0xf0;

    data[0] = upper_half_byte | 0x0C;
    data[1] = upper_half_byte | 0x08;

    data[2] = lower_half_byte | 0x0C;
    data[3] = lower_half_byte | 0x08;

    HAL_I2C_Master_Transmit(&hi2c1, LCD_1602_SLAVE_ADRESS, data, 4, 100);
}

void lcd_send_data(uint8_t dat)
{
    
    uint8_t upper_half_byte;
    uint8_t lower_half_byte;
    uint8_t data[4];

    upper_half_byte = dat & 0xf0; 
    lower_half_byte = (dat << 4) & 0xf0;

    data[0] = upper_half_byte | 0x0D; 
    data[1] = upper_half_byte | 0x09; 

    data[2] = lower_half_byte | 0x0D; 
    data[3] = lower_half_byte | 0x09; 

    HAL_I2C_Master_Transmit(&hi2c1, LCD_1602_SLAVE_ADRESS, data, 4, 100);
}

void lcd_clear()
{
    lcd_send_cmd(0x80);
    for (int i = 0; i < 70; i++)
    {
        lcd_send_data(' ');
    }
}

void lcd_set_cursor(uint8_t row, uint8_t col)
{
    switch (row)
    {
		case 0:
			col |= 0x80;
			break;
		case 1:
			col |= 0xC0;
			break;
    }
    lcd_send_cmd(col);
}

void lcd_cursor_off()
{
    lcd_send_cmd(0xE);
}

void lcd_init()
{
    HAL_Delay(50); 
    lcd_send_cmd(0x30);
    HAL_Delay(5);
    lcd_send_cmd(0x30);
    HAL_Delay(1); 
    lcd_send_cmd(0x30);

    HAL_Delay(1);
    lcd_send_cmd(0x20);
    HAL_Delay(1);
    lcd_send_cmd(0x20);
    HAL_Delay(1);
    lcd_send_cmd(0x80); 
    HAL_Delay(1);
    lcd_send_cmd(0x00); 
    HAL_Delay(1);
    lcd_send_cmd(0x80); 
    HAL_Delay(1);
    lcd_send_cmd(0x00); 
    HAL_Delay(1);
    lcd_send_cmd(0x10);
    HAL_Delay(1);
    lcd_send_cmd(0x00); 
    HAL_Delay(1);
    lcd_send_cmd(0xC0);
}

void lcd_send_string(char *str)
{
    while (*str)
    {
        lcd_send_data(*str++);
    }
}

void MX_I2C1_Init(void)
{
    hi2c1.Instance = I2C1;
    hi2c1.Init.Timing = 0x0000020B;
    hi2c1.Init.OwnAddress1 = 0;
    hi2c1.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
    hi2c1.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
    hi2c1.Init.OwnAddress2 = 0;
    hi2c1.Init.OwnAddress2Masks = I2C_OA2_NOMASK;
    hi2c1.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
    hi2c1.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
    if (HAL_I2C_Init(&hi2c1) != HAL_OK)
    {
        Error_Handler();
    }

    if (HAL_I2CEx_ConfigAnalogFilter(&hi2c1, I2C_ANALOGFILTER_ENABLE) != HAL_OK)
    {
        Error_Handler();
    }

    if (HAL_I2CEx_ConfigDigitalFilter(&hi2c1, 0) != HAL_OK)
    {
        Error_Handler();
    }
}
