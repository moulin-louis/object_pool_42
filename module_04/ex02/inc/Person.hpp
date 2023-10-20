//
// Created by loumouli on 10/20/23.
//

#pragma once
#ifndef EX02_PERSON_HPP
#define EX02_PERSON_HPP

#include <string>
#include "Room.hpp"

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

class Student : public Person {
private:
  vector<Course *> _subscribedCourse;

public:
  explicit Student(const string &p_name) : Person(p_name) {};

  void attendClass(Classroom *p_classroom);

  void exitClass();

  void graduate(Course *p_course);
};

#endif //EX02_PERSON_HPP
