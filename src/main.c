#include <genesis.h>
#include <vdp.h>
#include "inputEvent.h"

void buttonEnterCallback(u8 key);
void buttonStayCallback(u8 key);
void buttonExitCallback(u8 key);

void drawMessage(u8 key, u8 key_, const char *str_, u16 y_);

int main()
{
    regButtonEnterEvent(buttonEnterCallback);
    regButtonExitEvent(buttonExitCallback);
    regButtonStayEvent(buttonStayCallback);

    while (TRUE)
    {
        inputProcessUpdate();
        VDP_waitVSync();
    }
    return 0;
}

void buttonEnterCallback(u8 key)
{
    drawMessage(key, 0, "Enter:up", 0);
    drawMessage(key, 1, "Enter:down", 0);
    drawMessage(key, 2, "Enter:left", 0);
    drawMessage(key, 3, "Enter:right", 0);
    drawMessage(key, 4, "Enter:a", 0);
    drawMessage(key, 5, "Enter:b", 0);
    drawMessage(key, 6, "Enter:c", 0);
    drawMessage(key, 7, "Enter:x", 0);
    drawMessage(key, 8, "Enter:y", 0);
    drawMessage(key, 9, "Enter:z", 0);
    drawMessage(key, 10, "Enter:start", 0);
    drawMessage(key, 11, "Enter:mode", 0);

    VDP_clearTextLine(2);
}

void buttonStayCallback(u8 key)
{
    drawMessage(key, 0, "Stay:up", 1);
    drawMessage(key, 1, "Stay:down", 1);
    drawMessage(key, 2, "Stay:left", 1);
    drawMessage(key, 3, "Stay:right", 1);
    drawMessage(key, 4, "Stay:a", 1);
    drawMessage(key, 5, "Stay:b", 1);
    drawMessage(key, 6, "Stay:c", 1);
    drawMessage(key, 7, "Stay:x", 1);
    drawMessage(key, 8, "Stay:y", 1);
    drawMessage(key, 9, "Stay:z", 1);
    drawMessage(key, 10, "Stay:start", 1);
    drawMessage(key, 11, "Stay:mode", 1);

    VDP_clearTextLine(2);
}

void buttonExitCallback(u8 key)
{
    drawMessage(key, 0, "Exit:up", 2);
    drawMessage(key, 1, "Exit:down", 2);
    drawMessage(key, 2, "Exit:left", 2);
    drawMessage(key, 3, "Exit:right", 2);
    drawMessage(key, 4, "Exit:a", 2);
    drawMessage(key, 5, "Exit:b", 2);
    drawMessage(key, 6, "Exit:c", 2);
    drawMessage(key, 7, "Exit:x", 2);
    drawMessage(key, 8, "Exit:y", 2);
    drawMessage(key, 9, "Exit:z", 2);
    drawMessage(key, 10, "Exit:start", 2);
    drawMessage(key, 11, "Exit:mode", 2);

    VDP_clearTextLine(0);
    VDP_clearTextLine(1);
}

void drawMessage(u8 key, u8 key_, const char *str_, u16 y_)
{
    if (key == key_)
    {
        VDP_drawText(str_, 0, y_);
    }
}