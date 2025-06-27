#ifndef STORAGE_CPP_
#define STORAGE_CPP_
#include "Storage.h"
#include <fstream>
using json = nlohmann::json;

bool loadFromFile(std::vector<Task>& vectorOfTasks, const std::string& fileName) {
     std::ifstream inFile(fileName);

     if (!inFile.is_open()) {
          std::cerr << "Error: \"" << fileName << "\" could not be found or opened." << std::endl;
          return false;
     }
     else {
          json jsonTasks;

          try {
               inFile >> jsonTasks;
          }
          catch (const json::parse_error& e) {
               std::cerr << "Parse error: " << e.what() << std::endl << std::endl;
               return false;
          }
          catch (const std::exception& e) {
               std::cerr << "Error: " << e.what() << std::endl << std::endl;
               return false;
          }

          vectorOfTasks.clear();
          for (const auto& jsonTask : jsonTasks) {
               Task task;
               from_json(jsonTask, task);
               vectorOfTasks.push_back(task);
          }
     }
     return true;
}

bool saveToFile(const std::vector<Task>& vectorOfTasks, const std::string& fileName) {
     std::ofstream outFile(fileName);

     if (!outFile.is_open())
     {
          std::cerr << "Error: \"" << fileName << "\" could not be found or opened." << std::endl;
          return false;
     }
     else {
          json jsonTasks = json::array();

          for (unsigned int i = 0; i < vectorOfTasks.size(); i++) {
               json j;
               to_json(j, vectorOfTasks.at(i));
               jsonTasks.push_back(j);
          }

          outFile << jsonTasks.dump(4);
          outFile.close();
     }
     return true;
}
#endif
