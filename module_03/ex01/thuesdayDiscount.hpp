//
// Created by llr on 10/18/23.
//

#ifndef EX01_THUESDAYDISCOUNT_HPP
#define EX01_THUESDAYDISCOUNT_HPP

#include "command.hpp"

class ThuesdayDiscountCommand : virtual public Command {
public:
  virtual float get_total_price() {
    float result = 0;
    for (vector<Command::items>::iterator it = this->articles.begin(); it != this->articles.end(); it++) {
      result += ((*it).price * (float)(*it).quantity);
    }
    if (this->date == "Thuesday") {
      return result * 0.9f;
    }
    return result;
  }
};


#endif //EX01_THUESDAYDISCOUNT_HPP
