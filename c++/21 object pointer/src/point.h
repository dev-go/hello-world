// Copyright (c) 2020, devgo.club
// All rights reserved.

#pragma once

#include <stdint.h>

class Point
{
public:
  int64_t x();
  int64_t y();
  void set_x(int64_t x);
  void set_y(int64_t y);
  char *to_string();
  Point(int64_t x = 0, int64_t y = 0);
  Point(const Point &p);
  ~Point();

private:
  int64_t x_;
  int64_t y_;
};
