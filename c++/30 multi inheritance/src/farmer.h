// Copyright (c) 2020, devgo.club
// All rights reserved.

#pragma once

#include <stdint.h>

class Farmer
{
public:
  int64_t id() const;
  void set_id(int64_t id);
  char *to_string();
  void sow();
  Farmer();
  Farmer(const Farmer &f);
  ~Farmer();

protected:
  int64_t id_;
};
