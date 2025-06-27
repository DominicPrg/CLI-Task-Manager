/**
 * @file taskmanager.h
 * @brief Declares the TaskManager class responsible for managing a list of tasks.
 */

#ifndef TASK_MANAGER_H_
#define TASK_MANAGER_H_
#include "Task.h"
#include <iostream>
#include <string>
#include <vector>
#include "json.hpp"

namespace task_manager {
     /**
     * @brief A constant value representing the first ID number.
     * @details This constant value should always remain at 1 to inititialize
     * the first Task with '1', and incremenet the ID of each enw Task
     * accordingly.
     */
     const int STARTING_ID = 1;

     /**
      * @class TaskManager
      * @brief Handles user interactions and manages a collection of Task objects.
      */
     class TaskManager : public Task {
     private:
          /**
          * @brief A vector of Tasks.
          * @details This stores the Tasks created during the program's 
          * runtime.
          */
          std::vector<Task> tasks;

          /**
          * @brief The ID # of a Task in tasks, based on ordering.
          */
          int nextId;

          /**
          * @brief Checks for an invalid ID.
          * 
          * This function verifies the invalidity of id (if id is < STARTING_ID
          * and id > tasks.size())
          * 
          * @param id The ID # of Task.
          * @return true id is invalid.
          * @return false id is valid
          * @throws AccessNonexistTaskError if id is invalid.
          * @pre None.
          * @post None.
          */
          bool checkForInvalidID(int id) const;

          /**
          * @brief Checks for the completion of a Task.
          * 
          * This function verifies the completion status of a Task.
          * 
          * @param id The ID # of Task.
          * @return true Task is already toggled as completed.
          * @return false Task isn't toggled as completed.
          * @pre id should be valid.
          * @post None.
          */
          bool checkForCompletion(int id) const;

          /**
          * @brief Prints out all Tasks in a vector of Tasks.
          * 
          * This function prints out a table detailing the Tasks in a vector
          * of Tasks. It calls displayUpperHalfTable(), calls out the Task
          * class display() function on each Task in a for loop, and calls
          * displayLowerHalfTable().
          * 
          * @pre None.
          * @post All Tasks in a vector have been outputted in table format.
          */
          void displayTasks(const std::vector<Task>& vectorOfTasks) const;

          /**
          * @brief Prints out the upper half of the table.
          * 
          * This function prints out the upper half of the table, including 
          * distinct fields of a Task.
          * 
          * @pre None.
          * @post Upper half of the table has been outputted.
          */
          void displayUpperHalfTable() const;

          /**
          * @brief Prints out the lower half of the table.
          * 
          * This function prints out the lower half of the table.
          * 
          * @pre None.
          * @post Lower half of the table has been outputted.
          */
          void displayLowerHalfTable() const;

          /**
          * @brief Inputs the data members of a Task.
          * 
          * This function prompts the user to enter the information of a Task,
          * which includes the Task's title, description, deadline, and status.
          * 
          * @param taskTitle The Task's title.
          * @param taskDescription The Task's description.
          * @param taskDeadline The Task's deadline.
          * @param taskCompletionString The Task's status in string format.
          * @param taskCompletionBool The Task's status in boolean format.
          * @pre None.
          * @post The variables, having been passed by reference, can be used
          *       as parameters for creating a Task.
          */
          void enterTaskInfo(std::string& taskTitle, std::string& taskDescription, std::string& taskDeadline, std::string& taskCompletionString, bool& taskCompletionBool) const;

          /**
          * @brief Checks for an empty title string.
          * 
          * This function confirms if an empty string has been inputted for
          * the title.
          * 
          * @param titleStr The title string.
          * @return true titleStr is empty.
          * @return false titleStr isn't empty.
          * @pre None.
          * @post None.
          */
          void checkForEmptyTitle(std::string& titleStr) const;

