//
// Created by llr on 10/17/23.
//
#include "../inc/Tool.hpp"

void Tool::remove_owner() {
    cout << "Tool: remove owner" << endl;
    this->owner = NULL;
}

void Tool::add_owner(const Worker* new_owner) {
    cout << "Tool: add new owner" << endl;
    this->owner = new_owner;
}

const Worker*& Tool::get_owner() {
    return this->owner;
}
