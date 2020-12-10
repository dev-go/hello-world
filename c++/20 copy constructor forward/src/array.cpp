// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include "array.h"

uint64_t Array::count() { return count_; }

bool Array::get(uint64_t index, double *value)
{
  if (index >= count_)
  {
    return false;
  }
  *value = value_list_[index];
  return true;
}

bool Array::set(uint64_t index, double value)
{
  if (index >= count_)
  {
    return false;
  }
  value_list_[index] = value;
  return true;
}

Array::Array(uint64_t count) : count_(count)
{
  value_list_ = new double[count_];
  for (int64_t i = 0; i < count_; i++)
  {
    value_list_[i] = 0;
  }
  printf("new >>>\n");
}

Array::Array(const Array &arr) : count_(arr.count_)
{
  value_list_ = new double[count_];
  for (uint64_t i = 0; i < count_; i++)
  {
    value_list_[i] = arr.value_list_[i];
  }
  printf("copy >>>\n");
}

Array::~Array()
{
  delete[] value_list_;
  value_list_ = NULL;
  printf("delete >>>\n");
}
