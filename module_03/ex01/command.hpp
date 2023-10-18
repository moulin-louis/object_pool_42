//
// Created by llr on 10/18/23.
//

#ifndef EX01_COMMAND_HPP
#define EX01_COMMAND_HPP

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Command {
public:
  struct items {
    int quantity;
    float price;
  };
  int id;
  string date;
  string client;
  vector<items> articles;

  virtual float get_total_price() {
    float result = 0;
    for (vector<items>::iterator it = this->articles.begin(); it != this->articles.end(); it++) {
      result += ((*it).price * (float)(*it).quantity);
    }
    return result;
  }
};


#endif //EX01_COMMAND_HPP
