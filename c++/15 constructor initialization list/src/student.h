// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <stdint.h>

#include <string>

class Student
{
public:
  Student(std::string homeland);
  Student(std::string name, std::string homeland);
  std::string name();
  void set_name(std::string name);
  std::string homeland();

private:
  std::string name_;
  const std::string homeland_;
};
