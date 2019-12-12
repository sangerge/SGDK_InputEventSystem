#include <genesis.h>
#include "inputEvent.h"

/* 
    index对应不同的按键
    0  - UP
    1  - DOWN
    2  - LEFT
    3  - RIGHT
    4  - A
    5  - B
    6  - C
    7  - X
    8  - Y
    9  - Z
    10 - START
    11 - MODE
*/
static u8 previousInputList[12];
static u8 currentInputList[12];
static u16 input;

static void everyButton(u16 BUTTON_, u8 index_);
static void everyEvent(u8 key);

void inputProcessUpdate()
{
    {
        input = JOY_readJoypad(JOY_1);

        everyButton(BUTTON_UP, 0);
        everyButton(BUTTON_DOWN, 1);
        everyButton(BUTTON_LEFT, 2);
        everyButton(BUTTON_RIGHT, 3);
        everyButton(BUTTON_A, 4);
        everyButton(BUTTON_B, 5);
        everyButton(BUTTON_C, 6);
        everyButton(BUTTON_X, 7);
        everyButton(BUTTON_Y, 8);
        everyButton(BUTTON_Z, 9);
        everyButton(BUTTON_START, 10);
        everyButton(BUTTON_MODE, 11);
    }

    {
        everyEvent(0);
        everyEvent(1);
        everyEvent(2);
        everyEvent(3);
        everyEvent(4);
        everyEvent(5);
        everyEvent(6);
        everyEvent(7);
        everyEvent(8);
        everyEvent(9);
        everyEvent(10);
        everyEvent(11);
    }
}

void regButtonEnterEvent(void (*cal)(u8 key))
{
    buttonEnter = cal;
}

void regButtonExitEvent(void (*cal)(u8 key))
{
    buttonExit = cal;
}

void regButtonStayEvent(void (*cal)(u8 key))
{
    buttonStay = cal;
}

static void everyButton(u16 BUTTON_, u8 index_)
{
    previousInputList[index_] = currentInputList[index_];

    if (input & BUTTON_)
    {
        currentInputList[index_] = 1;
    }
    else
    {
        currentInputList[index_] = 0;
    }
}

static void everyEvent(u8 key)
{
    if (currentInputList[key] != previousInputList[key])
    {
        if (currentInputList[key])
        {
            buttonEnter(key);
        }
        else
        {
            buttonExit(key);
        }
    }
    else if (previousInputList[key] && currentInputList[key])
    {
        buttonStay(key);
    }
}
