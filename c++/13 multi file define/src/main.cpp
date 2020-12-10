// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <stdlib.h>

#include <iostream>
#include <string>

#include "Teacher.h"

int main(int argc, char **argv)
{
  Teacher *t = new Teacher();
  if (t == NULL)
  {
    std::cout << "create new teacher failed" << std::endl;
    return EXIT_FAILURE;
  }
  t->set_name("Terrence");
  t->set_age(18);
  std::cout << "name: " << t->get_name() << ", age: " << t->get_age()
            << std::endl;
  t->teach();

  return EXIT_SUCCESS;
}
