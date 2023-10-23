//
// Created by loumouli on 10/20/23.
//

#pragma once
#ifndef EX02_PERSON_HPP
#define EX02_PERSON_HPP

#include <string>

class Room;

class Classroom;

class Course;

using namespace std;

class Person {
private:
  string name;
  Room *currentRoom;
public:
  explicit Person(const string &p_name) {
    this->name = p_name;
    this->currentRoom = nullptr;
  };

  const string &get_name() const { return this->name; };

  const Room *get_room() { return (this->currentRoom); }

  friend ostream &operator<<(ostream &p_os, const Person &p_person) {
    p_os << "name: " << p_person.name << endl;
    return p_os;
  }
};

class Student : public Person {
private:
  vector<Course *> subscribedCourse;
  Headmaster *hm;
public:
  explicit Student(const string &p_name) : Person(p_name) {};

  void attendClass(Classroom *p_classroom);

  void exitClass();

  void graduate(Course *p_course);

  void add_subscribed_course(Course *p_course) {
    if (!p_course)
      return;
    this->subscribedCourse.push_back(p_course);
  }

  friend ostream &operator<<(ostream &p_os, const Student &p_student) {
    p_os << "name's: " << p_student.get_name();
    return p_os;
  }
};

#endif //EX02_PERSON_HPP
