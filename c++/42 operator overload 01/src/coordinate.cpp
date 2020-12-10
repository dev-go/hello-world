// Copyright (c) 2020, devgo.club
// All rights reserved.

#include "coordinate.h"

double Coordinate::x() { return x_; }

double Coordinate::y() { return y_; }

Coordinate &Coordinate::operator-()
{
  x_ = -x_;
  y_ = -y_;
  return (*this);
}

Coordinate::Coordinate(double x, double y) : x_(x), y_(y) {}
