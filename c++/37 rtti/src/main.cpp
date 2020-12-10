// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <iostream>
#include <typeinfo>

#include "bird.h"
#include "flyable.h"
#include "plane.h"

void demo(Flyable *f)
{
  printf("demo >>>\n");
  f->takeoff();
  printf("==========================\n");
  if (typeid(*f) == typeid(Bird))
  {
    Bird *b = dynamic_cast<Bird *>(f);
    b->foraging();
  }
  if (typeid(*f) == typeid(Plane))
  {
    Plane *p = dynamic_cast<Plane *>(f);
    p->carry();
  }
  printf("==========================\n");
  f->land();
  printf("demo <<<\n");
  return;
}

int main(int argc, char **argv)
{
  Bird b;
  demo(&b);

  Plane p;
  demo(&p);

  std::cout << "-----------------------------------------" << std::endl;

  Flyable *f = new Bird();
  std::cout << typeid(f).name() << std::endl;
  std::cout << typeid(*f).name() << std::endl;

  return EXIT_SUCCESS;
}
