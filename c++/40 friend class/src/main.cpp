// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include "time.h"
#include "watch.h"

int main(int argc, char **argv)
{
  Watch w;
  w.time();
  w.set_time(6, 6, 6);
  w.time();

  return EXIT_SUCCESS;
}
