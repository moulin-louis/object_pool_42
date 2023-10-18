//
// Created by loumouli on 10/17/23.
//

#include "../inc/Shovel.hpp"

Shovel::Shovel() {
  this->numberOfUses = 0;
  this->owner = 0;
  cout << "Shovel: Creating..." << endl;
}
void Shovel::use() {
  cout << "USING SHOOOVEEELL" << endl;
  this->numberOfUses += 1;
}
