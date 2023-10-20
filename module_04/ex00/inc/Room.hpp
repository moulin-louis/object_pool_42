//
// Created by loumouli on 10/20/23.
//
#ifndef EX00_ROOM_HPP
#define EX00_ROOM_HPP

#include <vector>
#include "Person.hpp"
#include "Form.hpp"
#include "Course.hpp"

class Person;

class Course;

using namespace std;

class Room {
private:
  long long ID;
  vector<Person *> _occupants;

public:
  Room();

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

#endif //EX00_ROOM_HPP
