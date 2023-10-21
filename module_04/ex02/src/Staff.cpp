//
// Created by loumouli on 10/21/23.
//
#include "Course.hpp"

Form *Secretary::createForm(FormType p_formType) {
  Form *result;
  switch (p_formType) {
    case FormType::CourseFinished:
      result = new CourseFinishedForm(FormType::CourseFinished);
      break;
    case FormType::NeedMoreClassRoom:
      result = new NeedMoreClassRoomForm(FormType::NeedMoreClassRoom);
      break;
    case FormType::NeedCourseCreation:
      result = new NeedCourseCreationForm(FormType::NeedCourseCreation);
      break;
    case FormType::SubscriptionToCourse:
      result = new SubscriptionToCourseForm(FormType::SubscriptionToCourse);
      break;
  }
  return result;
}
