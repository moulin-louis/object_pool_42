//
// Created by loumouli on 10/20/23.
//

#pragma once
#ifndef EX02_STAFF_HPP
#define EX02_STAFF_HPP

#include <string>
#include <vector>

class Form;

class Person;

class Course;

enum class FormType;

using namespace std;

class Staff : public Person {
private:
public:
  explicit Staff(const string &p_name) : Person(p_name) {};

  void sign(Form *p_form) {
    cout << "Cant sign Form, not a Headmaster" << endl;
  };
};

class Headmaster : public Staff {
private:
  vector<Form *> formToValidate;

public:
  void receiveForm(Form *p_form);
};

class Secretary : public Staff {
private:
  vector<Form *> archive_form;
public:
  explicit Secretary(const string &p_name) : Staff(p_name) {};

  static Form *createForm(FormType p_formType);

  void archiveForm();
};

class Professor : public Staff {
private:
  Course *currentCourse;

public:
  explicit Professor(const string &p_name) : Staff(p_name) {};

  void assignCourse(Course *p_course);

  void doClass();

  void closeCourse();
};

#endif //EX02_STAFF_HPP
