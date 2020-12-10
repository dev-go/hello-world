// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <stdio.h>
#include <stdlib.h>

#include "circle.h"
#include "coordinate.h"
#include "shape.h"

int main(int argc, char **argv)
{
  Shape *c = new Circle(1, 2, 10);
  printf("============================\n");
  delete c;
  c = NULL;

  return EXIT_SUCCESS;
}
