#ifndef STORAGE_H_
#define STORAGE_H_
#include "Task.h"
#include "json.hpp"
#include "storage_util.h"
#include <vector>

/**
* @brief All JSON objects from a ".json" file are transfered to a vector of
*        Tasks.
*
* This function opens a ".json" file, uses ifstream to access the
* JSON objects in the file, and converts each JSON object into a Task object.
*
* @param fileName The ".json" file to load the contents from.
* @param vectorOfTasks The vector of Tasks to contain the fields from the 
*        JSON object.
* @return true The file was opened and contained valid JSON
*              structure.
* @return false The file failed to open or unexpected/missing/
*               invalid JSON structure is encountered.
* @pre fileName must be a ".json" file, with correct naming, that's
*      accessible by the program. fileName must also contain valid
*      JSON structure.
* @post tasks consist of Task-converted JSON objects from fileName.
*/
bool loadFromFile(std::vector<Task>& vectorOfTasks, const std::string& fileName);

/**
* @brief All Task objects in tasks are saved onto a ".json" file.
*
* This function opens a ".json" file, creates a JSON array, converts
* all Task objects in vectorOfTasks into a JSON object, and uses ofstream to
* enter the tasks in JSON format, before closing the file.
*
* @param fileName The ".json" file to save the contents onto.
* @param vectorOfTasks The vector of Tasks to transfer data from.
* @return true The file was opened and the data was saved onto it.
* @return false The file failed to open.
* @pre fileName must be a ".json" file, with correct naming, that's
       accessible by the program.
* @post fileName consists of JSON-converted Task objects from tasks.
*/
bool saveToFile(const std::vector<Task>& vectorOfTasks, const std::string& fileName);
#endif
