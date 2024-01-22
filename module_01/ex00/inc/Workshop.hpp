//
// Created by llr on 10/18/23.
//
#ifndef EX00_WORKSHOP_HPP
#define EX00_WORKSHOP_HPP

#include <vector>

#include "Worker.hpp"

class Workshop {
public:
  void executeWorkDay();
  void register_workshop(Worker*);
  void leave(const Worker*);

private:
  vector<Worker*> register_worker;
};

#endif //EX00_WORKSHOP_HPP
