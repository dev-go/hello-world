// Copyright (c) 2020, devgo.club
// All rights reserved.

#pragma once

#include <stdint.h>

class Person
{
public:
  void run();
  char *to_string();
  Person(char *name, int64_t id);

protected:
  char *name_;

private:
  int64_t id_;
};
