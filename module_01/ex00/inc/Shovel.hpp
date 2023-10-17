//
// Created by loumouli on 10/17/23.
//

#ifndef EX00_SHOVEL_HPP
#define EX00_SHOVEL_HPP
#include "Worker.hpp"
#include "Tool.hpp"

#include <iostream>
#include <sys/types.h>


class Worker;

class Shovel : protected Tool{
public:
  Shovel();
  void  add_fist(const Worker *);
  void  remove_fist();
  virtual void use();
private:
  const Worker *fist;
};


#endif //EX00_SHOVEL_HPP
