// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <stdint.h>
#include <stdlib.h>

#include "worker.h"

int main(int argc, char **argv)
{
  char name[] = {'T', 'e', 'r', 'r', 'e', 'n', 'c', 'e', '\0'};
  int64_t id = 2011135139;
  int64_t salary = 10000;
  Worker w(name, id, salary);
  w.run();
  w.work();

  return EXIT_SUCCESS;
}
