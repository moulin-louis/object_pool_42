//
// Created by llr on 10/19/23.
//

#include "EmployeeManager.hpp"
#include "ContractWorker.hpp"
#include "TempWorker.hpp"
#include "Apprentice.hpp"

int main() {
  EmployeeManager manager;
  ContractWorker c_worker;
  TempWorker  t_worker;
  Apprentice a_worker;
  manager.addEmployee(&c_worker);
  manager.addEmployee(&t_worker);
  manager.addEmployee(&a_worker);
  return 0;
}