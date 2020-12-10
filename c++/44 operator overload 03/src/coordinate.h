// Copyright (c) 2020, devgo.club
// All rights reserved.

#pragma once

#include <stdint.h>

class Coordinate
{
public:
  char *to_string();
  Coordinate &operator++();
  Coordinate operator++(int);
  Coordinate(int8_t x = 0, int8_t y = 0);
  Coordinate(const Coordinate &coor);

private:
  int8_t x_;
  int8_t y_;
};
