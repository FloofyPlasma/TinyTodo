#include "../include/file_io.h" // FIXME: (FloofyPlasma): WHY! WHY THE HELL DOES CLANGD SAY THIS FILE DOESNT EXIST WITHOUT THE RELATIVE PATH!?
#include "../include/task_manager.h"
#include "../include/ui.h"
#include <ncurses.h>

int main() {
  TaskList TaskList;
  TaskList.Count = 0;

  initUI();

  loadTasks(&TaskList, "tasks.txt");

  drawUI(&TaskList); // Initial draw call so it displays stuff and isn't blank.

  handleInput(&TaskList);

  saveTasks(&TaskList, "tasks.txt");

  refresh();
  endwin();

  return 0;
}
