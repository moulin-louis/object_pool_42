//
// Created by loumouli on 10/21/23.
//
#include "Course.hpp"
#include <algorithm>

using namespace std;

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
  this->waiting_form.push_back(result);
  this->hm->receiveForm(result);
  return result;
}

void Secretary::archiveForm(Form *p_form) {
  cout << "Archiving Form..." << endl;
  auto it = find(this->waiting_form.begin(), this->waiting_form.end(), p_form);
  if (it == this->waiting_form.end()) {
    cout << "Cant find this Form" << endl;
    return;
  }
  this->waiting_form.erase(it);
  this->archive_form.push_back(p_form);
  cout << "Form archived!" << endl;
}

Secretary::~Secretary() {
  for (auto elem : this->waiting_form)
    delete elem;
  for (auto elem : this->archive_form)
    delete elem;
}

void Headmaster::sign(Form *p_form) {
  p_form->is_signed = true;
}

void Headmaster::signForm(unsigned int nbr_to_sign) {
  if (nbr_to_sign > this->formToValidate.size()) {
    nbr_to_sign = this->formToValidate.size();
  }
  for (unsigned int i = 0; i < nbr_to_sign; i++) {
    auto form = this->formToValidate.begin();
    this->sign(*form);
    (*form)->is_signed = true;
    (*form)->execute();
    secretary->archiveForm(*form);
    this->formToValidate.erase(form);
    cout << endl;
  }
}

Headmaster::Headmaster(const string &p_name) : Staff(p_name) {
  Lists<Staff>& StaffLists = Singleton<Lists<Staff>>::instance();

  this->secretary = new Secretary("Secretary", this);
  StaffLists.get_list().push_back(this->secretary);
  StaffLists.get_list().push_back(this);
}
