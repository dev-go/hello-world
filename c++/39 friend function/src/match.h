// Copyright (c) 2020, devgo.club
// All rights reserved.

#pragma once

#include <stdint.h>

class Time;

class Match
{
public:
  void set_time(Time &t, uint8_t hour, uint8_t min, uint8_t sec);
};
