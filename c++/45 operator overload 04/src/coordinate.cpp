// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <stdint.h>

#include "coordinate.h"

// Coordinate Coordinate::operator+(const Coordinate &coor)
// {
//     Coordinate tmp;
//     tmp.x_ = x_ + coor.x_;
//     tmp.y_ = y_ + coor.y_;
//     return tmp;
// }

int32_t Coordinate::operator[](uint8_t index)
{
  if (index == 0)
  {
    return x_;
  }
  if (index == 1)
  {
    return y_;
  }
  return 0;
}

Coordinate::Coordinate(int32_t x, int32_t y) : x_(x), y_(y) {}

Coordinate::Coordinate(const Coordinate &coor) : x_(coor.x_), y_(coor.y_) {}
