//
// Created by llr on 10/17/23.
//

#include "../inc/Hammer.hpp"

Hammer::Hammer() {
  cout << "Hamer: Creating..." << endl;
  this->numberOfUses = 0;
  this->owner = NULL;
}

void Hammer::use() {
  cout << "Hammer: USING HAMMMMMEEEER " << endl;
  this->numberOfUses += 1;
}

Hammer::~Hammer() {
  cout << "Hammer: destructring..." << endl;
}