// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <stdint.h>
#include <stdlib.h>

#include <iostream>

#include "coordinate.h"

Coordinate operator+(const Coordinate &c1, const Coordinate &c2)
{
  Coordinate tmp;
  tmp.x_ = c1.x_ + c2.x_;
  tmp.y_ = c1.y_ + c2.y_;
  return tmp;
}

std::ostream &operator<<(std::ostream &output, const Coordinate &coor)
{
  output << "Coordinate{x: " << coor.x_ << ", y: " << coor.y_ << "}";
  return output;
}

int main(int argc, char **argv)
{
  Coordinate c1(1, 2);
  std::cout << c1 << std::endl;
  Coordinate c2(7, 9);
  std::cout << c2 << std::endl;
  Coordinate c3 = c1 + c2;
  std::cout << c3 << std::endl;
  std::cout << c3[0] << std::endl;
  std::cout << c3[1] << std::endl;

  return EXIT_SUCCESS;
}
