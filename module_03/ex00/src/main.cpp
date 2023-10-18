//
// Created by llr on 10/18/23.
//

#include "../inc/Car.hpp"

int main() {
  Car car;
  car.accelerate(10.2);
  car.shift_gears_up();
  car.shift_gears_down();
  car.reverse();
  car.turn_wheel(-5.4);
  car.straighten_wheels();
  car.apply_force_on__brakes(42.0);
  car.apply_emergency_brakes();
  return 0;
}