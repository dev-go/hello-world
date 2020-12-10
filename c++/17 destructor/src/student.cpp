// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <iostream>
#include <string>

#include "student.h"

Student::Student(std::string name) : name_(name)
{
  std::cout << "new >>> Student{name: " << name << "}" << std::endl;
};

Student::Student(const Student &stu)
{
  name_ = stu.name_;
  std::cout << "copy >>> Student{name: " << stu.name_ << "}" << std::endl;
};

Student::~Student()
{
  std::cout << "delete >>> Student{name: " << name_ << "}" << std::endl;
};

std::string Student::name() { return name_; };

void Student::set_name(std::string name) { name_ = name; };
