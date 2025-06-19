#ifndef TASK_MANAGER_H_
#define TASK_MANAGER_H_
#include "Task.h"
#include <iostream>
#include <string>
#include <vector>
#include "json.hpp"

namespace task_manager {
     const int STARTING_ID = 1;

     class TaskManager : public Task {
     private:
          std::vector<Task> tasks;
          int nextId;
          bool checkForInvalidID(int id) const;
          bool checkForCompletion(int id) const;
          void to_json(nlohmann::json& jsonObject, const Task& taskObject) const;
          void from_json(const nlohmann::json& jsonObject, Task& taskObject);
          const void displayTasks(const std::vector<Task>& vectorOfTasks) const;
          const void displayUpperHalfTable() const;
          const void displayLowerHalfTable() const;
          void enterTaskInfo(std::string& taskTitle, std::string& taskDescription, std::string& taskDeadline, std::string& taskCompletionString, bool& taskCompletionBool) const;
          //void searchByKeyword(const std::vector<Task>& tasks) const;
          //void searchByStatus(const std::vector<Task>& tasks) const;
          //void searchByID(const std::vector<Task>& tasks) const;

     public:
          TaskManager();
          const void printCommands() const;
          void addTask();     
          void listTasks() const;
          bool saveToFile(const std::string& fileName) const;
          bool loadFromFile(const std::string& fileName);
          bool completeTask(int id);
          bool deleteTask(int id);
          //void searchForTask(std::string& searchFeature) const;
          class AccessNonexistTaskError {};
     };
}
#endif
