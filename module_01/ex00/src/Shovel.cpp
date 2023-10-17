//
// Created by loumouli on 10/17/23.
//

#include "Shovel.hpp"

Shovel::Shovel() {
  cout << "Shovel: Creating..." << endl;
  this->fist = NULL;
  this->numberOfUses = 0;
}

void Shovel::add_fist(const Worker *worker) {
  cout << "Shovel: adding fist to shovel" << endl;
  if (!worker)
    return;
  this->fist = worker;
}

void Shovel::remove_fist() {
  cout << "Shovel: removing fist to shovel" << endl;
  if (!this->fist)
    return;
  ((Worker *)this->fist)->remove_shovel();
  this->fist = NULL;
}

void Shovel::use() {
  cout << "USING SHOOOVEEELL" << endl;
}
