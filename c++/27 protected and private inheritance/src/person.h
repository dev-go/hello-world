// Copyright (c) 2020, devgo.club
// All rights reserved.

#pragma once

#include <stdint.h>

class Person
{
public:
  char *to_string();
  Person(char *name, int64_t id);

public:
  char *name_;

protected:
  int64_t id_;
};
