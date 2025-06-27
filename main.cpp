/**
 * @file main.cpp
 * @brief Entry point for the CLI Task Manager program.
 *
 * Handles the main menu loop and user interaction by calling TaskManager methods.
 * Acts as the interface layer between the user and the task manager logic.
 */

#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
#include "Task.h"
#include "TaskManager.h"
#include "Storage.h"
#include "json.hpp"
using json = nlohmann::json;
using namespace task_manager;

void runCLITaskManager();
void processInput(TaskManager& userTaskManager, std::string& userInput);
void openJsonFile(TaskManager& userTaskManager);
void convertToJsonFile(TaskManager& userTaskManager);
void handleStringInput(std::string& userInput);

int main() {
	runCLITaskManager();
}

void runCLITaskManager() {
	TaskManager myTaskManager;
	std::string input;

	openJsonFile(myTaskManager);

	std::cout << "\033[1;37mWelcome to the CLI Task Manager!" << std::endl;
	std::cout << "Type help to see available commands. Enter \"exit\" to exit out of the program.\033[0m" << std::endl << std::endl;
	handleStringInput(input);

	while (input != "EXIT") {
		processInput(myTaskManager, input);
		std::cout << std::endl;
		handleStringInput(input);
	}

	convertToJsonFile(myTaskManager);

	std::cout << "Goodbye!";
}

void processInput(TaskManager& userTaskManager, std::string& userInput) {
	int taskID;

	if (userInput == "HELP") {
		userTaskManager.printCommands();
	}
	else if (userInput == "ADD") {
		userTaskManager.addTask();
	}
	else if (userInput == "COMPLETE") {
		std::cout << "Enter task ID: ";
		std::cin >> taskID;
		std::cin.ignore();
		userTaskManager.completeTask(taskID);
	}
	else if (userInput == "DELETE") {
		std::cout << "Enter task ID: ";
		std::cin >> taskID;
		std::cin.ignore();
		userTaskManager.deleteTask(taskID);
	}
	else if (userInput == "LIST") {
		userTaskManager.listTasks();
	}
	//Scrapped function
	/*
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

void openJsonFile(TaskManager& userTaskManager) {
	std::string input;
	std::string fileName;
	std::vector<Task> theseTasks;

	std::cout << "Before you start the program, would you load tasks from a previous session through a \".json\" file? (y/n): ";
	handleStringInput(input);
	std::cout << std::endl;

	while (input != "Y" && input != "N") {
		std::cout << "Error: invalid input. Please enter \'y\' or \'n\': ";
		handleStringInput(input);
		std::cout << std::endl;
	}

	if (input == "N") {
		std::cout << "Okay! Tasks will not be loaded then.";
	}
	else {
		std::cout << "Okay! Please enter the name of your \".json\" file to load from, or enter \"exit\" (in lower-case) to continue without the procedure:" << std::endl;
		std::getline(std::cin, fileName);
		std::cout << std::endl;

		while (fileName != "exit" && loadFromFile(theseTasks, fileName) == false) {
			std::cout << "Please make sure that the \"json\" has valid JSON structure, confirm that the file name is correct, or enter 'exit'" << std::endl;
			std::cout << "(in lower-case) to continue without the procedure: ";
			std::getline(std::cin, fileName);
		}

		if (fileName != "exit") {
			for (unsigned int i = 0; i < theseTasks.size(); i++) {
				userTaskManager.insertTask(theseTasks.at(i));
			}
			std::cout << "Tasks have been successfully loaded into the program!";
		}
	}
	std::cout << std::endl << std::endl << std::endl;
}

void convertToJsonFile(TaskManager& userTaskManager) {
	if (!userTaskManager.isTaskManagerEmpty()) {
		std::string input;
		std::string fileName;

		std::cout << "Before you exit the program, would you like to save your tasks onto a \".json\" file? (y/n): ";
		handleStringInput(input);

		while (input != "Y" && input != "N") {
			std::cout << "Error: invalid input. Please enter simply \'y\' or \'n\': ";
			handleStringInput(input);
		}

		if (input == "N") {
			std::cout << "Okay! Tasks will not be saved then.";
		}
		else {
			std::cout << "Okay! Please enter the name of your \".json\" file to save to, or enter \"exit\" (in lower-case) to continue without the procedure:" << std::endl;
			std::getline(std::cin, fileName);

			while (fileName != "exit" && saveToFile(userTaskManager.getTasks(), fileName) == false) {
				std::cout << "Please make sure the file name is correct, or enter 'exit' (in lower-case) to continue without the procedure: ";
				std::getline(std::cin, fileName);
			}

			if (fileName != "exit") {
				std::cout << "Tasks have been successfully saved into the \"" << fileName << "\" file.";
			}
		}
	}
	std::cout << std::endl << std::endl << std::endl;
}

void handleStringInput(std::string& userStr) {
	std::getline(std::cin, userStr);

	while (userStr.empty()) {
		std::cout << "Error: string cannot be null. Please try again: ";
		std::getline(std::cin, userStr);
	}

	std::transform(userStr.begin(), userStr.end(), userStr.begin(), ::toupper);
}
