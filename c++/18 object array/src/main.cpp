// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <stdint.h>
#include <stdlib.h>

#include <iostream>

#include "coordinate.h"

int main(int argc, char **argv)
{
  Coordinate arr[3];
  arr[0].set_x(100.001);
  arr[0].set_y(100.002);
  arr[1].set_x(200.001);
  arr[1].set_y(200.002);
  arr[2].set_x(300.001);
  arr[2].set_y(300.002);

  Coordinate coor = arr[2];
  std::cout << coor.to_string() << std::endl;

  std::cout << "==============" << std::endl;

  Coordinate *p = new Coordinate[4];
  p->set_x(1000);
  p->set_y(1001);
  (p + 1)->set_x(2000);
  (p + 1)->set_y(2002);
  p[2].set_x(3000);
  p[2].set_y(3003);
  3 [p].set_x(4000);
  3 [p].set_y(4004);
  for (uint8_t i = 0; i < 4; i++)
  {
    std::cout << (p + i)->to_string() << std::endl;
  }
  delete[] p;
  p = NULL;

  std::cout << "==============" << std::endl;

  return EXIT_SUCCESS;
}
