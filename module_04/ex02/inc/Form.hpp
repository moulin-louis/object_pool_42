//
// Created by loumouli on 10/20/23.
//

#pragma once
#ifndef EX02_FORM_HPP
#define EX02_FORM_HPP

#include <iostream>
#include <random>

class Professor;

class Course;

class Student;

template<class T>
class Lists;

template<class T>
class Singleton;

class Headmaster;

using namespace std;

enum class FormType {
  CourseFinished,
  NeedMoreClassRoom,
  NeedCourseCreation,
  SubscriptionToCourse,
};

class Form {
private:
  FormType formType;
  bool is_signed;
public:
  friend Headmaster;

  explicit Form(FormType p_formType) {
    this->formType = p_formType;
    this->is_signed = false;
  }

  virtual ~Form() = default;

  virtual void execute() = 0;

  const FormType &get_form_type() { return this->formType; };

  bool get_signed() { return this->is_signed; };
};

class NeedCourseCreationForm : public Form {
private:
  string name_course;
  int number_class{};
  int max_student{};
public:
  explicit NeedCourseCreationForm(FormType p_formType) : Form(p_formType) {};

  void execute() override;

  void set_name(const string &p_name) { this->name_course = p_name; };

  void set_nbr_class(int p_nbr) {
    if (p_nbr < 0)
      return;
    this->number_class = p_nbr;
  };

  void set_max_student(int p_nbr) {
    if (p_nbr < 0)
      return;
    this->max_student = p_nbr;
  };
};

class CourseFinishedForm : public Form {
private:
  Course *course_finished{};
public:
  explicit CourseFinishedForm(FormType p_formType) : Form(p_formType) {};

  void execute() override;

  void set_course_finished(Course *p_course) {
    if (!p_course)
      return;
    this->course_finished = p_course;
  };
};

class NeedMoreClassRoomForm : public Form {
private:
  long long id;
  Course *course;
public:
  explicit NeedMoreClassRoomForm(FormType p_formType) : Form(p_formType) {
    std::random_device rd;
    this->id = rd();
    this->course = nullptr;
  };

  void execute() override;

  void set_course(Course *p_course) {
    if (!p_course)
      return;
    this->course = p_course;
  }
};

class SubscriptionToCourseForm : public Form {
private:
  Student *student;
  Course *course;
public:
  explicit SubscriptionToCourseForm(FormType p_formType) : Form(p_formType) {
    this->student = nullptr;
    this->course = nullptr;
  };

  void execute() override;

  void set_student(Student *p_student) {
    if (!p_student)
      return;
    this->student = p_student;
  };

  void set_course(Course *p_course) {
    if (!p_course)
      return;
    this->course = p_course;
  };
};

#endif //EX02_FORM_HPP
