// Copyright (c) 2020, devgo.club
// All rights reserved.

#pragma once

#include "shape.h"

class Circle : public Shape
{
public:
  double CalcArea();
  Circle(double r);
  ~Circle();

private:
  double r;
};
