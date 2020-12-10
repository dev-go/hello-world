// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <stdio.h>
#include <stdlib.h>

#include "array.h"

int main(int argc, char **argv)
{
  Array arr01 = Array(6);
  arr01.set(0, 100);
  arr01.set(1, 200);
  arr01.set(2, 300);
  Array arr02 = arr01;
  arr02.set(3, 400);
  for (uint64_t i = 0; i < arr01.count(); i++)
  {
    double v = 0;
    arr01.get(i, &v);
    printf("arr01 -- index: %lu, value: %lf\n", i, v);
  }
  for (uint64_t i = 0; i < arr02.count(); i++)
  {
    double v = 0;
    arr02.get(i, &v);
    printf("arr02 -- index: %lu, value: %lf\n", i, v);
  }
  return EXIT_SUCCESS;
}
