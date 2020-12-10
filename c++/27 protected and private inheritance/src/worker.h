// Copyright (c) 2020, devgo.club
// All rights reserved.

#pragma once

#include <stdint.h>

#include "person.h"

class Worker : protected Person
{
public:
  void work();
  Worker(char *name, int64_t id, int64_t salary);

protected:
  int64_t salary_;
};
