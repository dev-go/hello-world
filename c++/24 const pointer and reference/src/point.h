// Copyright (c) 2020, devgo.club
// All rights reserved.

#pragma once

#include <stdint.h>

class Point
{
public:
  int8_t x();
  int8_t y();
  void set_x(int8_t x);
  void set_y(int8_t y);
  char *to_string() const;
  Point(int8_t x = 0, int8_t y = 0);

private:
  int8_t x_;
  int8_t y_;
};
