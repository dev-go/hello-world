// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <stdlib.h>

#include <iostream>

#include "array.h"

int main(int argc, char **argv)
{
  Array arr(6);
  std::cout << arr.get_len() << std::endl;
  arr.set_value(0, 1000);
  arr.set_value(1, 1001);
  arr.set_value(2, 1002);
  std::cout << "===========" << std::endl;

  for (uint64_t i = 0; i < arr.get_len(); i++)
  {
    double tmp = 0;
    arr.get_value(i, &tmp);
    std::cout << "index: " << i << ", value: " << tmp << std::endl;
  }

  return EXIT_SUCCESS;
}
