#include "Bank.hpp"

using namespace std;

int main() {
  Bank bank = Bank();
  try {

    bank.create_account(100);
    bank.create_account(100);
    cout << bank << endl;
    bank.delete_account(1);
    cout << bank << endl;
    bank.deposit(0, 100);
    try {
      bank.withdraw(2, 5);
    } catch (exception& e) {
      cout << "ERROR: " << e.what() << endl;
    }
    cout << bank << endl;
    cout << bank << endl;
    for (int i = 0; i < 10; i++) {
      bank.deposit(0, 10000);
    }
    cout << bank.get_liquidity() << endl;
    bank.take_loan(0, 4500);
    cout << bank << endl;
    cout << "value of client 0 = " << bank[0].get_value() << endl;
  } catch (exception& e) {
    cout << "ERROR: " << e.what() << endl;
    return 1;
  }
  return (0);
}
