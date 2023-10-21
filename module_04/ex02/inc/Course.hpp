//
// Created by loumouli on 10/20/23.
//

#pragma once
#ifndef EX02_COURSE_HPP
#define EX02_COURSE_HPP

#include <string>
#include <vector>
#include "Course.hpp"
#include "Event.hpp"
#include "Form.hpp"
#include "Lists.hpp"
#include "Person.hpp"
#include "Room.hpp"
#include "Staff.hpp"

class Student;

class Professor;

using namespace std;

class Course {
private:
  string _name;
  Professor *responsable;
  vector<Student *> students;
  int numberOfClassToGraduate;
  int maximumNumberOfStudent;
public:
  explicit Course(const string &, int, int);

  void assign(Professor *p_professor) {
    if (!p_professor)
      return;
    this->responsable = p_professor;
  };

  void subscribe(Student *p_student) {
    if (!p_student)
      return;
    this->students.push_back(p_student);
  };

  friend ostream &operator<<(ostream &p_os, const Course &p_course) {
    for (auto &student: p_course.students) {
      p_os << *student << endl;
    }
    return p_os;
  };
};

#endif //EX02_COURSE_HPP
