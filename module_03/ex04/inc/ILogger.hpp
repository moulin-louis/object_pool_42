//
// Created by loumouli on 10/20/23.
//
#ifndef EX04_ILOGGER_HPP
#define EX04_ILOGGER_HPP

#include <string>

using namespace std;

class ILogger {
public:
  virtual void write(string) = 0;
};

#endif //EX04_ILOGGER_HPP
