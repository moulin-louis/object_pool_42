//
// Created by llr on 10/18/23.
//

#include "../inc/Wheels.hpp"

Wheels::Wheels() {
  cout << "Wheels: created" << endl;
}

void Wheels::turn_wheel(float angle) {
  cout << "Wheels: turning the wheel at an angle of " << angle << endl;
}

void Wheels::straighten_wheels() {
  cout << "Wheels: returning the wheels to a straigh-ahead position" << endl;
}
