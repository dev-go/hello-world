// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <stdio.h>
#include <stdlib.h>

#include "bird.h"
#include "flyable.h"
#include "plane.h"

void fly(Flyable *f)
{
  f->takeoff();
  f->land();
}

int main(int argc, char **argv)
{
  Bird *b = new Bird();
  Plane *p = new Plane();

  fly(b);
  fly(p);

  return EXIT_SUCCESS;
}
