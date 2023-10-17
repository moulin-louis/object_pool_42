//
// Created by loumouli on 10/16/23.
//

#include "Account.hpp"

Account::Account() {
  this->id = -1;
  this->value = 0;
}

std::ostream &operator<<(std::ostream &p_os, const Account &p_account) {
  p_os << "[" << p_account.id << "] - [" << p_account.value << "]";
  return (p_os);
}

const int &Account::get_value() {
  return this->value;
}

