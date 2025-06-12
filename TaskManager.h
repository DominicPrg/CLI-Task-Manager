#ifndef TASK_MANAGER_H
#define TASK_MANAGER_H
#include "Task.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <cctype>
#include <stdexcept>

const int STARTING_ID = 1;

class TaskManager : public Task {
private:
     std::vector<Task> tasks;
     int nextId;
     bool checkForInvalidID(int id);

public:
     TaskManager();
     void printCommands() const;
     void addTask();   
     void displayTasks() const;
     //void saveToFile(const std::string& fileName) const;
     //void loadFromFile(const std::string& fileName);
     bool completeTask(int id);
     bool deleteTask(int id);
     class DeleteNonexistTaskError{};
};

TaskManager::TaskManager() {
     nextId = STARTING_ID;
}

void TaskManager::printCommands() const {
     std::cout << "List of task manager commands: " << std::endl;
     std::cout << " add: Add a new task to the task manager." << std::endl;
     std::cout << " list: List all the current tasks in the task manager." << std::endl;
     std::cout << " complete: Toggle a specific task in the task manager as completed." << std::endl;
     std::cout << " delete: Delete a specific task in the task manager." << std::endl << std::endl;
}

void TaskManager::addTask() {
     std::string taskTitle;
     std::string taskDescription;
     std::string taskDeadline;
     std::string taskCompletionString;
     bool taskCompletionBool = false;

     std::cout << "Enter task title: ";
     std::getline(std::cin, taskTitle);

     std::cout << "Enter task description: ";
     std::getline(std::cin, taskDescription);

     std::cout << "Enter task deadline: ";
     std::getline(std::cin, taskDeadline);

     std::cout << "Enter task status (done/pending): ";
     std::cin >> taskCompletionString;

     if (taskCompletionString == "done") {
          taskCompletionBool = true;
     }

     std::cout << std::endl;
     std::cin.ignore();

     Task newTask(nextId, taskTitle, taskDescription, taskDeadline, taskCompletionBool);
     nextId++;
     tasks.push_back(newTask);
}

void TaskManager::displayTasks() const {
     std::cout << "\033[1;37m--------------------------------------------------------------------------------\033[0m" << std::endl;
     std::cout << "\033[1;31mID" << '\t' << '|' << "Title" << '\t' << '|' << "Description" << '\t' << '|' << "Due date" << '\t' << '|' << "Status\033[0m" << std::endl;
     std::cout << "\033[1;37m--------------------------------------------------------------------------------\033[0m" << std::endl;


     std::cout << "\033[32m";
     for (unsigned int i = 0; i < tasks.size(); i++) {       
          tasks.at(i).display();        
     }
     std::cout << "\033[0m";


     std::cout << "\033[1;37m--------------------------------------------------------------------------------\033[0m" << std::endl << std::endl;
}

bool TaskManager::completeTask(int id) {
     if (checkForInvalidID(id)) {
          return false;
     }

     tasks.at(id - 1).toggleComplete();
     std::cout << "\033[1;37mTask ID " << id << " marked as Done!\033[0m" << std::endl;
     return true;
}

bool TaskManager::deleteTask(int id) {
     if (checkForInvalidID(id)) {
          return false;
     }

     for (unsigned int i = id; i < tasks.size(); i++) {
          tasks.at(i).id -= 1;
     }

     tasks.erase(tasks.begin() + (id - 1));
     std::cout << "\033[1;37mTask ID " << id << " marked has been deleted!\033[0m" << std::endl;
     return true;
}

bool TaskManager::checkForInvalidID(int id) {
     try {
          if (id < STARTING_ID || id > tasks.size()) {
               throw DeleteNonexistTaskError();
          }
     }
     catch (const DeleteNonexistTaskError&) {
          std::cout << "Error: You entered an invalid ID." << std::endl;
          return true;
     }
     return false;
}

#endif
