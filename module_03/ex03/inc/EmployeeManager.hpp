//
// Created by llr on 10/19/23.
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
  int days;
public:
  ~EmployeeManager();
  void addEmployee(Employee *);

  void removeEmployee(Employee *);

  void executeWorkday();

  void calculatePayroll();
};


#endif //EX03_EMPLOYEEMANAGER_HPP
