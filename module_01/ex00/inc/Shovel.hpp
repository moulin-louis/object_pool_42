//
// Created by loumouli on 10/17/23.
//
#ifndef EX00_SHOVEL_HPP
#define EX00_SHOVEL_HPP

#include <iostream>

#include "Tool.hpp"

class Shovel : public Tool {
public:
  Shovel();
  virtual void use();
};


#endif //EX00_SHOVEL_HPP
