#ifndef KEYBOARD_H
#define KEYBOARD_H

#include "main.h"
#include "stdint.h"

void RestoreState(void);

void scan(state which);

#endif /*KEYBOARD_H*/
