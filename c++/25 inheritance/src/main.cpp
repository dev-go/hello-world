// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <stdlib.h>

#include <iostream>

#include "person.h"
#include "worker.h"

int main(int argc, char **argv)
{
  Worker *w = new Worker();
  w->name_ = "Terrence";
  w->age_ = 18;
  w->salary_ = 10000;
  std::cout << "name: " << w->name_ << ", age: " << int(w->age_)
            << ", salary: " << w->salary_ << std::endl;
  w->eat();
  w->work();
  delete w;
  w = NULL;
  return EXIT_SUCCESS;
}
