//
// Created by loumouli on 10/19/23.
//

#include "EmployeeManager.hpp"
#include "hourlyEmployee.hpp"
#include "salariedEmployee.hpp"

int main() {
  EmployeeManager manager;
  ContractWorker c_worker;
  TempWorker  t_worker;
  Apprentice a_worker;

  manager.addEmployee(&c_worker);
  manager.addEmployee(&t_worker);
  manager.addEmployee(&a_worker);
  t_worker.mobilize(217);
  c_worker.rest(5 * 7);
  a_worker.rest(15);
  manager.calculatePayroll();
  return 0;
}