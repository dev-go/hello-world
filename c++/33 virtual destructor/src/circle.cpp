// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <stdio.h>
#include <string.h>

#include "circle.h"

double Circle::CalcArea()
{
  printf("Circle >>> CalcArea ...\n");
  return 3.14 * r * r;
}

char *Circle::String()
{
  char *buf = new char[64];
  memset(buf, 0, 64);
  sprintf(buf, "Coordinate{R: %lf, Coor: %s}", r, coor->String());
  return buf;
}

Circle::Circle(double x, double y, double r)
{
  this->r = r;
  coor = new Coordinate();
  coor->Set(x, y);
  printf("Circle >>> new ...\n");
}

Circle::~Circle()
{
  delete coor;
  coor = NULL;
  printf("Circle >>> delete ...\n");
}
