#ifndef KEYBOARD_H
#define KEYBOARD_H

#include "main.h"
#include "stdint.h"

void RestoreState(void);

char GetClick(uint16_t GPIO_Pin);

#endif /*KEYBOARD_H*/