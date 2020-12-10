// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <stdint.h>
#include <stdlib.h>

#include <iostream>

int main(int argc, char **argv)
{
  int32_t *a = new int32_t(66);
  if (a == NULL)
  {
    return EXIT_FAILURE;
  }
  std::cout << "a: " << a << ", *a: " << *a << std::endl;
  delete a;
  a = NULL;

  int32_t *b = new int32_t;
  if (b == NULL)
  {
    return EXIT_FAILURE;
  }
  std::cout << "b: " << b << ", *b: " << *b << std::endl;
  delete b;
  b = NULL;

  int32_t *c = new int32_t();
  if (c == NULL)
  {
    return EXIT_FAILURE;
  }
  std::cout << "c: " << c << ", *c: " << *c << std::endl;
  delete c;
  c = NULL;

  std::cout << "================================" << std::endl;

  int32_t len = 10;
  int32_t *arr = new int32_t[len];
  std::cout << "arr: " << arr << std::endl;
  if (arr == NULL)
  {
    return EXIT_FAILURE;
  }
  for (int32_t i = 0; i < len; i++)
  {
    arr[i] = 101 * i;
  }
  for (int32_t i = 0; i < len; i++)
  {
    std::cout << "index: " << i << ", value: " << arr[i] << std::endl;
  }
  delete[] arr;
  arr = NULL;

  return EXIT_SUCCESS;
}
