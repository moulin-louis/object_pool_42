//
// Created by loumouli on 10/20/23.
//

#ifndef EX04_FILELOGGER_HPP
#define EX04_FILELOGGER_HPP

#include <iostream>
#include <fstream>
#include "HeaderLogger.hpp"

using namespace std;

class File {
private:
  ofstream file;
public:
  explicit File(const string &file_name) {
    this->file.open(file_name.c_str(), ios::out);
    if (!this->file.is_open())
      throw std::runtime_error(string("File: cant open:") + file_name);
  };

  ~File() { this->file.close(); };

  void write_to_file_nl(const string &input) { this->file << input << endl; };
};

template<class T>
class FileLogger : virtual public HeaderLogger<T>, public File {
protected:
  virtual void write(string input) { this->write_to_file_nl(this->add_header(input)); };

  explicit FileLogger(string input) : File(input) {};
};

template<class T>
class UserFileLogger : virtual public FileLogger<T> {
private:
  ofstream file;
public:
  explicit UserFileLogger(string input) : FileLogger<T>(input) {};
};

template<class T>
class ManagedFileLogger : virtual public FileLogger<T> {
private:
  ofstream file;
public:
  explicit ManagedFileLogger() : FileLogger<T>("/tmp/log_ex04") {};
};

#endif //EX04_FILELOGGER_HPP
