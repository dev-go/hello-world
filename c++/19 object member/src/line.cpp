// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include "line.h"

Point Line::a() { return a_; }

Point Line::b() { return b_; }

void Line::set_a(Point a)
{
  a_ = a;
  return;
}

void Line::set_b(Point b)
{
  b_ = b;
  return;
}

char *Line::to_string()
{
  char *buf = new char[100];
  memset(buf, 0, 100);
  sprintf(buf, "Line{a: %s, b: %s}", a_.to_string(), b_.to_string());
  return buf;
}

Line::Line(Point a, Point b) : a_(a), b_(b)
{
  printf("new >>> Line{a: %s, b: %s}\n", a_.to_string(), b_.to_string());
}

Line::Line(int8_t ax, int8_t ay, int8_t bx, int8_t by)
    : a_(ax, ay), b_(bx, by)
{
  printf("new >>> Line: {a.x: %hhd, a.y: %hhd, b.x:%hhd, b.y: %hhd}\n", ax, ay,
         bx, by);
}

Line::~Line()
{
  printf("delete >>> Line{a: %s, b: %s}\n", a_.to_string(), b_.to_string());
}
