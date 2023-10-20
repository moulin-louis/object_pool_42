//
// Created by loumouli on 10/20/23.
//

#include <vector>
#include <string>
using namespace std;

#include "ILogger.hpp"
#include "FileLogger.hpp"
#include "SimpleLogger.hpp"

int main() {
  vector<ILogger *> loggers;
  vector<string>  to_write;

  to_write.push_back("Hello ex04");
  to_write.push_back("Hello 42");
  to_write.push_back("Hello toto");

  UserFileLogger<string> userFileLogger("/dev/stdout");
  ManagedFileLogger<string> managedFileLogger;
  SimpleLogger simpleLogger;
  userFileLogger.change_header("userFileLogger");
  managedFileLogger.change_header("manageFileLogger");

  loggers.push_back(&userFileLogger);
  loggers.push_back(&managedFileLogger);
  loggers.push_back(&simpleLogger);
  for (vector<string>::iterator it = to_write.begin(); it != to_write.end(); it++) {
    for (vector<ILogger *>::iterator it2 = loggers.begin(); it2 != loggers.end(); it2++) {
      (*it2)->write((*it));
    }
  }
  return 0;
}
