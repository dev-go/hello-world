// Copyright (c) 2020, devgo.club
// All rights reserved.

#pragma once

#include <stdint.h>

class Watch;

class Time
{
  friend class Watch;

public:
  Time(uint8_t hour_ = 0, uint8_t min_ = 0, uint8_t sec_ = 0);

private:
  uint8_t hour_;
  uint8_t min_;
  uint8_t sec_;
};
