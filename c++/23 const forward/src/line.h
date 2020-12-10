// Copyright (c) 2020, devgo.club
// All rights reserved.

#pragma once

#include <stdint.h>

#include "point.h"

class Line
{
public:
  char *to_string();
  Line(int8_t ax, int8_t ay, int8_t bx, int8_t by);
  void change();
  void change() const;

private:
  Point const a_;
  Point b_;
};
