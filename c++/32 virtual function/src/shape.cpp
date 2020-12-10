// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <stdio.h>

#include "shape.h"

double Shape::CalcArea()
{
  printf("Shape CalcArea ...\n");
  return 0;
}

Shape::Shape() { printf("new Shape ...\n"); };

Shape::~Shape() { printf("delete Shape ...\n"); }
