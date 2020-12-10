// Copyright (c) 2020, devgo.club
// All rights reserved.

#pragma once

class Coordinate
{
public:
  double x();
  double y();
  Coordinate &operator-();
  Coordinate(double x = 0, double y = 0);

private:
  double x_;
  double y_;
};
