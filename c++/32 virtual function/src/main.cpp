// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <stdio.h>
#include <stdlib.h>

#include "circle.h"
#include "rect.h"
#include "shape.h"

int main(int argc, char **argv)
{
  Shape *c = new Circle(10);
  Shape *r = new Rect(3, 4);
  printf("Circle Area: %lf\n", c->CalcArea());
  printf("Rect Area: %lf\n", r->CalcArea());
  delete c;
  c = NULL;
  delete r;
  r = NULL;
  return EXIT_SUCCESS;
}
