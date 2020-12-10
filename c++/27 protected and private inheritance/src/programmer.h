// Copyright (c) 2020, devgo.club
// All rights reserved.

#pragma once

#include <stdint.h>

#include "worker.h"

class Programmer : private Worker
{
public:
  void dev();
  Programmer(char *name, int64_t id, int64_t salary);
};
