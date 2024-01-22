//
// Created by llr on 10/18/23.
//
#include "../inc/SpeedControl.hpp"

SpeedControl::SpeedControl() {
  cout << "SpeedControl: created" << endl;
}

void SpeedControl::apply_force_on_brakes(float force) {
  cout << "SpeedControl: " << force << " force applied to brakes" << endl;
}

void SpeedControl::apply_emergency_brakes() {
  cout << "SpeedControl: emergency brakes applied" << endl;
}

void SpeedControl::accelerate(float speed) {
  cout << "SpeedControl: acceleration of " << speed << endl;
}
