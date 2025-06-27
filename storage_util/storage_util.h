#ifndef STORAGE_UTIL_H_
#define STORAGE_UTIL_H_
#include "json.hpp"
#include "Task.h"

/**
* @brief Creates a JSON object based on Task.
*
* This function creates a JSON object with fields associated with
* the Task object.
*
* @param jsonObject A JSON object to be initialized to Task's fields.
* @param taskObject The Task blueprint for the JSON object.
* @pre taskObject should contain every necessary field.
* @post jsonObject cotains taskObject's fields and is ready for use.
*/
void to_json(nlohmann::json& jsonObject, const Task& taskObject);

/**
* @brief Creates a Task based on a JSON object.
*
* This function creates a Task with the fields associated with the
* JSON object.
*
* @param jsonObject The JSON blueprint for the Task.
* @param taskObject A Task object to be initialized to the JSON
*        object's fields.
* @pre jsonObject should contain every necessary field.
* @post taskObject contains jsonObject's fields and is ready for use.
*/
void from_json(const nlohmann::json& jsonObject, Task& taskObject);
#endif
