// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <stdint.h>
#include <stdlib.h>

#include <iostream>

int main(int argc, char **argv)
{
  int32_t a = 0;
  std::cout << "please enter an integer: " << std::endl;
  std::cin >> a;
  std::cout << "your input is: " << a << std::endl;
  std::cout << "oct: " << std::oct << a << std::endl;
  std::cout << "dec: " << std::dec << a << std::endl;
  std::cout << "hex: " << std::hex << a << std::endl;

  std::cout << "======================" << std::endl;

  bool b = false;
  std::cout << "please enter a boolean value(0 or 1)" << std::endl;
  std::cin >> b;
  std::cout << std::boolalpha << b << std::endl;

  return EXIT_SUCCESS;
}
