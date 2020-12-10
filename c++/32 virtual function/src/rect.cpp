// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <stdio.h>

#include "rect.h"

double Rect::CalcArea()
{
  printf("Rect CalcArea ...\n");
  return width * height;
}

Rect::Rect(double width, double height)
{
  this->width = width;
  this->height = height;
  printf("new Rect ...\n");
}

Rect::~Rect() { printf("delete Rect ...\n"); }
