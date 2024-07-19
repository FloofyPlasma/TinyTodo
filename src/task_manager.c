#include "../include/task_manager.h"

#include <stdio.h>
#include <string.h>

void addTask(TaskList *TaskList, const char *Description) {
  if (TaskList->Count < 100) {
    Task *Task = &TaskList->Tasks[TaskList->Count++];
    Task->ID = TaskList->Count;
    strncpy(Task->Description, Description, sizeof(Task->Description) - 1);
    Task->Description[sizeof(Task->Description) - 1] = '\0';
    // Null termination, we don't want any pesky stack overflows :)
  }
}

void viewTasks(const TaskList *TaskList) {
  for (int i = 0; i < TaskList->Count; i++) {
    printf("Task ID: %d, Description: %s\n", TaskList->Tasks[i].ID,
           TaskList->Tasks[i].Description);
  }
}

void deleteTask(TaskList *TaskList, int id) {
  int i, found;
  found = 0;

  for (i = 0; i < TaskList->Count; i++) {
    if (TaskList->Tasks[i].ID == id) {
      found = 1;
      break;
    }
  }

  if (found) {
    for (int j = i; j < TaskList->Count - 1; j++) {
      TaskList->Tasks[j] = TaskList->Tasks[j + 1];
      TaskList->Tasks[j].ID = j + 1;
    }
    TaskList->Count--;
  }
}
