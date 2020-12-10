// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "person.h"
#include "worker.h"

int main(int argc, char **argv)
{
  char *name = (char *)"Terrence";
  uint64_t id = 2011135139;
  Person *w = new Worker(name, id);

  printf("================================\n");

  printf("%s\n", w->to_string());
  w->work();

  printf("================================\n");

  delete w;
  w = NULL;

  printf("================================\n");

  return EXIT_SUCCESS;
}
