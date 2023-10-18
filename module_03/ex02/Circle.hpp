//
// Created by llr on 10/18/23.
//

#ifndef EX02_CIRCLE_HPP
#define EX02_CIRCLE_HPP

#include <cmath>
#include <iostream>
#include "Shape.hpp"

using namespace std;

class Circle : virtual public Shape {
public:
  explicit Circle(float);

  virtual float calculate_area();

  virtual float calculate_perimiter();

private:
  float rayon;
};

Circle::Circle(float u_rayon) {
  this->rayon = u_rayon;
}

float Circle::calculate_area() {
  if (this->rayon < 0) {
    cout << "Invalid rayon" << endl;
    return -1.0;
  }
  return M_PI * (this->rayon * this->rayon);
}

float Circle::calculate_perimiter() {
  if (this->rayon < 0) {
    cout << "Invalid rayon" << endl;
    return -1.0;
  }
  return (float)(2.0 * M_PI * this->rayon);
}


#endif //EX02_CIRCLE_HPP
