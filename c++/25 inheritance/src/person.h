// Copyright (c) 2020, devgo.club
// All rights reserved.

#pragma once

#include <stdint.h>

#include <string>

class Person
{
public:
  void eat();
  Person();
  ~Person();

public:
  std::string name_;
  uint8_t age_;
};
