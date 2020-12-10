// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <stdio.h>

#include "shape.h"

double Shape::CalcArea()
{
  printf("Shape >>> CalcArea ...\n");
  return 0;
}

Shape::Shape() { printf("Shape >>> new ...\n"); }

Shape::~Shape() { printf("Shape >>> delete ...\n"); }
