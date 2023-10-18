//
// Created by llr on 10/17/23.
//

#ifndef EX00_TOOL_HPP
#define EX00_TOOL_HPP

#include <sys/types.h>
#include "Worker.hpp"

class Worker;

class Tool {
public:
  virtual void use() = 0;
  void add_owner(const Worker*);
  void remove_owner();
  const Worker *& get_owner();
protected:
  const Worker *owner;
  u_int32_t numberOfUses;
};


#endif //EX00_TOOL_HPP
