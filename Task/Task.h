/**
 * @file task.h
 * @brief Defines the Task class used to represent a single task in the task 
          manager.
 */

#ifndef TASK_H_
#define TASK_H_
#include <iostream>
#include <string>

/**
 * @class Task
 * @brief Represents an individual task with a title, description, deadline,  
          status, and ID.
 */
class Task {
private:
    //Make data members private and include accessor/mutator functions for
    // next improvement.
public:
     /**
     * @brief The title of the Task.
     */
     std::string title;

     /**
     * @brief The description of the Task.
     */
     std::string description;

     /**
     * @brief The deadline of the Task.
     */
     std::string dueDate;

     /**
     * @brief The status of the Task.
     */
     bool isCompleted;
     /**
     * @brief The ID # of the Task.
     */
     int id;

     /**
     * Task() - Default constructor.
     * Initializes id, title, description, dueDate, and isCompleted to default 
     * values.
     */
     Task();

     /**
     * Task(int taskId, std::string taskTitle, std::string taskDescription, 
            std::string taskDeadline, bool taskCompletion) - 
            Parameterized Constructor
     * Initializes id, title, description, dueDate, and isCompleted to
     * paramterized values.
     */
     Task(int taskId, std::string taskTitle, std::string taskDescription, std::string taskDeadline, bool taskCompletion);

     /**
     * @brief Displays the fields of the Task.
     * 
     * This function displays each field of the Task in the following order:
     * id, title, description, dueDate, and "Done" or "Pending" (indicated
     * by getStatus())
     * 
     * @pre None.
     * @post The Task is outputted.
     */
     void display() const;

     /**
     * @brief Toggles the Task as complete.
     * 
     * This function sets isCompleted to true.
     * 
     * @pre None (However, I should consider implementing the
     *      checkForCompletion() function as an exception here to confirm that
     *      Task is not already marked as complete.
     * @post isComplete is set to true.
     */
     void toggleComplete();

     /**
     * @brief Returns the status of Task.
     * 
     * This function returns the status of the Task object, determined by
     * isCompleted.
     * 
     * @return String "Done" if isCompleted == true; "Pending" if isCompleted
     *         == false.
     * @pre None.
     * @post A string "Done" or "Pending".
     */
     std::string getStatus() const;
};
#endif
