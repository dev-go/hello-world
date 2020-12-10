// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <stdint.h>
#include <stdlib.h>

#include <iostream>

#include "student.h"

int main(int argc, char **argv)
{
  Student *s1 = new Student("China, Shandong");
  s1->set_name("Terrence");
  std::cout << "name: " << s1->name() << std::endl;
  std::cout << "homeland: " << s1->homeland() << std::endl;

  return EXIT_SUCCESS;
}
