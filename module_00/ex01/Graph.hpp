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
  void add_point(const Vector2&);
  void print_to_screen();
  const Vector2& get_size() const;
private:
  Vector2 size;
  vector<Vector2> points;
};


#endif //EX01_GRAPH_HPP
