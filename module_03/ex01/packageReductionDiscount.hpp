//
// Created by llr on 10/18/23.
//

#ifndef EX01_PACKAGEREDUCTIONDISCOUNT_HPP
#define EX01_PACKAGEREDUCTIONDISCOUNT_HPP

#include "command.hpp"

class PackageReductionDiscountCommand : virtual public Command {
public:
  virtual float get_total_price() {
    float result = 0;
    for (vector<Command::items>::iterator it = this->articles.begin(); it != this->articles.end(); it++) {
      result += ((*it).price * (float)(*it).quantity);
    }
    return result > 150 ? result - 10.0f : result;
  }
};

#endif //EX01_PACKAGEREDUCTIONDISCOUNT_HPP
