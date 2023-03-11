#include "menu.h"
#include "lcd1602.h"
#include "rtc.h"
#include <string.h>

uint8_t current_state = 0;
uint8_t seconds = 0;
uint8_t current_seconds = 0;

char datetime[8];
char alarmtime[16];

uint8_t colomn = 0;

uint8_t ten_hours = 0;
uint8_t hours = 0;

uint8_t ten_minutes = 0;
uint8_t minutes = 0;

RTC_TimeTypeDef time;
RTC_DateTypeDef date;

void SetState(uint8_t button, RTC_AlarmTypeDef *alarm, RTC_HandleTypeDef *hrtc)
{
	if (current_state == 0)
	{
		if (button == '#')
		{
			lcd_init();
			lcd_clear();
			current_state = 1;
		}
	}
	else
	{
		if (button == '*')
		{
			lcd_init();
			lcd_clear();
			current_state = 0;
		}
		if (button == 'A')
		{
			colomn = ((colomn - 1) + 5) % 5;
			if (colomn == 2)
			{
				colomn--;
			}
			lcd_set_cursor(1, colomn);
		}
		if (button == 'B')
		{
			colomn = ((colomn + 1) + 5) % 5;
			if (colomn == 2)
			{
				colomn++;
			}
			lcd_set_cursor(1, colomn);
		}
		if (button == 'C')
		{
			alarm->AlarmTime.Hours = ten_hours * 10 + hours;
			alarm->AlarmTime.Minutes = ten_minutes * 10 + minutes;
			HAL_RTC_SetAlarm(hrtc, alarm, RTC_FORMAT_BIN);

			current_state = 0;
		}
		if (button != 'A' && button != 'B' && button != 'C' && button != 'D' && button != '*' && button != '#')
		{
			switch (colomn)
			{
				case 0:
					ten_hours = button - 48;
					break;
				case 1:
					hours = button - 48;
					break;
				case 3:
					ten_minutes = button - 48;
					break;
				case 4:
					minutes = button - 48;
					break;

				default:
					break;
			}
		}
	}
}

void ShowMenu(RTC_HandleTypeDef *hrtc)
{
	if (current_state == 0)
	{
		GetTimeString(hrtc, &time, &date, datetime);
		current_seconds = time.Seconds;
		if (current_seconds != seconds)
		{
			lcd_init();
			lcd_clear();
			lcd_set_cursor(0, 0);
			lcd_send_string(datetime);
			lcd_set_cursor(1, 0);
			lcd_send_string("# set alarm");
			lcd_cursor_off();
			HAL_Delay(500);
		}
		seconds = current_seconds;
	}
	else
	{
		if(ten_hours * 10 + hours > 23)
		{
			ten_hours = 0;
			hours = 0;
		}
		if(ten_minutes * 10 + minutes > 59)
		{
			ten_minutes = 0;
			minutes = 0;
		}
		sprintf(alarmtime, "%01d%01d:%01d%01d A< B> C=", ten_hours, hours, ten_minutes, minutes);
		lcd_init();
		lcd_set_cursor(0, 0);
		lcd_send_string("* for return");
		lcd_set_cursor(1, 0);
		lcd_send_string(alarmtime);
		lcd_set_cursor(1, colomn);
		HAL_Delay(500);
	}
}
