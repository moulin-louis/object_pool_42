//
// Created by llr on 10/18/23.
//

#ifndef EX02_TRIANGLE_HPP
#define EX02_TRIANGLE_HPP

#include "Shape.hpp"

class Triangle : virtual public Shape {
public:
  explicit Triangle(const float[3]);
  virtual float calculate_area();
  virtual float calculate_perimiter();
private:
  float sides[3];
};

Triangle::Triangle(const float u_sides[3]) : sides() {
  memcpy(this->sides, u_sides, 3 * sizeof(float));
}

float Triangle::calculate_perimiter() {
  if (this->sides[0] < 0 || this->sides[1] < 0 || this->sides[2] < 0) {
    cout << "Invalid sides" << endl;
    return -1.0;
  }
  return this->sides[0] + this->sides[1] + this->sides[2];
}

float Triangle::calculate_area() {
  if (this->sides[0] < 0 || this->sides[1] < 0 || this->sides[2] < 0) {
    cout << "Invalid sides" << endl;
    return -1.0;
  }
  float semi_param = (this->sides[0] + this->sides[1] + this->sides[2]) / 2;
  semi_param = semi_param * ((semi_param - this->sides[0] * (semi_param - this->sides[1]) * (semi_param - this->sides[2])));
  return sqrt(semi_param);
}


#endif //EX02_TRIANGLE_HPP
