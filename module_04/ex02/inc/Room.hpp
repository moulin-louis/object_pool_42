//
// Created by loumouli on 10/20/23.
//

#pragma once
#ifndef EX02_ROOM_HPP
#define EX02_ROOM_HPP

#include <iostream>

#include <vector>
#include "Form.hpp"

class Person;

class Course;

using namespace std;

class Room {
private:
  long long ID;
  vector<Person *> _occupants;

public:
  Room() {
    this->ID = 0;
    this->_occupants = vector<Person *>();
  };

  bool canEnter(Person *);

  void enter(Person *);

  void exit(Person *);

  void printOccupant();
};

class Classroom : public Room {
private:
  Course *_currentRoom;

public:
  Classroom();

  void assignCourse(Course *p_course);
};

class SecretarialOffice : public Room {
private:
  vector<Form *> _archivedForms;

public:

};

class HeadmasterOffice : public Room {
private:

public:

};

class StaffRestRoom : public Room {
private:

public:

};

class Courtyard : public Room {
private:

public:

};

#endif //EX02_ROOM_HPP
