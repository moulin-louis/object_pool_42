//
// Created by llr on 10/19/23.
//

#ifndef EX03_EMPLOYEE_HPP
#define EX03_EMPLOYEE_HPP


class Employee {
private:
  int hourlyValue;
public:
  const int& get_hourlyValue();
  virtual int executeWorkday() = 0;
};

#endif //EX03_EMPLOYEE_HPP
