// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <stdio.h>
#include <string.h>

#include "coordinate.h"

void Coordinate::Set(double x, double y)
{
  this->x = x;
  this->y = y;
}

char *Coordinate::String()
{
  char *buf = new char[32];
  memset(buf, 0, 32);
  sprintf(buf, "Coordinate{X: %lf, y: %lf}", x, y);
  return buf;
}

Coordinate::Coordinate() : x(0), y(0) { printf("Coordinate >>> new ...\n"); }

Coordinate::~Coordinate() { printf("Coordinate >>> delete ...\n"); }
