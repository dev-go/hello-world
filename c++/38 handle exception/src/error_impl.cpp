// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <stdio.h>
#include <string.h>

#include "error_impl.h"

char *ErrorImpl::error()
{
  char *buf = new char[64];
  memset(buf, 0, 64);
  strcpy(buf, error_);
  return buf;
}

ErrorImpl::ErrorImpl(char *error)
{
  error_ = new char[64];
  memset(error_, 0, 64);
  strcpy(error_, error);
}
