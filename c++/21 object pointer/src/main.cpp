// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <stdlib.h>

#include <iostream>

#include "line.h"
#include "point.h"

int main(int argc, char **argv)
{
  Line *line = new Line(1, 2, 3, 4);
  Point *p1 = new Point(11, 12);
  Point *p2 = line->a();
  line->set_a(p1);
  delete p2;
  p2 = NULL;
  std::cout << (*line).to_string() << std::endl;
  std::cout << "=================" << std::endl;
  delete line;
  line = NULL;
  return EXIT_SUCCESS;
}
