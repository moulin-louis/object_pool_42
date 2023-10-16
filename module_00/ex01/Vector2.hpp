//
// Created by loumouli on 10/16/23.
//

#ifndef EX01_VECTOR2_HPP
#define EX01_VECTOR2_HPP

#include "Graph.hpp"
using namespace std;

class Graph;

class Vector2 {
private:
  friend struct Graph;
  Vector2(float, float);
  float x;
  float y;
};


#endif //EX01_VECTOR2_HPP
