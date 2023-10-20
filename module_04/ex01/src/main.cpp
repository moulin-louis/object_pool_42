//
// Created by loumouli on 10/20/23.
//

#include "Course.hpp"
#include "Event.hpp"
#include "Form.hpp"
#include "Person.hpp"
#include "Room.hpp"
#include "Lists.hpp"

#include <iostream>

using namespace std;

void test() {
  Lists<Room> &RoomList = Singleton<Lists<Room>>::instance();
  Lists<Student> &StudentList = Singleton<Lists<Student>>::instance();
  Lists<Staff> &StaffList = Singleton<Lists<Staff>>::instance();
  Lists<Course> &CourseList = Singleton<Lists<Course>>::instance();

  for (auto it: RoomList.get_list()) {
    cout << it << endl;
  }
  for (auto it: StudentList.get_list()) {
    cout << it << endl;
  }
  for (auto it: StaffList.get_list()) {
    cout << it << endl;
  }
  for (auto it: CourseList.get_list()) {
    cout << it << endl;
  }
}

int main() {
  Lists<Room> &RoomList = Singleton<Lists<Room>>::instance();
  Lists<Student> &StudentList = Singleton<Lists<Student>>::instance();
  Lists<Staff> &StaffList = Singleton<Lists<Staff>>::instance();
  Lists<Course> &CourseList = Singleton<Lists<Course>>::instance();

  Room room;
  RoomList.add_to_list(&room);
  RoomList.remove_from_list(&room);
  RoomList.add_to_list(&room);

  Student student(string("Toto"));
  StudentList.add_to_list(&student);

  Professor professor(string("Pr.Toto"));
  StaffList.add_to_list(&professor);

  Course course("Minishell");
  CourseList.add_to_list(&course);
  for (auto it: RoomList.get_list()) {
    cout << it << endl;
  }
  for (auto it: StudentList.get_list()) {
    cout << it << endl;
  }
  for (auto it: StaffList.get_list()) {
    cout << it << endl;
  }
  for (auto it: CourseList.get_list()) {
    cout << it << endl;
  }
  cout << endl;
  test();
  return 0;
}