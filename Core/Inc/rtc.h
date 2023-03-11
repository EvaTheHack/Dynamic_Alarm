#ifndef RTC_H
#define RTC_H

#include "main.h"

void GetTimeString(RTC_HandleTypeDef *hrtc, RTC_TimeTypeDef *time, RTC_DateTypeDef *date, char result[]);

#endif /*RTC_H*/
