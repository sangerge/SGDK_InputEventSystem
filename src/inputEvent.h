#ifndef _INPUTEVENT_H_
#define _INPUTEVENT_H_

void (*buttonEnter)(u8 key);
void (*buttonStay)(u8 key);
void (*buttonExit)(u8 key);

//每一帧调用输入处理
void inputProcessUpdate();

//注册按键进入事件
void regButtonEnterEvent(void (*cal)(u8 key));

//注册按键按住事件
void regButtonStayEvent(void (*cal)(u8 key));

//注册按键离开事件
void regButtonExitEvent(void (*cal)(u8 key));

#endif