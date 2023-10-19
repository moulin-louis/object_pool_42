//
// Created by llr on 10/19/23.
//

#ifndef EX03_APPRENTICE_HPP
#define EX03_APPRENTICE_HPP

#include "Employee.hpp"

class Apprentice : virtual public Employee {
public:
  int executeWorkday() {
    return 0;
  };
};


#endif //EX03_APPRENTICE_HPP
