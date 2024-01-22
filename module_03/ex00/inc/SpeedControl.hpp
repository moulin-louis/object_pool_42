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
  static void apply_force_on_brakes(float force);

  static void apply_emergency_brakes();

  static void accelerate(float speed);
};

#endif //EX00_SPEEDCONTROL_HPP
