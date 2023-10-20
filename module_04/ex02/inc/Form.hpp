//
// Created by loumouli on 10/20/23.
//

#pragma once
#ifndef EX02_FORM_HPP
#define EX02_FORM_HPP

#include <iostream>

class Professor;

using namespace std;

enum class FormType {
  CourseFinished,
  NeedMoreClassRoom,
  NeedCourseCreation,
  SubscriptionToCourse,
};

class Form {
private:
  FormType _formType;

public:
  explicit Form(FormType p_formType) { this->_formType = p_formType; }
  virtual ~Form() = default;
  virtual void execute() = 0;
};

class CourseFinishedForm : public Form {
private:

public:
  explicit CourseFinishedForm(FormType p_formType) : Form(p_formType) {};
  void execute() override {
    cout << "Executing CourseFinished Form" << endl;
  };
};

class NeedMoreClassRoomForm : public Form {
private:

public:
  explicit NeedMoreClassRoomForm(FormType p_formType) : Form(p_formType) {};
  void execute() override {
    cout << "Executing NeedMoreClassRoom Form" << endl;
  };
};

class NeedCourseCreationForm : public Form {
private:
  string name_course;
  Professor *professor;
  int number_class;
  int max_student;
public:
  explicit NeedCourseCreationForm(FormType p_formType) : Form(p_formType) {};
  void execute() override { cout << "Executing NeedCourseCreation Form" << endl; };
  void set_name(const string &p_name) { this->name_course = p_name; };
  void set_proff(Professor *p_proff) { this->professor = p_proff; };
  void set_nbr_class(int p_nbr) { this->number_class = p_nbr; };
  void set_max_student(int p_nbr) { this->max_student = p_nbr; };
};

class SubscriptionToCourseForm : public Form {
private:

public:
  explicit SubscriptionToCourseForm(FormType p_formType) : Form(p_formType) {};
  void execute() override {
    cout << "Executing SubscriptionToCourse Form" << endl;
  };
};

#endif //EX02_FORM_HPP
