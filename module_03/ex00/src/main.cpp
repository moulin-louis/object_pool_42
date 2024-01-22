//
// Created by llr on 10/18/23.
//

#include "../inc/Car.hpp"

int main() {
  Car car;
  Car::accelerate(10.2);
  Car::shift_gears_up();
  Car::shift_gears_down();
  Car::reverse();
  Car::turn_wheel(-5.4);
  Car::straighten_wheels();
  Car::apply_force_on_brakes(42.0);
  Car::apply_emergency_brakes();
  return 0;
}
