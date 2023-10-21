//
// Created by loumouli on 10/20/23.
//

#include "Course.hpp"
#include <iostream>

using namespace std;

Lists<Student> &StudentList = Singleton<Lists<Student>>::instance();
Lists<Room> &RoomList = Singleton<Lists<Room>>::instance();
Lists<Course> &CourseList = Singleton<Lists<Course>>::instance();
Lists<Staff> &StaffList = Singleton<Lists<Staff>>::instance();

template <class BaseClass, class ChildClass>
ChildClass* find_class() {
  Lists<BaseClass> &list = Singleton<Lists<BaseClass>>::instance();
  for (auto elem : list.get_list()) {
    if (dynamic_cast<ChildClass*>(elem) != nullptr)
      return (ChildClass *)elem;
  }
  return nullptr;
}

void setup_course_creation(NeedCourseCreationForm *form, const string& name, int nbr_class, int max_student) {
  form->set_name(name);
  form->set_nbr_class(nbr_class);
  form->set_max_student(max_student);
}

void setup_course_finished(CourseFinishedForm *form, Course *course) {
  form->set_course_finished(course);
}

void setup_classroom_creation(NeedMoreClassRoomForm *form, Course *course) {
  form->set_course(course);
}

void setup_subscribe(SubscriptionToCourseForm *form, Course *course, Student *student) {
  form->set_course(course);
  form->set_student(student);
}

void setup(Form *form) {
  if (form->get_form_type() == FormType::NeedCourseCreation) {
    setup_course_creation((NeedCourseCreationForm *)form, string("42"), 5, 30);
  } else if (form->get_form_type() == FormType::CourseFinished) {
    setup_course_finished((CourseFinishedForm *)form, find_class<Course, Course>());
  } else if (form->get_form_type() == FormType::NeedMoreClassRoom) {
    setup_classroom_creation((NeedMoreClassRoomForm *)form, find_class<Course, Course>());
  } else if (form->get_form_type() == FormType::SubscriptionToCourse) {
    setup_subscribe((SubscriptionToCourseForm *)form, find_class<Course, Course>(), find_class<Student, Student>());
  }
}

int main() {
  new Headmaster("HM");
  Form *form;
  Headmaster *hm = find_class<Staff, Headmaster>();
  Secretary *secretary = find_class<Staff, Secretary>();

  StudentList.get_list().push_back(new Student("Toto"));

  //Create a Course
  form = secretary->createForm(FormType::NeedCourseCreation);
  setup(form);
  hm->signForm(1);
  cout << "Size of CourseList: " << CourseList.get_const_list().size() << endl;

 //  Delete the same Course
//  form = secretary->createForm(FormType::CourseFinished);
//  setup(form);
//  cout << "Size of CourseList: " << CourseList.get_const_list().size() << endl;

 //  Create another Course
//  form = secretary->createForm(FormType::NeedCourseCreation);
//  setup(form);

 //  Create a Classroom
//  form = secretary->createForm(FormType::NeedMoreClassRoom);
//  setup(form);
//  cout << "Size of RoomList: " << RoomList.get_list().size() << endl;

 //  Subscribe a Student to a Course
//  form = secretary->createForm(FormType::SubscriptionToCourse);
//  setup(form);
//  cout << *(*CourseList.get_list().begin());
  return 0;
}