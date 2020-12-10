// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <stdlib.h>

#include <iostream>

#include "student.h"

int main(int argc, char **argv)
{
  Student *s1 = new Student("Terrence");
  Student s2 = *s1;

  s1->set_name("hello");
  delete s1;
  s1 = NULL;

  s2.set_name("world");

  return EXIT_SUCCESS;
}
