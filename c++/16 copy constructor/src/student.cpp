// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <stdint.h>

#include <iostream>
#include <string>

#include "student.h"

std::string Student::name() { return name_; };

void Student::set_name(std::string name) { name_ = name; };

uint8_t Student::age() { return age_; };

Student::Student(std::string name, uint8_t age) : name_(name), age_(age)
{
  std::cout << "new >>> Student{name: " << name_ << ", age: " << int(age_)
            << "}" << std::endl;
};

Student::Student(const Student &stu)
{
  name_ = stu.name_;
  age_ = stu.age_;
  std::cout << "copy >>> Student{name: " << name_ << ", age: " << int(age_)
            << "}" << std::endl;
};
