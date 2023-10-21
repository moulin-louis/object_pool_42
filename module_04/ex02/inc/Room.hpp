//
// Created by loumouli on 10/20/23.
//

#pragma once
#ifndef EX02_ROOM_HPP
#define EX02_ROOM_HPP

#include <iostream>
#include <vector>

class Person;

class Course;

using namespace std;

class Room {
private:
  long long ID;
  vector<Person *> occupants;
public:
  Room() {
    this->ID = 0;
    this->occupants = vector<Person *>();
  };

  explicit Room(long long p_id) {
    this->ID = p_id;
    this->occupants = vector<Person *>();
  }

  bool canEnter(Person *);

  void enter(Person *);

  void exit(Person *);

  void printOccupant();
};

class Classroom : public Room {
private:
  Course *currentCourse;
public:
  explicit Classroom(long long p_id) : Room(p_id) { this->currentCourse = nullptr; };

  void assignCourse(Course *p_course) {
    if (!p_course)
      return;
    this->currentCourse = p_course;
  };
};

class SecretarialOffice : public Room {
private:
  vector<Form *> archivedForms;
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
