#ifndef TASK_CPP_
#define TASK_CPP_
#include "Task.h"

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
     //std::cout << id << std::setw(4) << '| ' << title << std::setw(20) << '| ' << description << std::setw(20) << '| ' << dueDate << std::setw(10) << '| ' << getStatus() << std::endl;
     std::cout << id << '\t' << '\t' << '|' << title << '\t' << '\t' << '|' << description << '\t' << '\t' << '|' << dueDate << '\t' << '\t' << '|' << getStatus() << std::endl;
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
#endif
