//
// Created by loumouli on 10/17/23.
//
#ifndef EX00_WORKER_HPP
#define EX00_WORKER_HPP

#include "Position.hpp"
#include "Statistic.hpp"
#include "Shovel.hpp"

class Worker {
public:
  Position position;
  Statistic statistic;
  Shovel *shovel;
  void add_shovel(Shovel *);
};


#endif //EX00_WORKER_HPP
