// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "match.h"
#include "time.h"

void display(Time &t);

int main(int argc, char **argv)
{
  Time t(6, 6, 6);
  display(t);
  Match m;
  m.set_time(t, 8, 8, 8);
  display(t);

  return EXIT_SUCCESS;
}

void display(Time &t)
{
  printf("Time <%02hhu:%02hhu:%02hhu>\n", t.hour_, t.min_, t.sec_);
}
