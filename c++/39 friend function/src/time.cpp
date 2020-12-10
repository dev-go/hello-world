// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <stdint.h>

#include "time.h"

Time::Time(uint8_t hour, uint8_t min, uint8_t sec)
    : hour_(hour), min_(min), sec_(sec) {}
