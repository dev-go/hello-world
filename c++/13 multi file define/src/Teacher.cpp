// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <iostream>
#include <string>

#include "Teacher.h"

std::string Teacher::get_name() { return m_strName; }

void Teacher::set_name(std::string _name) { m_strName = _name; }

int Teacher::get_age() { return m_iAge; }

void Teacher::set_age(int _age) { m_iAge = _age; }

void Teacher::teach() { std::cout << "teaching ..." << std::endl; }
