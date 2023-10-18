//
// Created by llr on 10/18/23.
//

#include "Circle.hpp"
#include "Rectangle.hpp"
#include "Triangle.hpp"
#include "Shape.hpp"

void display_area_perimiter(Shape *shape) {
  cout << "area: " << shape->calculate_area() << endl;
  cout << "perimiter: " << shape->calculate_perimiter() << endl;
}

int main(void) {
  {
    float sides[3];
    sides[0] = 2.0;
    sides[1] = 4.0;
    sides[2] = 5.0;
    Triangle trg(sides);
    display_area_perimiter(&trg);
  }
  {
    Circle crl(10.0);
    display_area_perimiter(&crl);
  }
  {
    float lens[2];
    lens[0] = 4.5;
    lens[1] = 4.9;
    Rectangle rctgl(lens);
    display_area_perimiter(&rctgl);
  }
  return 0;
}