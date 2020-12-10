// Copyright (c) 2020, devgo.club
// All rights reserved.

#pragma once

#include <stdint.h>

class Person
{
public:
  uint64_t birth();
  void set_birth(uint64_t birth);
  void show_info();
  Person(uint64_t birth = 0);
  Person(const Person &p);
  virtual ~Person();

protected:
  uint64_t birth_;
};
