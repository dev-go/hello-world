// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <stdio.h>
#include <stdlib.h>

#include "coordinate.h"

int main(int argc, char **argv)
{
  Coordinate coor(1, 2);
  printf("%s\n", coor.to_string());
  ++(++coor);
  printf("%s\n", coor.to_string());
  Coordinate old = coor++;
  printf("old: %s\n", old.to_string());
  printf("%s\n", coor.to_string());

  return EXIT_SUCCESS;
}
