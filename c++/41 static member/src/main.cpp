// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "tank.h"

int main(int argc, char **argv)
{
  printf("count: %lu, seq: %lu\n", Tank::get_count(), Tank::get_seq());
  Tank *t1 = new Tank();
  Tank *t2 = new Tank();
  Tank t3 = *t1;
  printf("count: %lu, seq: %lu\n", Tank::get_count(), Tank::get_seq());
  printf("t1: %s\n", t1->to_string());
  printf("t2: %s\n", t2->to_string());
  printf("t3: %s\n", t3.to_string());
  delete t1;
  t1 = NULL;
  printf("count: %lu, seq: %lu\n", Tank::get_count(), Tank::get_seq());

  return EXIT_SUCCESS;
}