          /**
          * These are scrapped functions that I failed to complete.
          * Will consider implementing them if I revisit this project and
          * expand upon it.
          * 
          * void searchByKeyword(const std::vector<Task>& tasks) const;
          * void searchByStatus(const std::vector<Task>& tasks) const;
          * void searchByID(const std::vector<Task>& tasks) const;
          */

     public:
          /**
          * TaskManager() - Default constructor.
          * Initializes nextID to value of STARTING_ID (which should always be
          * initialized to 1).
          */
          TaskManager();

          /**
          * @breif Lists the available commands of TaskManager.   
          * 
          * This function outputs the following commands, along with their
          * description: add, list, complete, and delete.
          * 
          * @pre None.
          * @post The list of commands are outputed to the terminal.    
          */
          void printCommands() const;

          /**
          * @brief A Task object is created and added to tasks.
          * 
          * This function declares local variables to hold the input value for 
          * the data members of the Task object, passes them by reference to
          * enterTaskInfo() to gather data, and passes the local variables as
          * parameters to a Task object. The Task object is added to tasks, and
          * nextID is incremented by 1.
          * 
          * @pre None.
          * @post A Task object is added to tasks.
          */
          void addTask();  

          /**
          * @brief All Task objects in tasks are displayed.
          * 
          * This function passes tasks as an argument to displayTasks().
          * 
          * @pre None.
          * @post The list of the tasks are outputted to the terminal.
          */
          void listTasks() const;

          /**
          * @brief A Task, specified by id, is marked as completed.
          * 
          * This function confirms that the Task's ID exists and that Task is
          * NOT already completed. The Task is accessed by ID and calls
          * toggleComplete(). The function verifies this procedure by explicity
          * stating that the task has been completed.
          * 
          * @param id Task object's ID number.
          * @return true The Task was toggled as completed. 
          * @return false Task's ID is nonexistent or Task is already toggled 
          *               as completed.
          * @pre Task's id must be valid and Task's getStatus() function must
          *      not return "Done".
          * @post Task's (specified by ID) status is marked as "Done" and 
          *       isCompleted == true.
          */
          bool completeTask(int id);

          /**
          * @brief A Task, specified by id, is deleted from tasks.
          * 
          * This function confirms that the Task's ID exist. All subsequent
          * Task objects' ID are decremented. The Task to-be-deleted is erased
          * from tasks. The function verifies the procedure by explicitly
          * stating that the task has been deleted.
          * 
          * @param id Task object's ID number.
          * @return true The Task was deleted from tasks.
          * @return false The Task's id is invalid or tasks is already empty.
          * @pre Task's id must be valid and tasks mustn't be empty.
          * @post All subsequent Task's id have been decremented and the
          *       specified Task has been erased from tasks.
          */
          bool deleteTask(int id);

          /**
          * @brief TaskManager is checked to be empty or not.
          * 
          * This function verifies whether or not a TaskManager object 
          * is empty, indicated by at least one Task object in tasks.
          * 
          * @return true tasks has at least one Task object.
          * @return false tasks is empty.
          * @pre None.
          * @post None.
          */
          bool isTaskManagerEmpty() const;

          /**
          * @brief An accessor method for returning tasks.
          * 
          * This function returns the tasks vector in a TaskManager object.
          * 
          * @return tasks The vector of Tasks.
          * @pre None.
          * @post None.
          */
          std::vector<Task> getTasks() const;

          /**
          * @brief Inserts a pre-defined Task into tasks.
          * 
          * This function pushes a Task back into tasks and, consequently,
          * increments nextID.
          * 
          * @param thisTask The Task to be pushed into tasks.
          * @pre None.
          * @post thisTask has been successfully inserted into tasks.
          */
          void insertTask(const Task& thisTask);

          //Scrapped function
          //void searchForTask(std::string& searchFeature) const;

          /**
          * @class AccessNonexistTaskError
          * @brief Represents an error in which a non-existent Task is called.
          * 
          * This exception is thrown when a non-existent Task is attempted
          * access by the client user.
          */
          class AccessNonexistTaskError {};
     };
}
#endif
