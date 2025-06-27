#ifndef STORAGE_UTIL_CPP_
#define STORAGE_UTIL_CPP_
#include "storage_util.h"
using json = nlohmann::json;

void to_json(nlohmann::json& jsonObject, const Task& taskObject) {
     jsonObject = {
          {"title", taskObject.title},
          {"description", taskObject.description},
          {"deadline", taskObject.dueDate},
          {"status", taskObject.isCompleted},
          {"id", taskObject.id }
     };
}

void from_json(const nlohmann::json& jsonObject, Task& taskObject) {
     try {
          jsonObject.at("title").get_to(taskObject.title);
          jsonObject.at("description").get_to(taskObject.description);
          jsonObject.at("deadline").get_to(taskObject.dueDate);
          jsonObject.at("status").get_to(taskObject.isCompleted);
          jsonObject.at("id").get_to(taskObject.id);
     }
     catch (const json::exception& e) {
          std::cerr << "JSON conversion error: " << e.what() << std::endl;
          throw;
     }
}
#endif
