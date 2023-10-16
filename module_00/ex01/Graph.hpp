//
// Created by loumouli on 10/16/23.
//

#ifndef EX01_GRAPH_HPP
#define EX01_GRAPH_HPP
#include <iostream>
#include <vector>
#include "Vector2.hpp"

class Vector2;
using namespace std;

class Graph {
public:
  Graph();
  ~Graph();
  void add_point(float, float);
  void print_to_screen();
  void print_point_info();
private:
  int size;
  vector<Vector2> point;
  float find_max_x();
  float find_max_y();
  size_t widht = 100;
  size_t height = 100;
  char *canvas;
};


#endif //EX01_GRAPH_HPP
