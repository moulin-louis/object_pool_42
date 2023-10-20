//
// Created by loumouli on 10/20/23.
//
#include "Course.hpp"

Course::Course(const string &p_name)  {
  this->_name = p_name;
  this->_responsable = nullptr;
  this->_maximumNumberOfStudent = 0;
  this->_numberOfClassToGraduate = 0;
}

