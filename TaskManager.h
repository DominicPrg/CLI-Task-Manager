#ifndef TASK_MANAGER_H
#define TASK_MANAGER_H
#include "Task.h"
#include <iostream>
#include <vector>

class TaskManager : public Task {
    private:
        std::vector<Task> tasks;
    
    public:
        TaskManager();
        void addTask();
        void deleteTask();
        void displayTasks() const;
        void saveToFile(const std::string& fileName);
        void loadFromFile(const std::string& fileName);
};

#endif