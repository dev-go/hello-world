// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <stdint.h>

#include "point.h"

class Line
{
public:
  Point a();
  Point b();
  void set_a(Point a);
  void set_b(Point b);
  char *to_string();
  Line(Point a = Point(0, 0), Point b = Point(0, 0));
  Line(int8_t ax, int8_t ay, int8_t bx, int8_t by);
  ~Line();

private:
  Point a_;
  Point b_;
};
