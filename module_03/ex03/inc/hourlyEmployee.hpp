//
// Created by loumouli on 10/19/23.
//
#ifndef EX03_HOURLYEMPLOYEE_HPP
#define EX03_HOURLYEMPLOYEE_HPP

#include <iostream>
#include "Employee.hpp"

using namespace std;

class hourlyEmployee : virtual public Employee {
protected:
  unsigned int hours_done;
public:
  hourlyEmployee() { this->hours_done = 0; };
};

class TempWorker : virtual public hourlyEmployee {
private:
  unsigned int hours_to_work;
public:
  TempWorker() {
    this->hours_to_work = 0;
    this->hourlyValue = 4;
  };

  int executeWorkday() {
    if (this->hours_to_work > 7) {
      this->hours_to_work -= 7;
      this->hours_done += 7;
    } else {
      this->hours_done += this->hours_to_work;
      this->hours_to_work = 0;
    }
    return 0;
  };

  void mobilize(unsigned int hours) { this->hours_to_work += hours; };

  unsigned int calculate_salary() { return this->hours_done * this->hourlyValue; };
};

#endif //EX03_HOURLYEMPLOYEE_HPP
