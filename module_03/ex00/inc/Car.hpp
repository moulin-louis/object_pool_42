//
// Created by llr on 10/18/23.
//
#ifndef EX00_CAR_HPP
#define EX00_CAR_HPP

#include "Engine.hpp"
#include "Gears.hpp"
#include "SpeedControl.hpp"
#include "Wheels.hpp"

class Car : public Engine, public Gears, public Wheels, public SpeedControl {
public:
  Car();

  ~Car();
};

#endif //EX00_CAR_HPP
