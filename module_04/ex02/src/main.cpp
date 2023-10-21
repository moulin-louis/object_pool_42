//
// Created by loumouli on 10/20/23.
//

#include "Course.hpp"
#include <iostream>

using namespace std;

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

void execute_n_delete(Form *form) {
  form->execute();
  delete form;
}

int main() {
  Lists<Room> &RoomList = Singleton<Lists<Room>>::instance();
  Lists<Student> &StudentList = Singleton<Lists<Student>>::instance();
//  Lists<Staff> &StaffList = Singleton<Lists<Staff>>::instance();
  Lists<Course> &CourseList = Singleton<Lists<Course>>::instance();

  StudentList.get_list().push_back(new Student("Toto"));
  Secretary secretary("Mr.Secretary");
  Form *form;

  //Create a Course
  form = Secretary::createForm(FormType::NeedCourseCreation);
  setup_course_creation((NeedCourseCreationForm *)form, string("42"), 5, 30);
  execute_n_delete(form);
  cout << "Size of CourseList: " << CourseList.get_const_list().size() << endl;

  //Delete the same Course
  form = Secretary::createForm(FormType::CourseFinished);
  setup_course_finished((CourseFinishedForm *)form, *CourseList.get_list().begin());
  execute_n_delete(form);
  cout << "Size of CourseList: " << CourseList.get_const_list().size() << endl;

  //Create another Course
  form = Secretary::createForm(FormType::NeedCourseCreation);
  setup_course_creation((NeedCourseCreationForm *)form, string("42"), 5, 30);
  execute_n_delete(form);

  //Create a Classroom
  form = Secretary::createForm(FormType::NeedMoreClassRoom);
  setup_classroom_creation((NeedMoreClassRoomForm *)form, *CourseList.get_list().begin());
  execute_n_delete(form);
  cout << "Size of RoomList: " << RoomList.get_list().size() << endl;

  //Subscribe a Student to a Course
  form = Secretary::createForm(FormType::SubscriptionToCourse);
  setup_subscribe((SubscriptionToCourseForm *)form, *CourseList.get_list().begin(), *StudentList.get_list().begin());
  execute_n_delete(form);
  cout << *(*CourseList.get_list().begin());
  return 0;
}