//
// Created by llr on 10/19/23.
//

#ifndef EX03_TEMPWORKER_HPP
#define EX03_TEMPWORKER_HPP

#include "Employee.hpp"

class TempWorker : virtual public Employee {
private:
  int hour_work;
public:
  int executeWorkday() {
    this->hour_work += 7;
    return 0;
  };
  void mobilize(int hours);
};


#endif //EX03_TEMPWORKER_HPP
