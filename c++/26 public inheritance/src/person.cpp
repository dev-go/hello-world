// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include "person.h"

void Person::run()
{
  printf("Person run ...\n%s\n", to_string());
  return;
}

char *Person::to_string()
{
  char *buf = new char[64];
  memset(buf, 0, 64);
  sprintf(buf, "Person{name: %s, id: %ld}", name_, id_);
  return buf;
}

Person::Person(char *name, int64_t id) : name_(name), id_(id) {}
