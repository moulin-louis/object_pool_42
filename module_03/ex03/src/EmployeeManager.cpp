//
// Created by llr on 10/19/23.
//

#include "EmployeeManager.hpp"

void EmployeeManager::addEmployee(Employee *employee) {
  if (!employee)
    return;
  this->hours_work.insert(pair<Employee *, int>(employee, 0));
  this->employees.push_back(employee);
}

void EmployeeManager::removeEmployee(Employee *employee) {
  vector<Employee *>::iterator it = std::find(this->employees.begin(), this->employees.end(), employee);
  if (it == this->employees.end()) {
    return;
  }
  this->hours_work.erase(employee);
  this->employees.erase(it);
}

void EmployeeManager::executeWorkday() {
  if (this->days == 31)
    this->days = 0;
  else
    this->days += 1;
  for (vector<Employee *>::iterator it = this->employees.begin(); it != this->employees.end(); it++) {
    (*it)->executeWorkday();
    this->hours_work[*it] += 7;
  }
}

void EmployeeManager::calculatePayroll() {
  int result = 0;
  if (this->days != 31) {
    cout << "A month haven't passed yet" << endl;
  }
  for (vector<Employee *>::iterator it = this->employees.begin(); it != this->employees.end(); it++) {
    result += this->hours_work[*it] * (*it)->get_hourlyValue();
  }
  cout << "This month payroll = " << result << endl;
}

EmployeeManager::~EmployeeManager() {
}
