#include "../include/ui.h"

#include <ncurses.h>

void initUI() {
  initscr();
  raw();
  keypad(stdscr, TRUE);
  noecho();
  curs_set(0);
}

void drawUI(const TaskList *TaskList) {
  clear();

  mvprintw(0, 0, "Usage:");
  mvprintw(1, 0, "Press a to add a task");
  mvprintw(2, 0, "Press d to delete a task");
  mvprintw(3, 0, "Press q to quit");

  for (int i = 0; i < TaskList->Count; i++) {
    mvprintw(5 + i, 0, "Task ID: %d, Description: %s", TaskList->Tasks[i].ID,
             TaskList->Tasks[i].Description);
  }

  refresh();
}

void handleInput(TaskList *TaskList) {
  int character;
  char input[MAX_INPUT_LENGTH];
  int taskId;

  taskId = 0;

  while ((character = getch()) != 'q') {
    switch (character) {
    case 'a': // Add Tasks
      clear();
      mvprintw(0, 0, "Enter task description: ");
      echo();
      if (getstr(input) == OK) {
        noecho();
        addTask(TaskList, input);
        drawUI(TaskList);
      } else {
        mvprintw(1, 0, "Failed to read input.");
        refresh();
      }

      break;
    case 'd': // Delete Tasks
      clear();
      mvprintw(0, 0, "Enter task ID to delete: ");
      echo();
      refresh();
      if (scanw("%d", &taskId) == ERR) {
        mvprintw(1, 0, "Failed to read input.");
        refresh();

      } else {
        noecho();
        deleteTask(TaskList, taskId);
        drawUI(TaskList);
      }

      break;
    default:
      break;
    }
  }
}
