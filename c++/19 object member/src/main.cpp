// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <stdlib.h>

#include <iostream>

#include "line.h"

int main(int argc, char **argv)
{
  Line *p = new Line();
  std::cout << p->to_string() << std::endl;
  delete p;
  p = NULL;

  return EXIT_SUCCESS;
}
