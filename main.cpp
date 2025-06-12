#include <iostream>
#include "TaskManager.h"
#include "Task.h"

void runProgram();
void processInput(TaskManager& userTaskManager, std::string& userInput);

int main() {
	runProgram();
}

void runProgram() {
	TaskManager myTaskManager;
	std::string input;

	std::cout << "Welcome to CLI Task Manager!" << std::endl;
	std::cout << "Type help to see available commands." << std::endl;
	std::getline(std::cin, input);

	while (input != "exit") {
		processInput(myTaskManager, input);
		std::cout << std::endl;
		std::getline(std::cin, input);
	}

	std::cout << "Goodbye!";
}

void processInput(TaskManager& userTaskManager, std::string& userInput) {
	int taskID;

	if (userInput == "help") {
		userTaskManager.printCommands();
	}
	else if (userInput == "add") {
		userTaskManager.addTask();
	}
	else if (userInput == "complete") {
		std::cout << "Enter task ID: ";
		std::cin >> taskID;
		userTaskManager.completeTask(taskID);
	}
	else if (userInput == "delete") {
		std::cout << "Enter task ID: ";
		std::cin >> taskID;
		userTaskManager.deleteTask(taskID);
	}
	else if (userInput == "list") {
		userTaskManager.displayTasks();
	}
	else {
		std::cout << "Invalid command. Please type \"help\" to see the full list of commands.";
	}
}
