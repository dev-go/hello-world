// Copyright (c) 2020, devgo.club
// All rights reserved.

#pragma once

#include <stdint.h>

#include "time.h"

class Watch
{
public:
  void time();
  void set_time(uint8_t hour, uint8_t min, uint8_t sec);

private:
  Time time_;
};
