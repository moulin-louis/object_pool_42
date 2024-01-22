//
// Created by loumouli on 10/17/23.
//
#ifndef EX00_STATISTIC_HPP
#define EX00_STATISTIC_HPP

struct Statistic {
  int level;
  int exp;

  friend ostream& operator<<(ostream& os, const Statistic& stat) {
    os << "level = " << stat.level << " exp = " << stat.exp;;
    return os;
  }
};

#endif //EX00_STATISTIC_HPP
