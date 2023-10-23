//
// Created by loumouli on 10/20/23.
//

#pragma once
#ifndef EX02_LISTS_HPP
#define EX02_LISTS_HPP

#include <list>
#include <memory>

using namespace std;


template<typename T>
class Singleton {
protected:
  Singleton() = default;

  virtual ~Singleton() = default;

public:
  static T &instance() {
    static std::unique_ptr<T> instance(new T());
    return *instance;
  }

  Singleton(const Singleton &) = delete;

  Singleton &operator=(const Singleton &) = delete;
};

template<class T>
class Lists {
private:
  list<T *> lists;
public:
  void add_to_list(T *val) {
    if (!val)
      return;
    this->lists.push_back(val);
  };

  void remove_from_list(T *val) {
    if (val) {
      this->lists.remove(val);
      delete val;
    }
  };

  const list<T *> &get_const_list() const { return this->lists; };

  list<T *> &get_list() { return this->lists; };

  ~Lists() {
    for (auto &elem: this->lists) {
      delete elem;
    }
  }
};


#endif //EX02_LISTS_HPP
