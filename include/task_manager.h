// TODO: (FloofyPlasma): Should I move these structs to their own header so we
// aren't including them a million times?

#ifndef TASK_MANAGER_H
#define TASK_MANAGER_H

typedef struct {
  int id;
  char description[256];
} Task;

typedef struct {
  Task tasks[100];
  int count;
} TaskList;

void addTask(TaskList *TaskList, const char *TaskDescription);
void viewTasks(const TaskList *TaskList);
void deleteTask(TaskList *TaskList, int id);

#endif // TASK_MANAGER_H
