// Copyright (c) 2020, devgo.club
// All rights reserved.

#pragma once

#include <stdint.h>

#include "person.h"

class Worker : public Person
{
public:
  void work();
  Worker();
  ~Worker();

public:
  int64_t salary_;
};
