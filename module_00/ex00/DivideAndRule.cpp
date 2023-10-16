#include <iostream>
#include <vector>
using namespace std;

struct Account {
private:
  int id;
  int value;
  Account() {
    this->id = -1;
    this->value = 0;
  };
  friend struct Bank;
  friend std::ostream &operator<<(std::ostream &p_os, const Account &p_account) {
    p_os << "[" << p_account.id << "] - [" << p_account.value << "]";
    return (p_os);
  }
};

struct Bank {
private:
  int liquidity;
  std::vector<Account *> clientAccounts;
  int nbr_of_client;
public:
  Bank() {
    this->liquidity = 0;
    this->nbr_of_client = 0;
  };
  ~Bank() {
    cout << "LOG: Bank deleted" << endl;
    for (std::vector<Account *>::iterator it = this->clientAccounts.begin(); it != this->clientAccounts.end(); it++) {
      delete *it;
    }
  };
  friend std::ostream &operator<<(std::ostream &p_os, const Bank &p_bank) {
    p_os << "Bank informations : " << std::endl;
    p_os << "Liquidity : " << p_bank.liquidity << std::endl;
    for (std::vector<Account *>::const_iterator clientAccount = p_bank.clientAccounts.begin();
         clientAccount != p_bank.clientAccounts.end();
         ++clientAccount)
      p_os << **clientAccount << std::endl;
    return (p_os);
  };
  void create_account(int initial_value) {
    if (initial_value < 0) {
      cout << "ERROR: Negative value in create_account" << endl;
      return;
    }
    Account *new_account = new Account;
    new_account->value = initial_value;
    this->clientAccounts.push_back(new_account);
    new_account->id = this->nbr_of_client;
    this->nbr_of_client++;
  };
  void delete_account(int id) {
    for (std::vector<Account *>::iterator it = this->clientAccounts.begin(); it != this->clientAccounts.end(); it++) {
      if ((*it)->id == id) {
        delete *it;
        this->clientAccounts.erase(it);
        return;
      }
    }
    cout << "WARN: Invalid ID in delete_account" << endl;
  };
  void deposit(int id, int value) {
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
  };
  void withdraw(int id, int value) {
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
  void take_loan(int id, int value_loan) {
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
};

int main() {
  Bank bank = Bank();

  bank.create_account(100);
  bank.create_account(100);
  cout << bank << endl;
  bank.delete_account(1);
  cout << bank << endl;
  bank.deposit(2, 100);
  cout << bank << endl;
  bank.withdraw(2, 5);
  cout << bank << endl;
  for (int i = 0; i < 10; i++) {
    bank.deposit(2, 10000);
  }
  cout << bank << endl;
  bank.take_loan(2, 4500);
  cout << bank << endl;
  return (0);
}