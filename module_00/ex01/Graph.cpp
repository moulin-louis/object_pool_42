//
// Created by loumouli on 10/16/23.
//

#include "Graph.hpp"

Graph::Graph() {
  this->canvas = NULL;
  this->size = new Vector2(0.0, 0.0);
}

Graph::~Graph() {
  delete this->size;
}

void Graph::add_point(float x, float y) {
  if (x > this->size->x)
    this->size->x = x + 1;
  if (y > this->size->y)
    this->size->y = y + 1;
  this->points.push_back(Vector2(x, y));
}

void Graph::add_point(Vector2 &point) {
 if (point.x > this->size->x)
   this->size->x = point.x + 1;
 if (point.y > this->size->y)
   this->size->y = point.y + 1;
 this->points.push_back(point);
}

void Graph::print_to_screen() {
  this->canvas = new char[(int)this->size->x * (int)this->size->y];
  memset(this->canvas, '0', (int)this->size->y * (int)this->size->x);
  for (vector<Vector2>::iterator it = this->points.begin(); it != this->points.end(); it++)
    this->canvas[(int)(*it).x * (int)this->size->x + (int)(*it).y] = 'X';
  for (int y = (int)this->size->y - 1; y >= 0 ; --y) {
    for (int x = 0; x < (int)this->size->x; x++)
      cout << this->canvas[y * (int)this->size->y + x];
    cout << endl;
  }
  this->size->x = 0.0;
  this->size->y = 0.0;
  this->points.clear();
  delete[] this->canvas;
}

const Vector2 &Graph::get_size() {
  return *this->size;
}

const vector<Vector2> &Graph::get_points() {
  return this->points;
}
