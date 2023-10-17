//
// Created by loumouli on 10/16/23.
//
#ifndef EX01_GRAPH_HPP
#define EX01_GRAPH_HPP

#include <iostream>
#include <vector>
#include <cstring>
#include "Vector2.hpp"

class Vector2;
using namespace std;

class Graph {
public:
  Graph();
  ~Graph();
  void add_point(float, float);
  void add_point(Vector2&);
  void print_to_screen();
  const Vector2& get_size();
  const vector<Vector2>& get_points();
private:
  Vector2 *size;
  vector<Vector2> points;
  char *canvas;
};


#endif //EX01_GRAPH_HPP
