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

     const void TaskManager::printCommands() const {
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

     void TaskManager::enterTaskInfo(std::string& taskTitle, std::string& taskDescription, std::string& taskDeadline, std::string& taskCompletionString, bool& taskCompletionBool) const {
          std::cout << "Enter task title: ";
          std::getline(std::cin, taskTitle);

          std::cout << "Enter task description: ";
          std::getline(std::cin, taskDescription);

          std::cout << "Enter task deadline: ";
          std::getline(std::cin, taskDeadline);

          std::cout << "Enter task status (done/pending): ";
          std::getline(std::cin, taskCompletionString);
          std::transform(taskCompletionString.begin(), taskCompletionString.end(), taskCompletionString.begin(), ::toupper);

          if (taskCompletionString.find("DONE") != std::string::npos) {
               taskCompletionBool = true;
          }

          std::cout << std::endl;
          std::cin.ignore();
     }

     void TaskManager::listTasks() const {
          displayTasks(tasks);
     }

     const void TaskManager::displayTasks(const std::vector<Task>& vectorOfTasks) const {
          displayUpperHalfTable();

          for (unsigned int i = 0; i < vectorOfTasks.size(); i++) {
               vectorOfTasks.at(i).display();
          }

          displayLowerHalfTable();
     }

     const void TaskManager::displayUpperHalfTable() const {
          std::cout << "\033[1;37m--------------------------------------------------------------------------------\033[0m" << std::endl;
          std::cout << "\033[1;31mID" << '\t' << '|' << "Title" << '\t' << '|' << "Description" << '\t' << '|' << "Due date" << '\t' << '|' << "Status\033[0m" << std::endl;
          std::cout << "\033[1;37m--------------------------------------------------------------------------------\033[0m" << std::endl;
          std::cout << "\033[32m";
     }

     const void TaskManager::displayLowerHalfTable() const {
          std::cout << "\033[0m";
          std::cout << "\033[1;37m--------------------------------------------------------------------------------\033[0m" << std::endl << std::endl;
     }

     bool TaskManager::completeTask(int id) {
          if (checkForInvalidID(id)) {
               return false;
          }

          if (checkForCompletion(id)) {
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
          nextId--;
          return true;
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

     bool TaskManager::checkForCompletion(int id) const {
          if (tasks.at(id - 1).getStatus() == "Done") {
               std::cout << "\033[1;37Task ID " << id << " is already marked as Done.\033[0m" << std::endl;
               return true;
          }
          return false;
     }

     void TaskManager::to_json(nlohmann::json& jsonObject, const Task& taskObject) const {
          jsonObject = {
               {"id", taskObject.id},
               {"title", taskObject.title},
               {"description", taskObject.description},
               {"deadline", taskObject.dueDate},
               {"status", taskObject.isCompleted}
          };
     }

     void TaskManager::from_json(const nlohmann::json& jsonObject, Task& taskObject) {
          try {
               jsonObject.at("id").get_to(taskObject.id);
               jsonObject.at("title").get_to(taskObject.title);
               jsonObject.at("description").get_to(taskObject.description);
               jsonObject.at("deadline").get_to(taskObject.dueDate);
               jsonObject.at("status").get_to(taskObject.isCompleted);
          }
          catch (const json::exception& e) {
               std::cerr << "JSON conversion error: " << e.what() << std::endl;
               throw;
          }

          /*
          taskObject.id = jsonObject.at("id").get<int>();
          taskObject.title = jsonObject.at("title").get<std::string>();
          taskObject.description = jsonObject.at("description").get<std::string>();
          taskObject.dueDate = jsonObject.at("deadline").get<std::string>();
          taskObject.isCompleted = jsonObject.at("status").get<bool>();*/
     }

     bool TaskManager::saveToFile(const std::string& fileName) const {
          std::ofstream outFile(fileName);

          if (!outFile.is_open())
          {
               std::cerr << "Error: \"" << fileName << "\" could not be found or opened." << std::endl;
               return false;
          }
          else {
               json jsonTasks = json::array();

               for (unsigned int i = 0; i < TaskManager::tasks.size(); i++) {
                    json j;
                    to_json(j, TaskManager::tasks.at(i));
                    jsonTasks.push_back(j);
               }

               outFile << jsonTasks.dump(4);
               outFile.close();
          }
          return true;
     }

     bool TaskManager::loadFromFile(const std::string& fileName) {
          std::ifstream inFile(fileName);

          if (!inFile.is_open()) {
               std::cerr << "Error: \"" << fileName << "\" could not be found or opened." << std::endl;
               return false;
          }
          else {
               json jsonTasks;

               try {
                    inFile >> jsonTasks;
               }
               catch (const json::parse_error& e) {
                    std::cerr << "Parse error: " << e.what() << std::endl;
                    return false;
               }
               catch (const std::exception& e) {
                    std::cerr << "Error: " << e.what() << std::endl;
                    return false;
               }

               tasks.clear();
               nextId = STARTING_ID;
               for (const auto& jsonTask : jsonTasks) {
                    Task task;
                    from_json(jsonTask, task);
                    tasks.push_back(task);
                    nextId++;
               }
          }
          return true;
     }

     //Don't worry about this function in time. It's an optional enhancement.
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
