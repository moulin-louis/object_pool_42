#include "Graph.hpp"

int main() {
  Graph graph;
  const Vector2 tmp_point = Vector2(0.0, 0.0);
  const Vector2 tmp_point1 = Vector2(2.0, 4.0);
  const Vector2 tmp_point2 = Vector2(4.0, 2.0);
  const Vector2 tmp_point3 = Vector2(2.0, 2.0);
  graph.add_point(tmp_point);
  graph.add_point(tmp_point1);
  graph.add_point(tmp_point2);
  graph.add_point(tmp_point3);
  const Vector2& size = graph.get_size();
  cout << "size x = " << size.get_x() << endl;
  cout << "size y = " << size.get_y() << endl;
  graph.print_to_screen();
  return 0;
}
