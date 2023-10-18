//
// Created by llr on 10/18/23.
//

#include "command.hpp"
#include "packageReductionDiscount.hpp"
#include "thuesdayDiscount.hpp"

int main(void) {
  Command new_command;
  new_command.client = "Toto";
  new_command.date = "Thuesday";
  Command::items temp = {2, 5.0};
  new_command.articles.push_back(temp);
  cout << new_command.get_total_price() << endl;
  ThuesdayDiscountCommand command_thuesday;
  command_thuesday.client = "Toto";
  command_thuesday.date = "Thuesday";
  command_thuesday.articles.push_back(temp);
  cout << command_thuesday.get_total_price() << endl;
  PackageReductionDiscountCommand pckg_command;
  pckg_command.client = "Toto";
  pckg_command.date = "Thuesday";
  pckg_command.articles.push_back(temp);
  cout << pckg_command.get_total_price() << endl;
  for (int i = 0; i < 19; i++) {
    pckg_command.articles.push_back(temp);
  }
  cout << pckg_command.get_total_price() << endl;
  return 1;
}