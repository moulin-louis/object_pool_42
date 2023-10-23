//
// Created by loumouli on 10/20/23.
//
#include "Course.hpp"

Course::Course(const string &p_name, int max_student, int nbr_graduate) {
  this->name = p_name;
  this->maximumNumberOfStudent = max_student;
  this->numberOfClassToGraduate = nbr_graduate;
  this->students = vector<Student *>();
  this->responsable = nullptr;
}

ostream &operator<<(ostream &p_os, const Course &p_course) {
  p_os << "Course's name: " << p_course.name << endl;
  p_os << *p_course.responsable;
  p_os << "Student in Course: " << endl;
  for (auto &student: p_course.students) {
    p_os << "\t-" << *student << endl;
  }
  p_os << "Number of class to graduate: " << p_course.numberOfClassToGraduate << endl;
  p_os << "Max nbr of student: " << p_course.maximumNumberOfStudent << endl;
  return p_os;
}
