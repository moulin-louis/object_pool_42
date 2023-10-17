//
// Created by llr on 10/17/23.
//

#ifndef EX00_TOOL_HPP
#define EX00_TOOL_HPP

#include <sys/types.h>

class Tool {
  virtual void use() = 0;
protected:
  u_int32_t numberOfUses;
};


#endif //EX00_TOOL_HPP
