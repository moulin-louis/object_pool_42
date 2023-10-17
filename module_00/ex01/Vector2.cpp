//
// Created by loumouli on 10/16/23.
//

#include "Vector2.hpp"

Vector2::Vector2(float ux, float uy) {
  this->x = ux;
  this->y = uy;
}

const float& Vector2::get_x() const {
  return this->x;
}

const float &Vector2::get_y() const {
  return this->y;
}
