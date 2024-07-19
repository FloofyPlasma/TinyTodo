# To-Do List Application Design Document with ncurses

## Table of Contents
1. **Introduction**
2. **Objectives**
3. **Requirements**
4. **System Architecture**
5. **Data Structures**
6. **Functionality**
7. **User Interface**
8. **Error Handling**
9. **Testing**
10. **Future Enhancements**

## 1. Introduction
The To-Do List application is a command-line based program that allows users to manage their daily tasks using a terminal-based UI powered by `ncurses`.

## 2. Objectives
- Provide a simple and user-friendly command-line interface using `ncurses`.
- Allow users to add, view, and delete tasks.
- Ensure data persistence between sessions.

## 3. Requirements

### Functional Requirements
- The application should allow users to:
  - Add a new task.
  - View all tasks.
  - Delete a task by its identifier.

### Non-Functional Requirements
- The application should be written in C.
- The application should handle errors gracefully.
- The application should use file I/O for data persistence.
- The application should use the `ncurses` library for the terminal-based UI.

## 4. System Architecture
The application follows a simple client-server model where the client interacts with the command-line interface and the server handles data operations.

### Modules
1. **Main Module**: Handles user input and command processing.
2. **Task Manager Module**: Manages task operations (add, view, delete).
3. **File I/O Module**: Manages reading from and writing to the task file.
4. **UI Module**: Handles the terminal-based UI using `ncurses`.

## 5. Data Structures
### Task Structure
```c
typedef struct {
    int id;
    char description[256];
} Task;
```

### Task List Structure
```c
typedef struct {
    Task tasks[100];
    int count;
} TaskList;
```

## 6. Functionality

### Main Module
- `int main()`
  - Initialize `ncurses`.
  - Load tasks from file.
  - Enter main loop to handle user input and update UI.
  - Save tasks to file on exit.

### Task Manager Module
- `void addTask(TaskList *taskList, const char *description)`
- `void viewTasks(const TaskList *taskList)`
- `void deleteTask(TaskList *taskList, int id)`

### File I/O Module
- `void loadTasks(TaskList *taskList, const char *filename)`
- `void saveTasks(const TaskList *taskList, const char *filename)`

### UI Module
- `void initUI()`
- `void drawUI(const TaskList *taskList)`
- `void handleInput(TaskList *taskList)`

## 7. User Interface
The application will use `ncurses` to provide an interactive terminal-based interface.

### UI Implementation Details
- Use `ncurses` for drawing the interface and handling user input.
- Display task list in a readable format with task IDs.
- Provide input fields for adding and deleting tasks.

### Example UI Flow
1. **Main Screen:**
   - Display a list of tasks.
   - Options to add or delete tasks.
2. **Add Task Screen:**
   - Input field for task description.
3. **Delete Task Screen:**
   - Input field for task ID to delete.

## 8. Error Handling
- Validate user input for commands and provide appropriate error messages.
- Handle file read/write errors.
- Ensure no buffer overflows when handling task descriptions.

## 9. Testing
- Unit tests for each function.
- Integration tests to ensure modules work together.
- Manual testing for user interface.

## 10. Future Enhancements
- Implement a priority system for tasks.
- Add due dates for tasks.
- Implement a search function to find tasks by keywords.