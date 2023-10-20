//
// Created by loumouli on 10/20/23.
//

#pragma once
#ifndef EX02_STAFF_HPP
#define EX02_STAFF_HPP

#include <string>
#include "Form.hpp"

using namespace std;

class Staff : public Person {
private:
public:
  explicit Staff(const string &p_name) : Person(p_name) {};

  void sign(Form *p_form);
};

class Headmaster : public Staff {
private:
  vector<Form *> _formToValidate;

public:
  void receiveForm(Form *p_form);
};

class Secretary : public Staff {
private:

public:
  explicit Secretary(const string &p_name) : Staff(p_name) {};

  static Form *createForm(FormType p_formType) {
    switch (p_formType) {
      case FormType::CourseFinished:
        return new CourseFinishedForm(FormType::CourseFinished);
      case FormType::NeedMoreClassRoom:
        return new NeedMoreClassRoomForm(FormType::NeedMoreClassRoom);
      case FormType::NeedCourseCreation:
        return new NeedCourseCreationForm(FormType::NeedCourseCreation);
      case FormType::SubscriptionToCourse:
        return new SubscriptionToCourseForm(FormType::SubscriptionToCourse);
    }
  }

  void archiveForm();
};

class Professor : public Staff {
private:
  Course *_currentCourse;

public:
  explicit Professor(const string &p_name) : Staff(p_name) {};

  void assignCourse(Course *p_course);

  void doClass();

  void closeCourse();
};

#endif //EX02_STAFF_HPP
