// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <stdio.h>
#include <stdlib.h>

#include "coordinate.h"

int main(int argc, char **argv)
{
  Coordinate coor(6, 8);
  printf("x: %lf, y: %lf\n", coor.x(), coor.y());
  -coor;
  printf("x: %lf, y: %lf\n", coor.x(), coor.y());
  -(-coor);
  printf("x: %lf, y: %lf\n", coor.x(), coor.y());

  return EXIT_SUCCESS;
}
