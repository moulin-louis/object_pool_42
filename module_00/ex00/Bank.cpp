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
  for (map<int, Account*>::iterator it = this->clientAccounts.begin();
       it != this->clientAccounts.end(); ++it) {
    delete it->second;
  }
}

std::ostream& operator<<(std::ostream& p_os, const Bank& p_bank) {
  p_os << "Bank information's : " << std::endl;
  p_os << "Liquidity : " << p_bank.liquidity << std::endl;
  for (map<int, Bank::Account*>::const_iterator clientAccount = p_bank.clientAccounts.begin();
       clientAccount != p_bank.clientAccounts.end();
       ++clientAccount)
    p_os << *clientAccount->second << std::endl;
  return (p_os);
}

void Bank::create_account(const int initial_value) {
  if (initial_value < 0)
    throw runtime_error("Negative value in create_account");
  Account* new_account = new Account;
  new_account->value = initial_value;
  this->clientAccounts.insert(pair<int, Account*>(this->nbr_of_client, new_account));
  new_account->id = this->nbr_of_client;
  this->nbr_of_client++;
}

void Bank::delete_account(const int id) {
  for (map<int, Account*>::iterator it = this->clientAccounts.begin(); it != this->clientAccounts.end(); ++it) {
    if (it->second->id == id) {
      delete it->second;
      this->clientAccounts.erase(it);
      return;
    }
  }
  throw runtime_error("Invalid ID in delete_account");
}

void Bank::deposit(const int id, const int value) {
  if (value < 0)
    throw runtime_error("Negative value in deposit");
  for (map<int, Account*>::iterator it = this->clientAccounts.begin(); it != this->clientAccounts.end(); ++it) {
    if (it->second->id == id) {
      const int fees = (int)((double)value * 0.05);
      it->second->value += value - fees;
      this->liquidity += fees;
      return;
    }
  }
  throw runtime_error("Invalid ID in deposit");
}

void Bank::withdraw(const int id, const int value) {
  if (value < 0)
    throw runtime_error("Negative value in withdraw");
  for (map<int, Account*>::iterator it = this->clientAccounts.begin(); it != this->clientAccounts.end(); ++it) {
    if (it->second->id == id) {
      it->second->value -= value;
      return;
    }
  }
  throw runtime_error("Invalid ID in withdraw");
}

void Bank::take_loan(int id, int value_loan) {
  if (value_loan < 0)
    throw runtime_error("Negative value in take_loan");
  if (value_loan > this->liquidity)
    throw runtime_error("Liquidity too low in take_loan");
  for (map<int, Account*>::iterator it = this->clientAccounts.begin(); it != this->clientAccounts.end(); ++it) {
    if (it->second->id == id) {
      this->liquidity -= value_loan;
      it->second->value += value_loan;
      return;
    }
  }
  throw runtime_error("Invalid ID in take_loan");
}

const int& Bank::get_liquidity() const {
  return this->liquidity;
}

const Bank::Account& Bank::operator[](const int id) {
  if (this->clientAccounts.find(id) == this->clientAccounts.end())
    throw runtime_error("Invalid ID in operator[]");
  return *this->clientAccounts[id];
}
