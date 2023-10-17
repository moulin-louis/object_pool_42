//
// Created by loumouli on 10/16/23.
//
#ifndef MODULE_00_BANK_HPP
#define MODULE_00_BANK_HPP

#include <iostream>
#include <vector>
#include "Account.hpp"

struct Account;
using namespace std;

struct Bank {
public:
  Bank();
  ~Bank();
  friend std::ostream &operator<<(std::ostream&, const Bank &);
  void create_account(int);
  void delete_account(int);
  void deposit(int, int);
  void withdraw(int, int);
  void take_loan(int, int);
  const int& get_liquidity();
private:
  int liquidity;
  std::vector<Account *> clientAccounts;
  int nbr_of_client;
};

#endif //MODULE_00_BANK_HPP
