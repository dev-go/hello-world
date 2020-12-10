// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <stdlib.h>

#include <iostream>

#include "person.h"
#include "worker.h"

int main(int argc, char **argv)
{
  Worker *w = new Worker(666);
  std::cout << "==================" << std::endl;
  Person *p = w;
  std::cout << "==================" << std::endl;
  std::cout << p->to_string() << std::endl;
  std::cout << "==================" << std::endl;
  std::cout << w->to_string() << std::endl;
  std::cout << "==================" << std::endl;
  std::cout << "Worker id: " << w->id_ << std::endl;
  std::cout << "Person id: " << p->id_ << std::endl;
  std::cout << "==================" << std::endl;

  p = NULL;
  delete w;
  w = NULL;

  return EXIT_SUCCESS;
}
