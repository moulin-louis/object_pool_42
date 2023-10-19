//
// Created by loumouli on 10/19/23.
//
#ifndef EX03_SALARIEDEMPLOYEE_HPP
#define EX03_SALARIEDEMPLOYEE_HPP

#include "Employee.hpp"

class salariedEmployee : virtual public Employee {
protected:
  unsigned int salary;
  unsigned int hours_rest;

  salariedEmployee() : salary() { this->hours_rest = 0; };

  virtual void rest(unsigned int) = 0;
};

class ContractWorker : virtual public salariedEmployee {
public:
  ContractWorker() { this->salary = 2400; }

  virtual int executeWorkday() { return 0; };

  virtual unsigned int calculate_salary() {
    float percent = (float) this->hours_rest / (float) (31 * 7);
    return (unsigned int) (this->salary * (1.0 - percent));
  };

  virtual void rest(unsigned int hours_to_rest) { this->hours_rest += hours_to_rest; }
};


class Apprentice : virtual public salariedEmployee {
public:
  Apprentice() { this->salary = 1200; };

  virtual int executeWorkday() { return 0; };

  virtual unsigned int calculate_salary() {
    unsigned int salary_school = (int) (this->salary * 0.75);
    float percent = (float) this->hours_rest / (float) (31 * 7);
    return (unsigned int) (salary_school * (1.0 - percent)); // assuming apprentice have a 50/50 presence
  };

  virtual void rest(unsigned int hours_to_rest) { this->hours_rest += hours_to_rest; };
};

#endif //EX03_SALARIEDEMPLOYEE_HPP
