#ifndef MENU_H
#define MENU_H

#include "main.h"

void SetState(uint8_t button, RTC_AlarmTypeDef *alarm, RTC_HandleTypeDef *hrtc);

void ShowMenu();

#endif /*MENU_H*/
