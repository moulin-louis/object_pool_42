//
// Created by llr on 10/18/23.
//
#ifndef EX00_ENGINE_HPP
#define EX00_ENGINE_HPP

#include <iostream>

using namespace std;

class Engine {
protected:
  Engine();

public:
  static void start();

  static void stop();
};

#endif //EX00_ENGINE_HPP
