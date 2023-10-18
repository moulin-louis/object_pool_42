//
// Created by loumouli on 10/17/23.
//
#ifndef EX00_WORKER_HPP
#define EX00_WORKER_HPP

// #include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>

#include "Position.hpp"
#include "Statistic.hpp"
#include "Tool.hpp"

class Tool;
using namespace std;

class Worker {
public:
  Worker();
  ~Worker();
  void add_tool(Tool *);
  void remove_tool(Tool *);
  friend ostream &operator<<(ostream &, const Worker &);
private:

  Position position;
  Statistic statistic;
  vector<Tool *> tools;
};


#endif //EX00_WORKER_HPP
