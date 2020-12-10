// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include "point.h"

int8_t Point::x() { return x_; }

int8_t Point::y() { return y_; }

void Point::set_x(int8_t x)
{
  x_ = x;
  return;
}

void Point::set_y(int8_t y)
{
  y_ = y;
  return;
}

char *Point::to_string()
{
  char *buf = new char[100];
  memset(buf, 0, 100);
  sprintf(buf, "Point{x: %hhd, y: %hhd}", x_, y_);
  return buf;
}

Point::Point(int8_t x, int8_t y) : x_(x), y_(y)
{
  printf("new >>> Point{x: %hhd, y: %hhd}\n", x_, y_);
}

Point::Point(const Point &p)
{
  x_ = p.x_;
  y_ = p.y_;
  printf("copy >>> Point{x: %hhd, y: %hhd}\n", x_, y_);
};

Point::~Point() { printf("delete >>> Point{x: %hhd, y: %hhd}\n", x_, y_); }
