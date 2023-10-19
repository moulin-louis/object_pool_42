//
// Created by llr on 10/19/23.
//

#ifndef EX03_CONTRACTWORKER_HPP
#define EX03_CONTRACTWORKER_HPP

#include "Employee.hpp"

class ContractWorker : virtual public Employee {
public:
  int executeWorkday() {
    return 0;
  };
};


#endif //EX03_CONTRACTWORKER_HPP
