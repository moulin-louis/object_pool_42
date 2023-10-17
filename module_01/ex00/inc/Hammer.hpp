//
// Created by llr on 10/17/23.
//
#ifndef EX00_HAMMER_HPP
#define EX00_HAMMER_HPP

#include "Tool.hpp"
#include <iostream>

using namespace std;

class Hammer : protected Tool {
public:
  virtual void use();
};


#endif //EX00_HAMMER_HPP
