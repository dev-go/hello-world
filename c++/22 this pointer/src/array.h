// Copyright (c) 2020, devgo.club
// All rights reserved.

#pragma once

#include <stdint.h>

class Array
{
public:
  uint64_t get_len();
  bool get_value(uint64_t index, double *value);
  bool set_value(uint64_t index, double value);
  Array(uint64_t len);
  ~Array();

private:
  uint64_t len;
  double *arr;
};
