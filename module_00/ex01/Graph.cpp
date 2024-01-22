//
// Created by loumouli on 10/16/23.
//

#include "Graph.hpp"

Graph::Graph(): size(0.0, 0.0) { }

void Graph::add_point(const Vector2& point) {
  if (point.x < 0.0 || point.y < 0.0) {
    cout << "Negative number, wont add this one..." << endl;
    return;
  }
  if (point.x > this->size.x)
    this->size.x = point.x + 1;
  if (point.y > this->size.y)
    this->size.y = point.y + 1;
  this->points.push_back(point);
}

void Graph::print_to_screen() {
  const int sx = (int)this->size.get_x();
  const int sy = (int)this->size.get_y();

  char *canvas = new char[sx * sy];
  memset(canvas, '.', sx * sy);
  for (vector<Vector2>::iterator it = this->points.begin(); it != this->points.end(); ++it)
    canvas[(int)it->x * sx + (int)it->y] = 'X';
  for (int y = sy - 1; y >= 0; --y) {
    for (int x = 0; x < sx; x++)
      cout << canvas[y * sy + x];
    cout << endl;
  }
  this->size.x = 0.0;
  this->size.y = 0.0;
  this->points.clear();
  delete[] canvas;
}

const Vector2& Graph::get_size() const { return this->size; }
