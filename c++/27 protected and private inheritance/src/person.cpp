// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include "person.h"

char *Person::to_string()
{
  char *buf = new char[32];
  memset(buf, 0, 32);
  sprintf(buf, "Person{name: %s, id: %ld}", name_, id_);
  return buf;
}

Person::Person(char *name, int64_t id) : name_(name), id_(id)
{
  printf("new Person\n%s\n", to_string());
  return;
}
