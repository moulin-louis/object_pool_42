//
// Created by loumouli on 10/16/23.
//

#ifndef MODULE_00_ACCOUNT_HPP
#define MODULE_00_ACCOUNT_HPP

#include <iostream>
#include "Bank.hpp"

struct Bank;

struct Account {
private:
  int id;
  int value;
  Account();
  friend struct Bank;
  friend std::ostream &operator<<(std::ostream &, const Account &);
};

#endif //MODULE_00_ACCOUNT_HPP
