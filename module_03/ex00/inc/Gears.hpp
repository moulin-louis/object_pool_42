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
  static void shift_gears_up();

  static void shift_gears_down();

  static void reverse();
};

#endif //EX00_GEARS_HPP
