// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <stdint.h>

#include <iostream>

class Student
{
public:
  Student(std::string name, uint8_t age);
  Student(const Student &stu);
  std::string name();
  void set_name(std::string name);
  uint8_t age();

private:
  std::string name_;
  uint8_t age_;
};
