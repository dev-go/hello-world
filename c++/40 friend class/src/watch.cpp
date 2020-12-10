// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <stdint.h>
#include <stdio.h>

#include "time.h"
#include "watch.h"

void Watch::time()
{
  printf("Time: <%02hhu:%02hhu:%02hhu>\n", time_.hour_, time_.min_, time_.sec_);
  return;
}

void Watch::set_time(uint8_t hour, uint8_t min, uint8_t sec)
{
  time_.hour_ = hour;
  time_.min_ = min;
  time_.sec_ = sec;
}
