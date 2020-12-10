// Copyright (c) 2020, devgo.club
// All rights reserved.

#pragma once

#include "error.h"

class ErrorImpl : public Error
{
public:
  virtual char *error();
  ErrorImpl(char *error);

private:
  char *error_;
};
