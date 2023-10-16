//
// Created by loumouli on 10/16/23.
//

#include "Bank.hpp"

Bank::Bank() {
  this->liquidity = 0;
  this->nbr_of_client = 0;
}

Bank::~Bank() {
  cout << "LOG: Bank deleted" << endl;
  for (std::vector<Account *>::iterator it = this->clientAccounts.begin(); it != this->clientAccounts.end(); it++) {
    delete *it;
  }
}

std::ostream &operator<<(std::ostream &p_os, const Bank &p_bank) {
  p_os << "Bank informations : " << std::endl;
  p_os << "Liquidity : " << p_bank.liquidity << std::endl;
  for (std::vector<Account *>::const_iterator clientAccount = p_bank.clientAccounts.begin();
       clientAccount != p_bank.clientAccounts.end();
       ++clientAccount)
    p_os << **clientAccount << std::endl;
  return (p_os);
}

void Bank::create_account(int initial_value) {
  if (initial_value < 0) {
    cout << "ERROR: Negative value in create_account" << endl;
    return;
  }
  Account *new_account = new Account;
  new_account->value = initial_value;
  this->clientAccounts.push_back(new_account);
  new_account->id = this->nbr_of_client;
  this->nbr_of_client++;
}

void Bank::delete_account(int id) {
  for (std::vector<Account *>::iterator it = this->clientAccounts.begin(); it != this->clientAccounts.end(); it++) {
    if ((*it)->id == id) {
      delete *it;
      this->clientAccounts.erase(it);
      return;
    }
  }
  cout << "WARN: Invalid ID in delete_account" << endl;
}

void Bank::deposit(int id, int value) {
  if (value < 0) {
    cout << "ERROR: Negative value in deposit" << endl;
    return;
  }
  for (std::vector<Account *>::iterator it = this->clientAccounts.begin(); it != this->clientAccounts.end(); it++) {
    if ((*it)->id == id) {
      int fees = (int)((double)value * 0.05);
      (*it)->value += value - fees;
      this->liquidity += fees;
      return;
    }
  }
  cout << "WARN: Invalid ID in deposit" << endl;
}

void Bank::withdraw(int id, int value) {
   if (value < 0) {
     cout << "ERROR: Negative value in withdraw" << endl;
     return;
   }
  for (std::vector<Account *>::iterator it = this->clientAccounts.begin(); it != this->clientAccounts.end(); it++) {
    if ((*it)->id == id) {
      (*it)->value -= value;
      return;
    }
  }
  cout << "WARN: Invalid ID in deposit" << endl;
}

void Bank::take_loan(int id, int value_loan) {
  if (value_loan < 0) {
    cout << "ERROR: Negative value in take_loan" << endl;
    return;
  }
  if (value_loan > this->liquidity) {
    cout << "WARN: Liquidity too low in take_loan" << endl;
    return;
  }
  for (std::vector<Account *>::iterator it = this->clientAccounts.begin(); it != this->clientAccounts.end(); it++) {
    if ((*it)->id == id) {
      this->liquidity -= value_loan;
      (*it)->value += value_loan;
      return;
    }
  }
  cout << "WARN: Invalid ID in take_load" << endl;
}
