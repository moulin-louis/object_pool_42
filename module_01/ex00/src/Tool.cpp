//
// Created by llr on 10/17/23.
//

#include "../inc/Tool.hpp"

void Tool::remove_owner() {
    if (this->owner)
        ((Worker*)this->owner)->remove_tool(this);
    this->owner = NULL;
}

void Tool::add_owner(const Worker* new_owner) {
    cout << "Tool: Add new owner" << endl;
    if (!new_owner)
        return;
    this->owner = new_owner;
}

const Worker *& Tool::get_owner() {
    return this->owner;
}