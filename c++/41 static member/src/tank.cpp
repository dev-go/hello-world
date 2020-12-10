// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include "tank.h"

uint64_t Tank::count_ = 0;
uint64_t Tank::seq_ = 10000;

Tank::Tank()
{
  count_++;
  seq_++;
  id_ = get_seq();
}

Tank::Tank(const Tank &tank)
{
  count_++;
  id_ = tank.id_;
}

Tank::~Tank() { count_--; }

char *Tank::to_string()
{
  char *buf = new char[32];
  memset(buf, 0, 32);
  sprintf(buf, "Tank{id: %lu}", id_);
  return buf;
}

uint64_t Tank::get_count() { return count_; }

uint64_t Tank::get_seq() { return seq_; }
