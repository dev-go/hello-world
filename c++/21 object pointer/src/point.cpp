// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include "point.h"

int64_t Point::x() { return x_; }

int64_t Point::y() { return y_; }

void Point::set_x(int64_t x)
{
  x_ = x;
  return;
}

void Point::set_y(int64_t y)
{
  y_ = y;
  return;
}

char *Point::to_string()
{
  char *buf = new char[64];
  memset(buf, 0, 64);
  sprintf(buf, "Point{x: %ld, y: %ld}", x_, y_);
  return buf;
}

Point::Point(int64_t x, int64_t y) : x_(x), y_(y)
{
  printf("new >>> %s\n", to_string());
}

Point::Point(const Point &p) : x_(p.x_), y_(p.y_)
{
  printf("copy >>> %s\n", to_string());
}

Point::~Point() { printf("delete >>> %s\n", to_string()); }
