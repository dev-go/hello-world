// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <stdint.h>
#include <stdlib.h>

#include <iostream>
#include <string>

#include "teacher.h"

int main(int argc, char **argv)
{
  Teacher *t1 = new Teacher();
  t1->set_name("Liu");
  t1->set_age(16);
  std::cout << "name: " << t1->name() << ", age: " << int(t1->age())
            << std::endl;

  Teacher *t2 = new Teacher("Terrence", 18);
  std::cout << "name: " << t2->name() << ", age: " << int(t2->age())
            << std::endl;

  delete t1;
  t1 = NULL;
  delete t2;
  t2 = NULL;

  return EXIT_SUCCESS;
}
