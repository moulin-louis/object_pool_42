//
// Created by loumouli on 10/21/23.
//
#include <list>
#include <algorithm>
#include "Course.hpp"

void NeedCourseCreationForm::execute() {
  Lists<Course> &CourseList = Singleton<Lists<Course>>::instance();

  cout << "Executing NeedCourseCreation Form" << endl;
  if (this->name_course.empty() || this->number_class <= 0 || this->max_student <= 0) {
    cout << "Invalid Params for NeedCourseCreation Form" << endl;
    cout << "Cant execute Form" << endl;
    return;
  }
  auto *new_course = new Course(this->name_course, this->max_student, this->number_class);
  CourseList.add_to_list(new_course);
}

void CourseFinishedForm::execute() {
  Lists<Course> &CourseList = Singleton<Lists<Course>>::instance();

  cout << "Executing CourseFinished Form" << endl;
  if (!this->course_finished) {
    cout << "Invalid Params for CourseFinished Form" << endl;
    cout << "Cant execute Form" << endl;
    return;
  }
  auto it = std::find(CourseList.get_list().begin(), CourseList.get_list().end(), this->course_finished);
  if (it == CourseList.get_list().end()) {
    cout << "Cant find the Course" << endl;
    cout << "Cant execute Form" << endl;
    return;
  }
  CourseList.remove_from_list(*it);
}

void NeedMoreClassRoomForm::execute() {
  Lists<Room> &RoomList = Singleton<Lists<Room>>::instance();
  cout << "Executing NeedMoreClassRoom Form" << endl;
  if (!this->course) {
    cout << "Cant find any Course to assign" << endl;
    cout << "Cant execute Form" << endl;
    return;
  }
  auto *classroom = new Classroom(this->id);
  classroom->assignCourse(this->course);
  RoomList.get_list().push_back(classroom);
}

void SubscriptionToCourseForm::execute() {
  cout << "Executing SubscriptionToCourse Form" << endl;
  if (!this->student || !this->course) {
    cout << "Invalid Params for SubscriptionToCourse Form" << endl;
    cout << "Cant execute Form" << endl;
    return;
  }
  this->course->subscribe(this->student);
  this->student->add_subscribed_course(this->course);
}