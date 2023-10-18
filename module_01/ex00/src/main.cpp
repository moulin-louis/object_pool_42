//
// Created by loumouli on 10/17/23.
//
#include "../inc/Worker.hpp"
#include "../inc/Shovel.hpp"
#include "../inc/Hammer.hpp"
#include "../inc/Workshop.hpp"

int main() {
  Shovel shovel;
  Hammer hammer;
  Worker worker1;
  Worker worker2;
  Workshop workshop1;
  Workshop workshop2;

  worker1.add_tool(&shovel);
  worker1.add_tool(&hammer);
  worker2.add_tool(&shovel);
  workshop1.register_workshop(&worker1);
  workshop2.register_workshop(&worker1);
  workshop1.executeWorkDay();
  workshop1.leave(&worker1);
  worker1.add_tool(&shovel);
  workshop1.executeWorkDay();
  workshop2.executeWorkDay();
  return 0;
}
