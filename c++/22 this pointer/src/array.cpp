// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <stdint.h>
#include <stdio.h>

#include "array.h"

uint64_t Array::get_len() { return this->len; }

bool Array::get_value(uint64_t index, double *value)
{
  if (index >= this->len)
  {
    return false;
  }
  *value = (this->arr)[index];
  return true;
}

bool Array::set_value(uint64_t index, double value)
{
  if (index >= this->len)
  {
    return false;
  }
  (this->arr)[index] = value;
  return true;
}

Array::Array(uint64_t len)
{
  this->len = len;
  this->arr = new double[len];
  for (uint64_t i = 0; i < len; i++)
  {
    this->arr[i] = 0;
  }
  printf("new >>> Array\n");
};

Array::~Array()
{
  delete[](this->arr);
  printf("delete >>> Array\n");
}
