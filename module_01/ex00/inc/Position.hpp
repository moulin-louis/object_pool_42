//
// Created by loumouli on 10/17/23.
//
#ifndef EX00_POSITION_HPP
#define EX00_POSITION_HPP

using namespace std;

struct Position {
  int x;
  int y;
  int z;
  friend ostream& operator<<(ostream& os, const Position& pos) {
    os << "x = " << pos.x << " y = " << pos.y << " z = " << pos.z;
    return os;
  }
};

#endif //EX00_POSITION_HPP
