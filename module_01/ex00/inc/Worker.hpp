//
// Created by loumouli on 10/17/23.
//
#ifndef EX00_WORKER_HPP
#define EX00_WORKER_HPP

#include <cstring>
#include <iostream>

#include "Position.hpp"
#include "Statistic.hpp"
#include "Shovel.hpp"

using namespace std;
class Shovel;

class Worker {
public:
  Worker();
  ~Worker();
  void add_shovel(Shovel *);
  void remove_shovel();
  friend ostream &operator<<(ostream &, const Worker &);
private:
  Position position;
  Statistic statistic;
  Shovel *shovel;
};


#endif //EX00_WORKER_HPP
