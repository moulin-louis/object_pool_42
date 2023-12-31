//
// Created by loumouli on 10/20/23.
//

#include "Course.hpp"
#include <iostream>

using namespace std;

Lists<Student> &StudentList = Singleton<Lists<Student>>::instance();
//Lists<Room> &RoomList = Singleton<Lists<Room>>::instance();
//Lists<Course> &CourseList = Singleton<Lists<Course>>::instance();
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

void setup_course_creation(NeedCourseCreationForm *form, const string& name, int nbr_class, int max_student, Professor *prof) {
  form->set_name(name);
  form->set_nbr_class(nbr_class);
  form->set_max_student(max_student);
  form->set_prof(prof);
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
  if (form->get_form_type() == FormType::NeedCourseCreation)
    setup_course_creation((NeedCourseCreationForm *)form, string("42"), 5, 30, find_class<Staff, Professor>());
  else if (form->get_form_type() == FormType::CourseFinished)
    setup_course_finished((CourseFinishedForm *)form, find_class<Course, Course>());
  else if (form->get_form_type() == FormType::NeedMoreClassRoom)
    setup_classroom_creation((NeedMoreClassRoomForm *)form, find_class<Course, Course>());
  else if (form->get_form_type() == FormType::SubscriptionToCourse)
    setup_subscribe((SubscriptionToCourseForm *)form, find_class<Course, Course>(), find_class<Student, Student>());
}

int main() {
  new Headmaster("HM");
  Headmaster *hm = find_class<Staff, Headmaster>();
  Secretary *secretary = find_class<Staff, Secretary>();

  StaffList.get_list().push_back(new Professor("Prof"));
  StudentList.get_list().push_back(new Student("Toto"));

  //Create a Course
  setup(secretary->createForm(FormType::NeedCourseCreation));
  hm->signForm(1);

 //  Delete the same Course
  setup(secretary->createForm(FormType::CourseFinished));
  hm->signForm(1);

//   Create another Course
  setup(secretary->createForm(FormType::NeedCourseCreation));
  hm->signForm(1);

//  Create a Classroom
  setup(secretary->createForm(FormType::NeedMoreClassRoom));
  hm->signForm(1);

  //  Subscribe a Student to a Course
  setup(secretary->createForm(FormType::SubscriptionToCourse));
//  (*(find_class<Staff, Secretary>()->get_waiting_form().begin()))->execute();
//  setup(secretary->createForm(FormType::SubscriptionToCourse));
  hm->signForm(1);
//  cout << *find_class<Course, Course>();
  //sign and execute all the form
  return 0;
}