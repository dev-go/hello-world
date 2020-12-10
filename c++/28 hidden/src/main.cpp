// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <stdlib.h>

#include <iostream>

#include "soldier.h"

int main(int argc, char **argv)
{
  Soldier s(666, "888");
  s.work();
  std::cout << "*****************" << std::endl;
  s.play();
  std::cout << "*****************" << std::endl;
  s.Person::play();

  return EXIT_SUCCESS;
}
