//
// Created by loumouli on 10/20/23.
//

#ifndef EX00_PERSON_HPP
#define EX00_PERSON_HPP

#include <string>
#include "Room.hpp"
#include "Form.hpp"

class Personne;

using namespace std;

class Person {
private:
  string _name;
  Room *_currentRoom;
public:
  explicit Person(const string &p_name) {
    this->_name = p_name;
    this->_currentRoom = nullptr;
  };

  Room *room() { return (_currentRoom); }
};

class Staff : public Person {
private:
public:
  explicit Staff(const string& p_name) : Person(p_name) {};
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
  Form *createForm(FormType p_formType);

  void archiveForm();
};

class Professor : public Staff {
private:
  Course *_currentCourse;

public:
  explicit Professor(const string& p_name) : Staff(p_name) {};
  void assignCourse(Course *p_course);

  void doClass();

  void closeCourse();
};

class Student : public Person {
private:
  vector<Course *> _subscribedCourse;

public:
  explicit Student(const string& p_name) : Person(p_name) {};
  void attendClass(Classroom *p_classroom);

  void exitClass();

  void graduate(Course *p_course);
};

#endif //EX00_PERSON_HPP
