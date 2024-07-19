// TODO: (FloofyPlasma): Figure out if we wanna store file handles or something
// in a struct

#ifndef FILE_IO_H
#define FILE_IO_H

#include "task_manager.h"

// TODO: (FloofyPlasma): Should we include the FileName in the TaskList struct?
// Only issue I see is if the file path is quite long...
void loadTasks(TaskList *TaskList, const char *FileName);
void saveTasks(TaskList *TaskList, const char *FileName);

#endif // FILE_IO_H
