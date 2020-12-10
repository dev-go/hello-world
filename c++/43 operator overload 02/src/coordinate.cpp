// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <stdio.h>
#include <string.h>

#include "coordinate.h"

char *Coordinate::to_string()
{
  char *buf = new char[32];
  memset(buf, 0, 32);
  sprintf(buf, "Coordinate{x: %lf, y: %lf}", x_, y_);
  return buf;
}

Coordinate::Coordinate(double x, double y) : x_(x), y_(y) {}
