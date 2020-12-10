// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <stdint.h>
#include <stdlib.h>

#include <iostream>

void f(int32_t i, int32_t j = 6, int32_t k = 8);

// void g(int32_t i, int32_t j=6, int32_t k); // error: missing default argument
// on parameter 'k'

int main(int argc, char **argv)
{
  f(1, 2, 3);
  f(1, 2);
  f(1);
  return EXIT_SUCCESS;
}

void f(int32_t i, int32_t j, int32_t k)
{
  std::cout << "i: " << i << ", j: " << j << ", k: " << k << std::endl;
  return;
}
