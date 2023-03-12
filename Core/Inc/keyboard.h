#ifndef KEYBOARD_H
#define KEYBOARD_H

#include "main.h"
#include "stdint.h"

void RestoreState(void);

void GetClick(uint16_t GPIO_Pin, char button);

#endif /*KEYBOARD_H*/
