//
// Created by loumouli on 10/17/23.
//
#ifndef EX00_HAMMER_HPP
#define EX00_HAMMER_HPP

#include <iostream>

#include "Tool.hpp"

class Hammer : public Tool {
public:
  Hammer();
  virtual void use();
};


#endif //EX00_HAMMER_HPP
