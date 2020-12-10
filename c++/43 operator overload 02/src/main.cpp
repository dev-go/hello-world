// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <stdio.h>
#include <stdlib.h>

#include "coordinate.h"

Coordinate &operator-(Coordinate &coor)
{
  coor.x_ = -coor.x_;
  coor.y_ = -coor.y_;
  return coor;
}

int main(int argc, char **argv)
{
  Coordinate coor(6, 8);
  printf("%s\n", coor.to_string());
  -coor;
  printf("%s\n", coor.to_string());
  -(-coor);
  printf("%s\n", coor.to_string());

  return EXIT_SUCCESS;
}
