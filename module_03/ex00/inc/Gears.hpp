//
// Created by llr on 10/18/23.
//
#ifndef EX00_GEARS_HPP
#define EX00_GEARS_HPP

#include <iostream>

using namespace std;

class Gears {
protected:
  Gears();

public:
  void shift_gears_up();

  void shift_gears_down();

  void reverse();
};

#endif //EX00_GEARS_HPP
