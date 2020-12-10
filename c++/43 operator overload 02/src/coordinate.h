// Copyright (c) 2020, devgo.club
// All rights reserved.

#pragma once

class Coordinate
{
  friend Coordinate &operator-(Coordinate &coor);

public:
  char *to_string();
  Coordinate(double x = 0, double y = 0);

private:
  double x_;
  double y_;
};
