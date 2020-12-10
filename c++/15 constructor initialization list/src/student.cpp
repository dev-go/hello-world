// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <stdint.h>

#include <iostream>
#include <string>

#include "student.h"

Student::Student(std::string homeland)
    : name_(""), homeland_(homeland){

                 };

Student::Student(std::string name, std::string homeland)
    : name_(name), homeland_(homeland){

                   };

std::string Student::name() { return name_; };

void Student::set_name(std::string name) { name_ = name; };

std::string Student::homeland() { return homeland_; };
