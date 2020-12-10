// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <stdlib.h>

#include <iostream>

#include "line.h"
#include "point.h"

int main(int argc, char **argv)
{
  Line line(1, 2, 3, 4);
  line.change();
  std::cout << line.to_string() << std::endl;
  std::cout << "=======================\n\n\n\n";

  Line const l(5, 6, 7, 8);
  l.change();
  std::cout << "=======================\n\n\n\n";

  return EXIT_SUCCESS;
}
