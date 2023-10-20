//
// Created by loumouli on 10/20/23.
//

#ifndef EX04_HEADERLOGGER_HPP
#define EX04_HEADERLOGGER_HPP

#include "ILogger.hpp"
#include <typeinfo>

template<class T>
class HeaderLogger : virtual public ILogger {
protected:
  T *header;

  virtual string add_header(string input) { return this->header ? (*header + ":" + input) : (input); };
public:
  HeaderLogger() { this->header = NULL; };

  ~HeaderLogger() { this->header ? delete this->header : void(); };

  virtual void change_header(T new_header) {
    if (this->header)
      delete this->header;
    this->header = new T;
    *this->header = new_header;
  }

  virtual void write(string) = 0;
};

#endif //EX04_HEADERLOGGER_HPP
