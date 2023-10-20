//
// Created by loumouli on 10/20/23.
//

#ifndef EX00_COURSE_HPP
#define EX00_COURSE_HPP

#include <string>
#include <vector>
#include "Person.hpp"

class Professor;

class Student;

using namespace std;

class Course {
private:
  string _name;
  Professor *_responsable;
  vector<Student *> _students;
  int _numberOfClassToGraduate;
  int _maximumNumberOfStudent;
public:
  explicit Course(const string &p_name);

  void assign(Professor *p_professor) {
    if (!p_professor)
      return;
    this->_responsable = p_professor;
  };

  void subscribe(Student *p_student) {
    if (!p_student)
      return;
    this->_students.push_back(p_student);
  };
};

#endif //EX00_COURSE_HPP
