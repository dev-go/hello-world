// Copyright (c) 2020, devgo.club
// All rights reserved.

#pragma once

#include <stdint.h>

class Person
{
public:
  char *to_string();
  Person(int64_t id = 0);
  ~Person();

  // protected:
public:
  int64_t id_;
};
