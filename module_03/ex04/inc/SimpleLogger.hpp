//
// Created by loumouli on 10/20/23.
//
#ifndef EX04_SIMPLELOGGER_HPP
#define EX04_SIMPLELOGGER_HPP

#include <iostream>
#include "ILogger.hpp"

using namespace std;

class SimpleLogger : virtual public ILogger {
public:
  virtual void write(string input) { cout << input << endl; };
};

#endif //EX04_SIMPLELOGGER_HPP
