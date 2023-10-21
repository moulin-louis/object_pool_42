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

class Secretary;

using namespace std;

class Staff : public Person {
private:
public:
  explicit Staff(const string &p_name) : Person(p_name) {};

  static void sign(Form *p_form) {
    cout << "Cant sign Form, not a Headmaster" << endl;
  };

  virtual ~Staff() = default;
};

class Headmaster : public Staff {
private:
  vector<Form *> formToValidate;
  Secretary *secretary;
public:
  explicit Headmaster(const string &p_name);

  void receiveForm(Form *p_form) {
    if (!p_form)
      return;
    this->formToValidate.push_back(p_form);
  };

  static void sign(Form *p_form);

  void signForm(unsigned int nbr_to_sign);
};

class Secretary : public Staff {
private:
  vector<Form *> waiting_form;
  vector<Form *> archive_form;
  Headmaster *hm;
public:
  explicit Secretary(const string &p_name, Headmaster *p_hm) : Staff(p_name) { this->hm = p_hm; };

  ~Secretary() override;

  Form *createForm(FormType p_formType);

  void archiveForm(Form *p_form);
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
