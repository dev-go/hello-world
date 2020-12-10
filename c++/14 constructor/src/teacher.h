// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <stdint.h>

#include <string>

class Teacher
{
public:
  Teacher();
  Teacher(std::string name, uint8_t age);
  std::string name();
  void set_name(std::string name);
  uint8_t age();
  void set_age(uint8_t age);

private:
  std::string name_;
  uint8_t age_;
};
