// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <stdio.h>
#include <string.h>

#include <string>

#include "coordinate.h"

double Coordinate::x() { return x_; }

double Coordinate::y() { return y_; }

void Coordinate::set_x(double x)
{
  x_ = x;
  return;
}

void Coordinate::set_y(double y)
{
  y_ = y;
  return;
}

std::string Coordinate::to_string()
{
  char buf[100];
  memset(buf, 0, 100);
  sprintf(buf, "Coordinate{x: %lf, y: %lf}", x_, y_);
  std::string result(buf);
  return result;
}

Coordinate::Coordinate(double x, double y) : x_(x), y_(y)
{
  printf("new >>> Coordinate{x: %lf, y: %lf}\n", x, y);
  return;
}

Coordinate::Coordinate(const Coordinate &coordinate)
{
  x_ = coordinate.x_;
  y_ = coordinate.y_;
  printf("copy >>> Coordinate{x: %lf, y:%lf}\n", x_, y_);
  return;
}

Coordinate::~Coordinate()
{
  printf("delete >>> Coordinate{x: %lf, y:%lf}\n", x_, y_);
  return;
}
