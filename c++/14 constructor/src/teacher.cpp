// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <stdint.h>

#include <string>

#include "teacher.h"

Teacher::Teacher()
{
  name_ = "";
  age_ = 0;
}

Teacher::Teacher(std::string name, uint8_t age)
{
  name_ = name;
  age_ = age;
}

std::string Teacher::name() { return name_; };

void Teacher::set_name(std::string name) { name_ = name; };

uint8_t Teacher::age() { return age_; };

void Teacher::set_age(uint8_t age) { age_ = age; };
