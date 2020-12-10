// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <stdint.h>
#include <stdlib.h>

#include <iostream>

inline int32_t max(int32_t a, int32_t b, int32_t c);

int main(int argc, char **argv)
{
  int32_t a = 27;
  int32_t b = 13;
  int32_t c = 51;
  std::cout << "max: " << max(a, b, c) << std::endl;
  return EXIT_SUCCESS;
}

int32_t max(int32_t a, int32_t b, int32_t c)
{
  int32_t result = a;
  if (b > result)
  {
    result = b;
  }
  if (c > result)
  {
    result = c;
  }
  return result;
}
