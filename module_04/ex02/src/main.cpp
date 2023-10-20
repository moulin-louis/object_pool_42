//
// Created by loumouli on 10/20/23.
//

#include "Course.hpp"
#include "Event.hpp"
#include "Form.hpp"
#include "Person.hpp"
#include "Staff.hpp"
#include "Room.hpp"
#include "Lists.hpp"

#include <iostream>

using namespace std;

int main() {
//  Lists<Room> &RoomList = Singleton<Lists<Room>>::instance();
//  Lists<Student> &StudentList = Singleton<Lists<Student>>::instance();
//  Lists<Staff> &StaffList = Singleton<Lists<Staff>>::instance();
//  Lists<Course> &CourseList = Singleton<Lists<Course>>::instance();

  Secretary secretary("Mr.Secretary");
  Form *form = secretary.createForm(FormType::SubscriptionToCourse);
  form->execute();
  delete form;
  return 0;
}