// TODO: (FloofyPlasma): Should I move these structs to their own header so we
// aren't including them a million times?

#ifndef TASK_MANAGER_H
#define TASK_MANAGER_H

#define MAX_INPUT_LENGTH 256

typedef struct {
  int ID;
  char Description[256];
} Task;

typedef struct {
  Task Tasks[100];
  int Count;
} TaskList;

void addTask(TaskList *TaskList, const char *TaskDescription);
void viewTasks(const TaskList *TaskList);
void deleteTask(TaskList *TaskList, int id);

#endif // TASK_MANAGER_H
