// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include <iostream>

class TV
{
public:
  char model[20];
  uint32_t price;

  void switch_vol(bool is_up)
  {
    if (is_up)
    {
      std::cout << "switch vol up" << std::endl;
    }
    else
    {
      std::cout << "switch vol down" << std::endl;
    }
  };
};

int main(int argc, char **argv)
{
  TV t1;
  memset(t1.model, 0, 20);
  strcpy(t1.model, "tcl_1000");
  t1.price = 6000;
  std::cout << "model: " << t1.model << ", price: " << t1.price << std::endl;
  t1.switch_vol(false);

  std::cout << "========================" << std::endl;

  TV *t2 = new TV();
  if (t2 == NULL)
  {
    std::cout << "create a new tv failed" << std::endl;
    return EXIT_FAILURE;
  }
  memset(t2->model, 0, 20);
  strcpy(t2->model, "sharp_600");
  t2->price = 3900;
  std::cout << "model: " << t2->model << ", price: " << t2->price << std::endl;
  t2->switch_vol(true);
  delete t2;
  t2 = NULL;

  return EXIT_SUCCESS;
}
