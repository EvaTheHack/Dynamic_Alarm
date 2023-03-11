#include "stdint.h"
#include "keyboard.h"

//typedef enum
//{
//    FIRST,
//    SECOND,
//    THIRD,
//    FOURTH
//} state;
//
//#define r1_port GPIOC
//#define r1_pin GPIO_PIN_7
//
//#define r2_port GPIOA
//#define r2_pin GPIO_PIN_9
//
//#define r3_port GPIOA
//#define r3_pin GPIO_PIN_8
//
//#define r4_port GPIOB
//#define r4_pin GPIO_PIN_10
//
//#define c1_port GPIOB
//#define c1_pin GPIO_PIN_4
//
//#define c2_port GPIOB
//#define c2_pin GPIO_PIN_5
//
//#define c3_port GPIOB
//#define c3_pin GPIO_PIN_3
//
//#define c4_port GPIOA
//#define c4_pin GPIO_PIN_10
//
//char chosen = 'X';
//char message[6];
//
//void RestoreState(void)
//{
//    HAL_GPIO_WritePin(r1_port, r1_pin, 1);
//    HAL_GPIO_WritePin(r2_port, r2_pin, 1);
//    HAL_GPIO_WritePin(r3_port, r3_pin, 1);
//    HAL_GPIO_WritePin(r4_port, r4_pin, 1);
//}
//
//void scan(state which)
//{
//    switch (which)
//    {
//    case FIRST:
//        HAL_GPIO_WritePin(r1_port, r1_pin, 1);
//        HAL_GPIO_WritePin(r2_port, r2_pin, 0);
//        HAL_GPIO_WritePin(r3_port, r3_pin, 0);
//        HAL_GPIO_WritePin(r4_port, r4_pin, 0);
//        break;
//    case SECOND:
//        HAL_GPIO_WritePin(r1_port, r1_pin, 0);
//        HAL_GPIO_WritePin(r2_port, r2_pin, 1);
//        HAL_GPIO_WritePin(r3_port, r3_pin, 0);
//        HAL_GPIO_WritePin(r4_port, r4_pin, 0);
//        break;
//    case THIRD:
//        HAL_GPIO_WritePin(r1_port, r1_pin, 0);
//        HAL_GPIO_WritePin(r2_port, r2_pin, 0);
//        HAL_GPIO_WritePin(r3_port, r3_pin, 1);
//        HAL_GPIO_WritePin(r4_port, r4_pin, 0);
//        break;
//    case FOURTH:
//        HAL_GPIO_WritePin(r1_port, r1_pin, 0);
//        HAL_GPIO_WritePin(r2_port, r2_pin, 0);
//        HAL_GPIO_WritePin(r3_port, r3_pin, 0);
//        HAL_GPIO_WritePin(r4_port, r4_pin, 1);
//        break;
//    }
//}
//
//char GetClick(uint16_t GPIO_Pin)
//{
//    if (GPIO_Pin == c1_pin)
//    {
//        scan(FIRST);
//        if (HAL_GPIO_ReadPin(c1_port, c1_pin))
//        {
//            chosen = '1';
//        }
//        RestoreState();
//
//        scan(SECOND);
//        if (HAL_GPIO_ReadPin(c1_port, c1_pin))
//        {
//            chosen = '4';
//        }
//        RestoreState();
//
//        scan(THIRD);
//        if (HAL_GPIO_ReadPin(c1_port, c1_pin))
//        {
//            chosen = '7';
//        }
//        RestoreState();
//
//        scan(FOURTH);
//        if (HAL_GPIO_ReadPin(c1_port, c1_pin))
//            chosen = '*';
//        RestoreState();
//    }
//    else if (GPIO_Pin == c2_pin)
//    {
//        scan(FIRST);
//        if (HAL_GPIO_ReadPin(c2_port, c2_pin))
//            chosen = '2';
//        RestoreState();
//
//        scan(SECOND);
//        if (HAL_GPIO_ReadPin(c2_port, c2_pin))
//            chosen = '5';
//        RestoreState();
//
//        scan(THIRD);
//        if (HAL_GPIO_ReadPin(c2_port, c2_pin))
//            chosen = '8';
//        RestoreState();
//
//        scan(FOURTH);
//        if (HAL_GPIO_ReadPin(c2_port, c2_pin))
//            chosen = '0';
//        RestoreState();
//    }
//    else if (GPIO_Pin == c3_pin)
//    {
//        scan(FIRST);
//        if (HAL_GPIO_ReadPin(c3_port, c3_pin))
//            chosen = '3';
//        RestoreState();
//
//        scan(SECOND);
//        if (HAL_GPIO_ReadPin(c3_port, c3_pin))
//            chosen = '6';
//        RestoreState();
//
//        scan(THIRD);
//        if (HAL_GPIO_ReadPin(c3_port, c3_pin))
//            chosen = '9';
//        RestoreState();
//
//        scan(FOURTH);
//        if (HAL_GPIO_ReadPin(c3_port, c3_pin))
//            chosen = '#';
//        RestoreState();
//    }
//    else if (GPIO_Pin == c4_pin)
//    {
//        scan(FIRST);
//        if (HAL_GPIO_ReadPin(c4_port, c4_pin))
//            chosen = 'A';
//        RestoreState();
//
//        scan(SECOND);
//        if (HAL_GPIO_ReadPin(c4_port, c4_pin))
//            chosen = 'B';
//        RestoreState();
//
//        scan(THIRD);
//        if (HAL_GPIO_ReadPin(c4_port, c4_pin))
//            chosen = 'C';
//        RestoreState();
//
//        scan(FOURTH);
//        if (HAL_GPIO_ReadPin(c4_port, c4_pin))
//            chosen = 'D';
//        RestoreState();
//    }
//    return chosen;
//}
