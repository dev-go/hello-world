// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <stdint.h>
#include <stdlib.h>

#include <iostream>

#include "student.h"

void test(Student stu) { std::cout << "do nothing ..." << std::endl; }

int main(int argc, char **argv)
{
  Student s1 = Student("Terrence", 18);
  Student s2(s1);
  Student s3 = s1;
  test(s1);

  return EXIT_SUCCESS;
}
