#include "Bank.hpp"

using namespace std;

int main() {
  Bank bank = Bank();
  try {
    cout << "Creating 2 account..." << endl;
    bank.create_account(100);
    bank.create_account(100);
    cout << bank << endl;
    cout << "Deleting one account..." << endl;
    bank.delete_account(1);
    cout << bank << endl;
    cout << "Depositing 100 to account 0..." << endl;
    bank.deposit(0, 100);
    cout << bank << endl;
    try {
      cout << "Trying to withdraw from invalid ID..." << endl;
      bank.withdraw(2, 5);
    }
    catch (exception& e) {
      cout << "ERROR: " << e.what() << endl;
    }
    cout << endl;
    cout << "Making a big deposit in account 0" << endl;
    for (int i = 0; i < 10; i++) {
      bank.deposit(0, 10000);
    }
    cout << "Bank liquidity is..." << endl;
    cout << bank.get_liquidity() << endl << endl;
    const int tmp = bank[0].get_value();
    bank.take_loan(0, 4500);
    cout << bank << endl;
    cout << "value of client 0 before loan = " << tmp << endl;
    cout << "value of client 0 after loan = " << bank[0].get_value() << endl;
  }
  catch (exception& e) {
    cout << "ERROR: " << e.what() << endl;
    return 1;
  }
  return (0);
}
