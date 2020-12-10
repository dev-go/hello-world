// Copyright (c) 2020, devgo.club
// All rights reserved.

#pragma once

#include <string>

class Person
{
public:
  void play();
  Person(std::string code = "");

protected:
  std::string code;
};
