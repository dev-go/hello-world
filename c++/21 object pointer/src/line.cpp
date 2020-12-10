// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include "line.h"
#include "point.h"

Point *Line::a() { return a_; }

Point *Line::b() { return b_; }

void Line::set_a(Point *a)
{
  a_ = a;
  return;
}

void Line::set_b(Point *b)
{
  b_ = b;
  return;
}

char *Line::to_string()
{
  char *buf = new char[256];
  memset(buf, 0, 256);
  sprintf(buf, "Line{a: %s, b: %s}", a_->to_string(), b_->to_string());
  return buf;
}

Line::Line(int64_t ax, int64_t ay, int64_t bx, int64_t by)
{
  a_ = new Point(ax, ay);
  b_ = new Point(bx, by);
  printf("new >>> %s\n", to_string());
}

Line::~Line()
{
  printf("delete >>> %s\n", to_string());
  delete a_;
  a_ = NULL;
  delete b_;
  b_ = NULL;
  printf("delete >>> Line done\n");
}
