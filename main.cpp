#include <iostream>
#include "TaskManager.h"
#include "json.hpp"
using json = nlohmann::json;
using namespace task_manager;

void runCLITaskManager();
void processInput(TaskManager& userTaskManager, std::string& userInput);
void convertToJsonFile(TaskManager& userTaskManager);
void openJsonFile(TaskManager& userTaskManager);

int main() {
	runCLITaskManager();
}

void runCLITaskManager() {
	TaskManager myTaskManager;
	std::string input;

	openJsonFile(myTaskManager);

	std::cout << "Welcome to the CLI Task Manager!" << std::endl;
	std::cout << "Type help to see available commands." << std::endl;
	std::getline(std::cin, input);

	while (input != "exit") {
		processInput(myTaskManager, input);
		std::cout << std::endl;
		std::getline(std::cin, input);
	}

	convertToJsonFile(myTaskManager);

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
		userTaskManager.listTasks();
	}/*
	else if (userInput == "search") {
		std::string searchFeature;
		std::cout << "By what criteria would you like to search a task by?" << std::endl;
		std::cout << '\t' << "Enter \"Keyword\" to search by keyword of title." << std::endl;
		std::cout << '\t' << "Enter \"Status\" to search by status of title." << std::endl;
		std::cout << '\t' << "Enter \"ID\" to search by task's ID." << std::endl;
		std::getline(std::cin, searchFeature);

		
	}*/
	else {
		std::cout << "Invalid command. Please type \"help\" to see the full list of commands." << std::endl;
	}
}

void convertToJsonFile(TaskManager& userTaskManager) {
	char input;
	std::string fileName;

	std::cout << "Before you exit the program, would you like to save your tasks onto a \".json\" file? (y/n): ";
	std::cin >> input;
	std::cin.ignore();

	while (input != 'y' && input != 'n') {
		std::cout << "Error: invalid input. Please enter \'y\' or \'n\': ";
		std::cin >> input;
	}

	if (input == 'n') {
		std::cout << "Okay! Tasks will not be saved then.";
	}
	else {
		std::cout << "Okay! Please enter the name of your \".json\" file to save to, or enter \"exit\" to continue without the procedure: ";
		std::getline(std::cin, fileName);

		while (userTaskManager.saveToFile(fileName) == false && fileName != "exit") {
			std::cout << "Please make sure the file name is correct, or enter 'exit' to continue without the procedure: ";
			std::getline(std::cin, fileName);
		}

		if (fileName != "exit") {
			std::cout << "Tasks have been successfully saved into the \"" << fileName << "\" file.";
		}
	}
	std::cout << std::endl << std::endl << std::endl;
}

void openJsonFile(TaskManager& userTaskManager) {
	char input;
	std::string fileName;

	std::cout << "Before you start the program, would you load tasks from a previous session through a \".json\" file? (y/n): ";
	std::cin >> input;
	std::cin.ignore();

	while (input != 'y' && input != 'n') {
		std::cout << "Error: invalid input. Please enter \'y\' or \'n\': ";
		std::cin >> input;
	}

	if (input == 'n') {
		std::cout << "Okay! Tasks will not be loaded then."; 
	}
	else {
		std::cout << "Okay! Please enter the name of your \".json\" file to load from, or enter \"exit\" to continue without the procedure: ";
		std::getline(std::cin, fileName);

		while (userTaskManager.loadFromFile(fileName) == false && fileName != "exit") {
			std::cout << "Please make sure that the \"json\" has valid JSON structure, confirm that the file name is correct, or enter 'exit' to continue without the procedure: ";
			std::getline(std::cin, fileName);
		}

		if (fileName != "exit") {
			std::cout << "Tasks have been successfully loaded into the program!";
		}
	}
	std::cout << std::endl << std::endl << std::endl;
}
