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
  Workshop workshop;

  worker1.add_tool(&shovel);
  worker1.add_tool(&hammer);
  worker2.add_tool(&shovel);
  workshop.register_workshop(&worker1);
  workshop.executeWorkDay();
  workshop.leave(&worker1);
  workshop.executeWorkDay();
  return 0;
}
