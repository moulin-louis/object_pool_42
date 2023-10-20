//
// Created by loumouli on 10/20/23.
//

#ifndef EX01_LISTS_HPP
#define EX01_LISTS_HPP

#include <list>

using namespace std;

#include <memory>

template<typename T>
class Singleton {
public:
  static T &instance() {
    static std::unique_ptr<T> instance(new T());
    return *instance;
  }

  Singleton(const Singleton &) = delete;

  Singleton &operator=(const Singleton &) = delete;

protected:
  Singleton() = default;

  virtual ~Singleton() = default;
};

template<class T>
class Lists {
private:
  list<T *> _list;
public:
  void add_to_list(T *val) {
    if (!val)
      return;
    this->_list.push_back(val);
  };

  void remove_from_list(T *val) {
    if (!val)
      return;
    this->_list.remove(val);
  };

  const list<T *> &get_list() const { return this->_list; };
};


#endif //EX01_LISTS_HPP
