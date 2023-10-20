//
// Created by loumouli on 10/20/23.
//

#ifndef EX00_FORM_HPP
#define EX00_FORM_HPP

enum class FormType {
  CourseFinished,
  NeedMoreClassRoom,
  NeedCourseCreation,
  SubscriptionToCourse,
};

class Form {
private:
  FormType _formType;

public:
  explicit Form(FormType p_formType) {
    this->_formType = p_formType;
  }

  virtual void execute() = 0;
};

class CourseFinishedForm : public Form {
private:

public:
  void execute();
};

class NeedMoreClassRoomForm : public Form {
private:

public:
  void execute();
};

class NeedCourseCreationForm : public Form {
private:

public:
  void execute();
};

class SubscriptionToCourseForm : public Form {
private:

public:
  void execute();
};


#endif //EX00_FORM_HPP
