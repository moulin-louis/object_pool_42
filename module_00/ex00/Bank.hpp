//
// Created by loumouli on 10/16/23.
//
#ifndef MODULE_00_BANK_HPP
#define MODULE_00_BANK_HPP

#include <iostream>
#include <exception>
#include <map>

using namespace std;

struct Bank {
  struct Account {
  public:
    const int &get_value() const {
      return this->value;
    };
  private:
    friend struct Bank;
    int id;
    int value;

    Account() {
      this->id = -1;
      this->value = 0;
    };

    friend ostream &operator<<(std::ostream &p_os, const Account &p_account) {
      p_os << "[" << p_account.id << "] - [" << p_account.value << "]";
      return (p_os);
    };
  };

public:
  Bank();

  ~Bank();

  friend ostream &operator<<(std::ostream &, const Bank &);
  const Bank::Account& operator[](int id);
  void create_account(int);

  void delete_account(int);

  void deposit(int, int);

  void withdraw(int, int);

  void take_loan(int, int);

  const int &get_liquidity() const;

private:
  int liquidity;
  std::map<int, Account *> clientAccounts;
  int nbr_of_client;
};

#endif //MODULE_00_BANK_HPP
