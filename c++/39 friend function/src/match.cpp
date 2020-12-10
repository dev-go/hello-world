// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <stdint.h>
#include <stdio.h>

#include "match.h"
#include "time.h"

void Match::set_time(Time &t, uint8_t hour, uint8_t min, uint8_t sec)
{
  t.hour_ = hour;
  t.min_ = min;
  t.sec_ = sec;
}
