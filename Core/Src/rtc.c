#include <stdio.h>
#include <string.h>
#include "main.h"
#include "rtc.h"

void GetTimeString(RTC_HandleTypeDef *hrtc, RTC_TimeTypeDef *time, RTC_DateTypeDef *date, char result[])
{
	HAL_RTC_GetTime(hrtc, time, RTC_FORMAT_BIN);
	HAL_RTC_GetDate(hrtc, date, RTC_FORMAT_BIN);
    sprintf(result, "%02d:%02d:%02d", time->Hours, time->Minutes, time->Seconds);
}
