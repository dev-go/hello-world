// Copyright (c) 2020, devgo.club
// All rights reserved.

#pragma once

#include <stdint.h>

#include "person.h"

class Farmer : virtual public Person
{
public:
  int64_t id() const;
  void set_id(int64_t id);
  char *to_string();
  void sow();
  Farmer();
  Farmer(const Farmer &f);
  virtual ~Farmer();

protected:
  int64_t id_;
};
