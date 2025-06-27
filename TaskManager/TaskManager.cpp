#ifndef TASK_MANAGER_CPP_
#define TASK_MANAGER_CPP_
#include "TaskManager.h"
#include <cctype>
#include <stdexcept>
#include <fstream>
#include <algorithm> //For std::transform function
using json = nlohmann::json;

namespace task_manager {
     TaskManager::TaskManager() {
          nextId = STARTING_ID;
     }

     bool TaskManager::checkForInvalidID(int id) const {
          try {
               if (id < STARTING_ID || id > tasks.size()) {
                    throw AccessNonexistTaskError();
               }
          }
          catch (const AccessNonexistTaskError&) {
               std::cout << "Error: You entered an invalid ID." << std::endl;
               return true;
          }
          return false;
     }

     //Note to self: consider implementation in Task instead.
     bool TaskManager::checkForCompletion(int id) const {
          if (tasks.at(id - 1).getStatus() == "Done") {
               std::cout << "\033[1;37mTask ID " << id << " is already marked as Done.\033[0m" << std::endl;
               return true;
          }
          return false;
     }

     void TaskManager::displayTasks(const std::vector<Task>& vectorOfTasks) const {
          displayUpperHalfTable();

          for (unsigned int i = 0; i < vectorOfTasks.size(); i++) {
               if (vectorOfTasks.at(i).getStatus() == "Done") {
                    std::cout << "\033[1;32m";
               }
               else {
                    std::cout << "\033[1;31m";
               }
               vectorOfTasks.at(i).display();
               std::cout << "\033[0m";
          }

          displayLowerHalfTable();
     }

     void TaskManager::displayUpperHalfTable() const {
          std::cout << "\033[1;37m-----------------------------------------------------------------------------------------\033[0m" << std::endl;
          std::cout << "\033[1;37mID" << '\t' << '\t' << '|' << "Title" << '\t' << '\t' << '|' << "Description" << '\t' << '\t' << '|' << "Due date" << '\t' << '\t' << '|' << "Status\033[0m" << std::endl;
          std::cout << "\033[1;37m-----------------------------------------------------------------------------------------\033[0m" << std::endl;
     }

     void TaskManager::displayLowerHalfTable() const {
          std::cout << "\033[1;37m-----------------------------------------------------------------------------------------\033[0m" << std::endl << std::endl;
     }

     void TaskManager::enterTaskInfo(std::string& taskTitle, std::string& taskDescription, std::string& taskDeadline, std::string& taskCompletionString, bool& taskCompletionBool) const {
          std::cout << "Enter task title: ";
          std::getline(std::cin, taskTitle);
          checkForEmptyTitle(taskTitle);

          std::cout << "Enter task description: ";
          std::getline(std::cin, taskDescription);

          std::cout << "Enter task deadline: ";
          std::getline(std::cin, taskDeadline);

          std::cout << "Enter task status (done/pending): ";
          std::getline(std::cin, taskCompletionString);
          std::transform(taskCompletionString.begin(), taskCompletionString.end(), taskCompletionString.begin(), ::toupper);

          while (taskCompletionString.find("PENDING") == std::string::npos && taskCompletionString.find("DONE") == std::string::npos) {
               std::cout << "Error: please enter \"done\" or \"pending\" (not case-sensitive): ";
               std::getline(std::cin, taskCompletionString);
               std::transform(taskCompletionString.begin(), taskCompletionString.end(), taskCompletionString.begin(), ::toupper);
          }

          if (taskCompletionString.find("DONE") != std::string::npos) {
               taskCompletionBool = true;
          }

          std::cout << std::endl;
     }

     void TaskManager::checkForEmptyTitle(std::string& titleStr) const {
          while (titleStr.empty()) {
               std::cout << "Error: task title must have at least one character. Please try again: ";
               std::getline(std::cin, titleStr);
          }
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
          
          enterTaskInfo(taskTitle, taskDescription, taskDeadline, taskCompletionString, taskCompletionBool);
          Task newTask(nextId, taskTitle, taskDescription, taskDeadline, taskCompletionBool);
          
          nextId++;
          tasks.push_back(newTask);
     }

     void TaskManager::listTasks() const {
          displayTasks(tasks);
     }

     bool TaskManager::completeTask(int id) {
          if (checkForInvalidID(id) || checkForCompletion(id)) {
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

          if (isTaskManagerEmpty()) {
               std::cout << "Error: there are no tasks in task manager." << std::endl;
               return false;
          }

          for (unsigned int i = id; i < tasks.size(); i++) {
               tasks.at(i).id -= 1;
          }

          tasks.erase(tasks.begin() + (id - 1));
          std::cout << "\033[1;37mTask ID " << id << " marked has been deleted!\033[0m" << std::endl;
          nextId--;
          return true;
     }

     bool TaskManager::isTaskManagerEmpty() const {
          if (tasks.empty()) {
               return true;
          }
          return false;
     }

     std::vector<Task> TaskManager::getTasks() const {
          return tasks;
     }

     void TaskManager::insertTask(const Task& thisTask) {
          tasks.push_back(thisTask);
          nextId++;
     }

     //Scrapped function
     /*
     void TaskManager::searchForTask(std::string& searchFeature) const {
        std::transform(searchFeature.begin(), searchFeature.end(), searchFeature.begin(), ::toupper);

        if (searchFeature != "KEYWORD" && searchFeature != "STATUS" && searchFeature != "ID") {
             std::cerr << "Error: unrecognized command. Could not execute function." << std::endl;
             return;
        }
        else {
             if (searchFeature == "KEYWORD")
        }
     }*/

}
#endif
