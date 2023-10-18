//
// Created by loumouli on 10/17/23.
//

#include "../inc/Worker.hpp"
#include "../inc/Shovel.hpp"
#include "../inc/Hammer.hpp"
#include "../inc/Tool.hpp"

int main() {
  Shovel shovel;
  {
    Worker worker1;
    Worker worker2;
    worker1.add_tool(&shovel);
    // worker2.add_tool(&shovel);
  }
  return 0;
}
