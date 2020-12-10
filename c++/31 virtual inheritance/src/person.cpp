// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include "person.h"

uint64_t Person::birth() { return birth_; }

void Person::set_birth(uint64_t birth)
{
  birth_ = birth;
  return;
}

void Person::show_info()
{
  printf("Person{birth: %lu}\n", birth_);
  return;
}

Person::Person(uint64_t birth) : birth_(birth) { printf("new Person >>>\n"); }

Person::Person(const Person &p)
{
  birth_ = p.birth_;
  printf("copy Person >>>\n");
}

Person::~Person() { printf("delete Person >>>\n"); }
