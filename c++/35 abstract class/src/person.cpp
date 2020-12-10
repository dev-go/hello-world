// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <stdio.h>
#include <string.h>

#include "person.h"

char *Person::to_string()
{
  char *buf = new char[32];
  memset(buf, 0, 32);
  sprintf(buf, "Person{name: %s}", name_);
  return buf;
}

Person::Person(char *name)
{
  name_ = new char[16];
  memset(name_, 0, 16);
  strcpy(name_, name);
  printf("new\t >>> %s\n", to_string());
}

Person::Person(const Person &p)
{
  name_ = new char[16];
  memset(name_, 0, 16);
  strcpy(name_, p.name_);
  printf("copy\t >>> %s\n", to_string());
}

Person::~Person()
{
  printf("delete\t >>> %s\n", to_string());
  delete name_;
  name_ = NULL;
}
