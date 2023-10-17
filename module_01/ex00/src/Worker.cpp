//
// Created by loumouli on 10/17/23.
//

#include "Worker.hpp"

Worker::Worker() : position(), statistic() {
  cout << "Worker: creating..." << endl;
  this->shovel = NULL;
}

void Worker::add_shovel(Shovel *shovel_to_add) {
  cout << "Worker: add shovel to fist" << endl;
  if (!shovel_to_add)
    return;
  this->shovel = shovel_to_add;
  this->shovel->add_fist(this);
}

void Worker::remove_shovel() {
  cout << "Worker: removing shovel from fist" << endl;
  if (!this->shovel)
    return;
  Shovel *tmp = this->shovel;
  this->shovel = NULL;
  tmp->remove_fist();
}

ostream &operator<<(ostream &os, const Worker &worker) {
  os << "Shovel address: " << worker.shovel << endl;
  return os;
}

Worker::~Worker() {
  if (!this->shovel)
    return;
  this->shovel->remove_fist();
}
