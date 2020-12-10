// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <stdint.h>
#include <stdlib.h>

#include <iostream>
#include <string>

template <typename T>
void display(T a) { std::cout << a << std::endl; }

template <typename T1, typename T2>
void display(T1 a, T2 b)
{
  std::cout << a << " , " << b << std::endl;
}

template <typename T, uint8_t size>
void display(T a)
{
  for (uint8_t i = 0; i < size; i++)
  {
    std::cout << a << std::endl;
  }
}

int main(int argc, char **argv)
{
  display<double>(66.6);
  display<std::string, int>("hi", 666);
  display<std::string, 6>("hello");

  return EXIT_SUCCESS;
}
