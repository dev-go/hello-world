// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <stdio.h>

#include "circle.h"

double Circle::CalcArea()
{
  printf("Circle CalcArea ...\n");
  return 3.14 * r * r;
}

Circle::Circle(double r)
{
  this->r = r;
  printf("new Circle ...\n");
}

Circle::~Circle() { printf("delete Circle ...\n"); }
