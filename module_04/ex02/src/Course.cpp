//
// Created by loumouli on 10/20/23.
//
#include "Course.hpp"

Course::Course(const string &p_name, int max_student, int nbr_graduate) {
  this->_name = p_name;
  this->maximumNumberOfStudent = max_student;
  this->numberOfClassToGraduate = nbr_graduate;
  this->students = vector<Student *>();
}
