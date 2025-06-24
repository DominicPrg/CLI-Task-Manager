# 🗂️ CLI Task Manager

A simple command-line task manager written in C++ that allows users to add, view, search, delete, and save tasks to a `.json` file. This project is designed to demonstrate core skills in file handling, user input validation, and JSON serialization.

---

## 🚀 Features

- Add tasks with titles and descriptions
- Mark tasks as complete/incomplete
- Delete tasks by ID
- Save/load tasks to/from a `tasks.json` file
- Input validation for strings, integers, and characters

---

## 📦 Installation

### Prerequisites

- C++17 or higher
- [nlohmann/json](https://github.com/nlohmann/json) header (single-header file)
- A C++ compiler (e.g., g++, clang++, or Visual Studio)

### Steps

1. Clone the repository:
   ```bash
   git clone https://github.com/yourusername/cli-task-manager.git
   cd cli-task-manager
2. Make sure json.hpp is in your project directory.
3. Compile the program:
   ```bash
   g++ main.cpp task.cpp taskmanager.cpp storage.cpp -o taskmanager
4. Run it:
   ```bash
   ./taskmanager
If using Visual Studio, simply add all source files and json.hpp to your project.

### Usage
---- TASK MANAGER ----
1. Add Task
2. List Tasks
3. Delete Task
4. Save and Exit

### 📋 Known Limitations
- No task priority or tagging
- Not optimized for very large task lists
- No GUI (CLI only)
- No organized format for output of long string values

### 🔮 Potential Future Enhancements
- Implement task search feature (by keyword, status and ID)
- Add reminder support
- Implement priority sorting and filtering
- Export/import tasks in CSV format
- Unit tests for core modules
- Build a GUI or web interface in the future

### 👤 Author
**Dominic Parra**
Computer Science Student

[LinkedIn](https://www.linkedin.com/in/dominic-parra-a68249281/)
[Portfolio](https://www.linkedin.com/in/dominic-parra-a68249281/recent-activity/all/)
