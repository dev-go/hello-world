// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <stdlib.h>

#include <iostream>
#include <string>

#include "my_array.h"

int main(int argc, char **argv)
{
  MyArray<std::string, 6> arr;
  arr.display();
  std::cout << "======================================" << std::endl;
  arr.set(0, "hello");
  arr.set(1, "c");
  arr.set(2, "c++");
  arr.set(3, "dev");
  arr.set(4, "it");
  arr.set(5, "hi");
  arr.display();

  return EXIT_SUCCESS;
}
