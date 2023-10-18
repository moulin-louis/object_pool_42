//
// Created by llr on 10/17/23.
//

#include "../inc/Hammer.hpp"

Hammer::Hammer() {
  cout << "Hamer: Creating..." << endl;
  this->numberOfUses = 0;
  this->owner = 0;
}

void Hammer::use() {
  cout << "USING HAMMMMMEEEER " << endl;
  this->numberOfUses += 1;
}
