//
// Created by loumouli on 10/17/23.
//

#include "../inc/Worker.hpp"

Worker::Worker() : position(), statistic() {
  cout << "Worker: creating..." << endl;
}

void Worker::add_tool(Tool *tool) {
  cout << "Worker: add shovel to fist" << endl;
  if (!tool)
    return;
  if (tool->get_owner() != NULL)
    tool->remove_owner();
  tool->add_owner(this);
  this->tools.push_back(tool);
}

void Worker::remove_tool(Tool *tool) {
  cout << "Worker: removing tool from equiped tools" << endl;
  if (!tool)
    return;
  vector<Tool*>::iterator it = std::find(this->tools.begin(), this->tools.end(), tool);
  if (it == this->tools.end()) {
    cout << "Worker: Cant find the tool to remove" << endl;
    return;
  }
  (*it)->remove_owner();
  this->tools.erase(it);
}

ostream &operator<<(ostream &os, const Worker &worker) {
  os << "Number of tools: " << worker.tools.size() << endl;
  return os;
}

Worker::~Worker() {
  for (vector<Tool *>::iterator it = this->tools.begin(); it != this->tools.end(); it++) {
    // (*it)->remove_owner();
  }
}
