#ifndef TASK_H
#define TASK_H
#include <iostream>
#include <string>

class Task {
public:
     Task();
     Task(int taskId, std::string taskTitle, std::string taskDescription, std::string taskDeadline, bool taskCompletion);
     std::string title;
     std::string description;
     std::string dueDate;
     bool isCompleted;
     int id;
     void display() const;
     void toggleComplete();
     std::string getStatus() const;
};

#endif
