// Copyright (c) 2020, devgo.club
// All rights reserved.

#pragma once

#include <string>

#include "person.h"

class Soldier : public Person
{
public:
  void play();
  void work();
  Soldier(int i_code = 0, std::string str_code = "");

protected:
  int code;
};
