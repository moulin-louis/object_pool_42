//
// Created by loumouli on 10/23/23.
//

#ifndef EX03_UTILS_HPP
#define EX03_UTILS_HPP

template<class T>
class Lists;

template<class T>
class Singleton;

template <class BaseClass, class ChildClass>
ChildClass* find_class() {
  Lists<BaseClass> &list = Singleton<Lists<BaseClass>>::instance();
  for (auto elem : list.get_list()) {
    if (dynamic_cast<ChildClass*>(elem) != nullptr)
      return (ChildClass *)elem;
  }
  return nullptr;
}

#endif //EX03_UTILS_HPP
