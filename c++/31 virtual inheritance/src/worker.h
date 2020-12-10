// Copyright (c) 2020, devgo.club
// All rights reserved.

#pragma once

#include "person.h"

class Worker : virtual public Person
{
public:
  char *name() const;
  void set_name(char *name);
  char *to_string();
  void work();
  Worker();
  Worker(const Worker &w);
  virtual ~Worker();

protected:
  char *name_;
};
