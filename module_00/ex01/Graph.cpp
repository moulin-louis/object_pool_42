//
// Created by loumouli on 10/16/23.
//

#include "Graph.hpp"

Graph::Graph() {
  this->canvas = new char[this->widht * this->height];
  this->size = 0;
}

void Graph::add_point(float x, float y) {
  this->size += 1;
  this->point.push_back(Vector2(x, y));
}


void Graph::print_to_screen() {
  float max_x = 0;
  float max_y = 0;
  cout << "TODO!" << endl;
}

void Graph::print_point_info() {
  int x = 0;
  for(vector<Vector2>::iterator it = this->point.begin(); it != this->point.end(); it++) {
    cout  << "[" << x << "] x: " << (*it).x << ", y: " << (*it).y << endl;
    x++;
  }
}

Graph::~Graph() {
  delete this->canvas;
}

float Graph::find_max_x() {
  float result = 0.0;
  for(vector<Vector2>::iterator it = this->point.begin(); it != this->point.end(); it++) {
    if (*it)
  }
}

