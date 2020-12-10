// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include "line.h"

char *Line::to_string()
{
  char *buf = new char[64];
  memset(buf, 0, 64);
  sprintf(buf, "Line{a: %s, b: %s}", a_.to_string(), b_.to_string());
  return buf;
}

Line::Line(int8_t ax, int8_t ay, int8_t bx, int8_t by)
    : a_(ax, ay), b_(bx, by)
{
  printf("new Line >>>\n%s\n<<<\n", to_string());
}

void Line::change()
{
  b_.set_x(22);
  printf("change()\n");
}

void Line::change() const
{
  printf("a.x: %hhd\n", a_.x());
  printf("b.x: %hhd\n", b_.x());
  printf("change() const\n");
}
