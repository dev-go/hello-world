// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include "coordinate.h"

char *Coordinate::to_string()
{
  char *buf = new char[32];
  memset(buf, 0, 32);
  sprintf(buf, "Coordinate{x: %hhd, y: %hhd}", x_, y_);
  return buf;
}

Coordinate &Coordinate::operator++()
{
  x_++;
  y_++;
  return *this;
}

Coordinate Coordinate::operator++(int)
{
  Coordinate tmp(*this);
  x_++;
  y_++;
  return tmp;
}

Coordinate::Coordinate(int8_t x, int8_t y) : x_(x), y_(y) {}

Coordinate::Coordinate(const Coordinate &coor) : x_(coor.x_), y_(coor.y_) {}
