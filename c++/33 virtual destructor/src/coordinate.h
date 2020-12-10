// Copyright (c) 2020, devgo.club
// All rights reserved.

#pragma once

class Coordinate
{
public:
  void Set(double x, double y);
  char *String();
  Coordinate();
  ~Coordinate();

private:
  double x;
  double y;
};
