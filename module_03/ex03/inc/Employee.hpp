//
// Created by loumouli on 10/19/23.
//
#ifndef EX03_EMPLOYEE_HPP
#define EX03_EMPLOYEE_HPP


class Employee {
protected:
  unsigned int hourlyValue;
public:
  Employee() { this->hourlyValue = 0; };

  const unsigned int &get_hourlyValue() const { return this->hourlyValue; };

  virtual int executeWorkday() = 0;

  virtual unsigned int calculate_salary() = 0;
};

#endif //EX03_EMPLOYEE_HPP
