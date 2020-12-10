// Copyright (c) 2020, devgo.club
// All rights reserved.

#pragma once

#include <stdint.h>

class Tank
{
public:
  Tank();
  Tank(const Tank &tank);
  ~Tank();
  char *to_string();
  static uint64_t get_count();
  static uint64_t get_seq();

private:
  static uint64_t count_;
  static uint64_t seq_;
  uint64_t id_;
};
