//
// Created by loumouli on 10/16/23.
//
#ifndef EX01_VECTOR2_HPP
#define EX01_VECTOR2_HPP

#include "Graph.hpp"

class Graph;

class Vector2 {
public:
  Vector2(float, float);
  const float& get_x() const;
  const float& get_y() const;
private:
  friend struct Graph;
  float x;
  float y;
};

#endif //EX01_VECTOR2_HPP
