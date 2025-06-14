#include "Task.h"
#include <iostream>
#include <string>

Task::Task() {
     title = "Untitled";
     description = "None";
     dueDate = "1/01/2000";
     id = 0;
     isCompleted = false;
}

Task::Task(int taskId, std::string taskTitle, std::string taskDescription, std::string taskDeadline, bool taskCompletion) {
     title = taskTitle;
     description = taskDescription;
     dueDate = taskDeadline;
     id = taskId;
     isCompleted = taskCompletion;
}

void Task::display() const {
     std::cout << id << '\t' << '|' << title << '\t' << '|' << description << '\t' << '|' << dueDate << '\t' << '|' << getStatus() << std::endl;
}

void Task::toggleComplete() {
     isCompleted = true;
}

std::string Task::getStatus() const {
     if (isCompleted) {
          return "Done";
     }
     return "Pending";
}
