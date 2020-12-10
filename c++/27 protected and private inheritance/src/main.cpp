// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <stdint.h>
#include <stdlib.h>

#include "programmer.h"

int main(int argc, char **argv)
{
  char *name = new char[10];
  name[0] = 'L';
  name[1] = 'i';
  name[2] = 'u';
  name[3] = '\0';
  int64_t id = 2011135139;
  int64_t salary = 10000;
  Programmer p(name, id, salary);
  p.dev();
  return EXIT_SUCCESS;
}
