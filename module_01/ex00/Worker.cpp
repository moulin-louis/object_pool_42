//
// Created by loumouli on 10/17/23.
//

#include "Worker.hpp"

Worker::Worker() {
  this->shovel = nullptr;
}

Worker::add_shovel(Shovel *shovel_to_add) {
  this->shovel = shovel_to_add;
}

Worker::remove_shovel() {
  this->shovel = nullptr;
}