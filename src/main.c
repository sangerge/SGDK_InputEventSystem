#include <genesis.h>
#include <vdp.h>
#include "inputEvent.h"

//1P按键输入
InputEventClass p1Input;

//2P按键输入
InputEventClass p2Input;

//1P按键Enter事件
void P1ButtonEnter(u8 key);
//1P按键Stay事件
void P1ButtonStay(u8 key);
//1P按键Exit事件
void P1ButtonExit(u8 key);

//2P按键Enter事件
void P2ButtonEnter(u8 key);
//2P按键Stay事件
void P2ButtonStay(u8 key);
//2P按键Exit事件
void P2ButtonExit(u8 key);

int main()
{
    VDP_drawText("2 Player Button Test!", 0, 0);

    //初始化1P按键事件类
    initInputEventClass(&p1Input, JOY_1);
    //初始化2P按键事件类
    initInputEventClass(&p2Input, JOY_2);

    //注册1P按键进入事件
    regButtonEnterEvent(&p1Input, P1ButtonEnter);
    //注册2P按键进入事件
    regButtonEnterEvent(&p2Input, P2ButtonEnter);

    regButtonStayEvent(&p1Input, P1ButtonStay);
    regButtonStayEvent(&p2Input, P2ButtonStay);

    regButtonExitEvent(&p1Input, P1ButtonExit);
    regButtonExitEvent(&p2Input, P2ButtonExit);

    while (TRUE)
    {
        //每一帧更新1P按键事件
        inputProcessUpdate(&p1Input);
        //每一帧更新2P按键事件
        inputProcessUpdate(&p2Input);

        VDP_waitVSync();
    }
    return 0;
}

void P1ButtonEnter(u8 key)
{
    VDP_clearTextLine(3);
    VDP_drawText("P1 Button Enter.", 0, 1);
}

void P1ButtonStay(u8 key)
{
    VDP_drawText("P1 Button Stay.", 0, 2);
}

void P1ButtonExit(u8 key)
{
    VDP_clearTextLine(1);
    VDP_clearTextLine(2);
    VDP_drawText("P1 Button Exit.", 0, 3);
}

void P2ButtonEnter(u8 key)
{
    VDP_clearTextLine(7);
    VDP_drawText("P2 Button Enter.", 0, 5);
}

void P2ButtonStay(u8 key)
{
    VDP_drawText("P2 Button Stay.", 0, 6);
}

void P2ButtonExit(u8 key)
{
    VDP_clearTextLine(5);
    VDP_clearTextLine(6);
    VDP_drawText("P2 Button Exit.", 0, 7);
}