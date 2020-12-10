// Copyright (c) 2020, devgo.club
// All rights reserved.

#pragma once

#include <stdint.h>

#include "person.h"

class Worker : public Person
{
public:
  virtual char *to_string();
  virtual void work();
  Worker(char *name = (char *)"", uint64_t id = 0);
  Worker(const Worker &w);
  virtual ~Worker();

private:
  uint64_t id_;
};
