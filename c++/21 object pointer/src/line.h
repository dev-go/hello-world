// Copyright (c) 2020, devgo.club
// All rights reserved.

#pragma once

#include <stdint.h>

#include "point.h"

class Line
{
public:
  Point *a();
  Point *b();
  void set_a(Point *a);
  void set_b(Point *b);
  char *to_string();
  Line(int64_t ax = 0, int64_t ay = 0, int64_t bx = 0, int64_t by = 0);
  ~Line();

private:
  Point *a_;
  Point *b_;
};
