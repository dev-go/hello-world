// Copyright (c) 2020, devgo.club
// All rights reserved.

#pragma once

#include <stdint.h>

#include "match.h"

class Time
{
  friend void display(Time &t);
  friend void Match::set_time(Time &t, uint8_t hour, uint8_t min, uint8_t sec);

public:
  Time(uint8_t hour, uint8_t min, uint8_t sec);

private:
  uint8_t hour_;
  uint8_t min_;
  uint8_t sec_;
};
