// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include "point.h"

int8_t Point::x() const { return x_; }

int8_t Point::y() const { return y_; }

void Point::set_x(int8_t x) { x_ = x; }

void Point::set_y(int8_t y) { y_ = y; }

char *Point::to_string() const
{
  char *buf = new char[32];
  memset(buf, 0, 32);
  sprintf(buf, "Point{x: %hhd, y: %hhd}", x_, y_);
  return buf;
}

Point::Point(int8_t x, int8_t y) : x_(x), y_(y)
{
  printf("new Point >>>\n%s\n<<<\n", to_string());
}

Point::Point(const Point &p)
{
  printf("copy Point >>>\n%s\n<<<\n", to_string());
}

Point::~Point() { printf("delete Point >>>\n%s\n<<<\n", to_string()); }
