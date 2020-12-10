// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <stdlib.h>

#include <iostream>

#include "point.h"

int main(int argc, char **argv)
{
  Point p1(1, 2);
  Point &p2 = p1;
  Point *p3 = &p1;
  std::cout << "p1: " << p1.to_string() << std::endl;
  std::cout << "p2: " << p2.to_string() << std::endl;
  std::cout << "p3: " << p3->to_string() << std::endl;

  std::cout << "\n\n=======================\n\n\n";

  Point const &p4 = p1;
  Point const *p5 = &p1;
  // std::cout << "p4.x: " << p4.x() << std::endl;
  std::cout << "p4: " << p4.to_string() << std::endl;
  // std::cout << "p5->x: " << p5->x() << std::endl;
  std::cout << "p5: " << p5->to_string() << std::endl;

  std::cout << "\n\n=======================\n\n\n";

  Point p6(11, 12);
  Point *const p7 = &p1;
  std::cout << "p7->x: " << int(p7->x()) << std::endl;
  std::cout << "p7: " << p7->to_string() << std::endl;
  // p7 = &p6;
  *p7 = p6;
  std::cout << "p7->x: " << int(p7->x()) << std::endl;
  std::cout << "p7: " << p7->to_string() << std::endl;

  return EXIT_SUCCESS;
}
