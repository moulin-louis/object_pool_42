//
// Created by llr on 10/18/23.
//
#ifndef EX00_SPEEDCONTROL_HPP
#define EX00_SPEEDCONTROL_HPP

#include <iostream>

using namespace std;

class SpeedControl {
protected:
  SpeedControl();

public:
  void apply_force_on__brakes(float force);

  void apply_emergency_brakes();

  void accelerate(float speed);
};

#endif //EX00_SPEEDCONTROL_HPP
