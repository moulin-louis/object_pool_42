#include "Account.hpp"
#include "Bank.hpp"
using namespace std;

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
