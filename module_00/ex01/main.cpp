#include "Graph.hpp"

int main() {
  Graph graph;
  graph.add_point(0.0, 0.0);
  Vector2 tmp_point = Vector2(2.0, 2.0);
  graph.add_point(tmp_point);
  graph.add_point(4.0, 2.0);
  graph.add_point(2.0, 4.0);
  const Vector2 &size = graph.get_size();
  cout << "size x = " << size.get_x() << endl;
  cout << "size y = " << size.get_y() << endl;
  vector<Vector2> tmp_points = graph.get_points();
  tmp_points.push_back(Vector2(15.0,15.0));
  cout << "size x = " << size.get_x() << endl;
  cout << "size y = " << size.get_y() << endl;
  graph.print_to_screen();
  return 0;
}
