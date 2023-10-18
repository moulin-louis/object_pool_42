//
// Created by loumouli on 10/17/23.
//

#include "../inc/Shovel.hpp"

Shovel::Shovel() {
  this->numberOfUses = 0;
  this->owner = NULL;
  cout << "Shovel: Creating..." << endl;
}
void Shovel::use() {
  cout << "Shovel:USING SHOOOVEEELL" << endl;
  this->numberOfUses += 1;
}

Shovel::~Shovel() {
  cout << "Shovel: Destructing..." << endl;
}
