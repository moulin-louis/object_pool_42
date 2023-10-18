//
// Created by llr on 10/18/23.
//
#ifndef EX00_WHEELS_HPP
#define EX00_WHEELS_HPP

#include <iostream>

using namespace std;

class Wheels {
protected:
  Wheels();

public:
  void turn_wheel(float angle);

  void straighten_wheels();
};

#endif //EX00_WHEELS_HPP
