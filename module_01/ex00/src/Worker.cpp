//
// Created by loumouli on 10/17/23.
//
#include "../inc/Worker.hpp"

Worker::Worker() : coordonnee(), stat() {
  cout << "Worker: creating..." << endl;
}

Worker::~Worker() {
  cout << "Worker: destructing..." << endl;
  for (vector<Tool *>::iterator it = this->tools.begin(); it != this->tools.end(); it++) {
    (*it)->owner = NULL;
  }
}

void Worker::add_tool(Tool *tool) {
  cout << "Worker: add tool to tools list" << endl;
  if (!tool)
    return;
  Worker* owner_tool = (Worker *)tool->get_owner();
  if (owner_tool == NULL) {
    tool->add_owner(this);
  }
  else {
    owner_tool->return_tool(tool);
    tool->add_owner(this);
  }
  this->tools.push_back(tool);
}

void Worker::return_tool(Tool *tool) {
  cout << "Worker: removing tool from tools list" << endl;
  vector<Tool*>::iterator it = std::find(this->tools.begin(), this->tools.end(), tool);
  if (it == this->tools.end())
    return;
  this->tools.erase(it);
}

void Worker::remove_tool(Tool *tool) {
  if (!tool)
    return;
  // Worker* owner_tool = (Worker *)tool->get_owner();
  vector<Tool*>::iterator it = std::find(this->tools.begin(), this->tools.end(), tool);
  if (it == this->tools.end())
    return;
  tool->add_owner(NULL);
  return_tool(tool);
}

ostream &operator<<(ostream &os, const Worker &worker) {
  os << "Number of tools: " << worker.tools.size() << endl;
  return os;
}

void Worker::work() {
  cout << "Worker: im using all my tools for a workshop" << endl;
  for (vector<Tool *>::iterator it = this->tools.begin(); it != this->tools.end(); it++) {
    (*it)->use();
  }
}
