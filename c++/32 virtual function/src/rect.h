// Copyright (c) 2020, devgo.club
// All rights reserved.

#pragma once

#include "shape.h"

class Rect : public Shape
{
public:
  double CalcArea();
  Rect(double width, double height);
  ~Rect();

private:
  double width;
  double height;
};
