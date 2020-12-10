// Copyright (c) 2020, devgo.club
// All rights reserved.

#pragma once

#include <stdint.h>

#include "person.h"

class Worker : public Person
{
public:
  void work();
  char *to_string();
  Worker(char *name, int64_t id, int64_t salary);

private:
  int64_t salary_;
};
