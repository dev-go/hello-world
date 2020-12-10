// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <stdint.h>

class Array
{
public:
  uint64_t count();
  bool get(uint64_t index, double *value);
  bool set(uint64_t index, double value);
  Array(uint64_t count);
  Array(const Array &arr);
  ~Array();

private:
  const uint64_t count_;
  double *value_list_;
};
