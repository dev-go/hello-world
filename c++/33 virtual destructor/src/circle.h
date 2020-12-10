// Copyright (c) 2020, devgo.club
// All rights reserved.

#pragma once

#include "coordinate.h"
#include "shape.h"

class Circle : public Shape
{
public:
  virtual double CalcArea();
  char *String();
  Circle(double x, double y, double r);
  virtual ~Circle();

private:
  double r;
  Coordinate *coor;
};
