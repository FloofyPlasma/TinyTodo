#include "../include/file_io.h"
#include <stdio.h>

void loadTasks(TaskList *TaskList, const char *FileName) {
  FILE *File = fopen(FileName, "r");

  if (File) {
    while (fscanf(File, "%d %[^\n]", &TaskList->Tasks[TaskList->Count].ID,
                  TaskList->Tasks[TaskList->Count].Description) != EOF) {
      TaskList->Count++;
    }
    fclose(File);
  }
}

void saveTasks(TaskList *TaskList, const char *FileName) {
  FILE *File = fopen(FileName, "w");

  if (File) {
    for (int i = 0; i < TaskList->Count; i++) {
      fprintf(File, "%d %s\n", TaskList->Tasks[i].ID,
              TaskList->Tasks[i].Description);
    }
    fclose(File);
  }
}
