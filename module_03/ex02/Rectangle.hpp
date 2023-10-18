//
// Created by llr on 10/18/23.
//

#ifndef EX02_RECTANGLE_HPP
#define EX02_RECTANGLE_HPP

#include <iostream>
#include <cstring>
#include "Shape.hpp"

using namespace std;

class Rectangle : virtual public Shape{
public:
  explicit Rectangle(const float[2]);
  virtual float calculate_area();
  virtual float calculate_perimiter();
private:
  float lens[2];
};

Rectangle::Rectangle(const float u_lens[2]) {
  memcpy(this->lens, u_lens, 2 * sizeof(float));
}

float Rectangle::calculate_area() {
  if (this->lens[0] < 0 || this->lens[1] < 0) {
    cout << "Invalid len" << endl;
    return -1.0;
  }
  return (this->lens[0] * this->lens[1]);
}

float Rectangle::calculate_perimiter() {
  if (this->lens[0] < 0 || this->lens[1] < 0) {
    cout << "Invalid len" << endl;
    return -1.0;
  }
  return (this->lens[0] + this->lens[1]) * 2;
}


#endif //EX02_RECTANGLE_HPP
