// TODO: (FloofyPlasma): This UI stuff should init ncurses and destroy it on its
// own, the main function shouldn't need to do it. But for now, the main
// function handles it.

#ifndef UI_H
#define UI_H

#include "task_manager.h"

void initUI();
void drawUI(const TaskList *TaskList);
void handleInput(TaskList *TaskList);

#endif // UI_H
