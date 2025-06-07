#ifndef TASK_H
#define TASK_H
#include <iostream>

class Task {
    const int DEFAULT_ID = 0;
    const std::string DEFAULT_TITLE = "None";
    const std::string DEFAULT_DESCRIPTION = "None";
    const std::string DEFAULT_DUE_DATE = "1/01/2000";

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

    private:

};

Task::Task() {
    title = DEFAULT_TITLE;
    description = DEFAULT_DESCRIPTION;
    dueDate = DEFAULT_DUE_DATE;
    id = DEFAULT_ID;
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
    std::cout << id << '\t|' << title << '\t|' << description << '\t|' << dueDate << '\t|' << getStatus() << std::endl;
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
