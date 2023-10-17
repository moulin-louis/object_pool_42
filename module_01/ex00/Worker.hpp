//
// Created by loumouli on 10/17/23.
//
#ifndef EX00_WORKER_HPP
#define EX00_WORKER_HPP

#include "Position.hpp"
#include "Statistic.hpp"
#include "Shovel.hpp"

class Worker {
  Position position;
  Statistic statistic;
  Shovel *shovel;
  Worker();
  void add_shovel(Shovel *);
  void remove_shovel();
};


#endif //EX00_WORKER_HPP
