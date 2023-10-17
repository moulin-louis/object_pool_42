//
// Created by loumouli on 10/17/23.
//

#include "Worker.hpp"
#include "Shovel.hpp"
#include "Hammer.hpp"

int main() {
  Shovel shovel;
  {
    Worker worker1;
    Worker worker2;
    worker1.add_shovel(&shovel);
    worker2.add_shovel(&shovel);
  }
  shovel.remove_fist();
  return 0;
}
