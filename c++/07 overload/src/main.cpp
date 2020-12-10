// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <stdint.h>
#include <stdlib.h>

#include <iostream>

int32_t get_max(int32_t x = 101, int32_t y = 102, int32_t z = 103);

int32_t get_max(int32_t x, int32_t y);

int main(int argc, char **argv)
{
  int32_t a = 1;
  int32_t b = 2;
  int32_t c = 3;
  std::cout << "get_max: " << get_max(a, b, c) << std::endl;
  // std::cout << "get_max: " << get_max(a, b) << std::endl; // error: call to
  // 'get_max' is ambiguous
  return EXIT_SUCCESS;
}

int32_t get_max(int32_t x, int32_t y, int32_t z)
{
  int32_t result = x;
  if (y > result)
  {
    result = y;
  }
  if (z > result)
  {
    result = z;
  }
  return result;
}

int32_t get_max(int32_t x, int32_t y)
{
  int32_t result = x;
  if (y > result)
  {
    result = y;
  }
  return result;
}
