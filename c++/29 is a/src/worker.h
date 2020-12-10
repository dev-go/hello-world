// Copyright (c) 2020, devgo.club
// All rights reserved.

#pragma once

#include <stdint.h>

#include "person.h"

class Worker : public Person
{
public:
  char *to_string();
  Worker(int64_t id = 0);
  ~Worker();

  // protected:
public:
  int64_t id_;
};
