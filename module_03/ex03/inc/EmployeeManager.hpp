//
// Created by loumouli on 10/19/23.
//
#ifndef EX03_EMPLOYEEMANAGER_HPP
#define EX03_EMPLOYEEMANAGER_HPP

#include <vector>
#include <map>
#include <iostream>
#include <algorithm>

#include "Employee.hpp"

using namespace std;

class EmployeeManager {
private:
  map<Employee *, int> hours_work;
  vector<Employee *> employees;
public:
  void addEmployee(Employee *employee) {
    if (!employee)
      return;
    this->hours_work.insert(pair<Employee *, int>(employee, 0));
    this->employees.push_back(employee);
  };

  void removeEmployee(Employee *employee) {
    vector<Employee *>::iterator it = std::find(this->employees.begin(), this->employees.end(), employee);
    if (it == this->employees.end()) {
      return;
    }
    this->hours_work.erase(employee);
    this->employees.erase(it);
  };

  void executeWorkday() {
    for (vector<Employee *>::iterator it = this->employees.begin(); it != this->employees.end(); it++) {
      (*it)->executeWorkday();
    }
  };

  void calculatePayroll() {
    unsigned int result = 0;
    for (unsigned int i = 0; i < 31; i++) {
      for (vector<Employee *>::iterator it = this->employees.begin(); it != this->employees.end(); it++) {
        (*it)->executeWorkday();
      }
    }
    for (vector<Employee *>::iterator it = this->employees.begin(); it != this->employees.end(); it++) {
      result += (*it)->calculate_salary();
    }
    cout << "This month payroll = " << result << endl;
  };
};

#endif //EX03_EMPLOYEEMANAGER_HPP
