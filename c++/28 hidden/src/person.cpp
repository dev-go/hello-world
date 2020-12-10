// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <iostream>
#include <string>

#include "person.h"

void Person::play()
{
  std::cout << "Person{code: " << code << "} play ..." << std::endl;
}

Person::Person(std::string code) : code(code)
{
  std::cout << "new Person" << std::endl;
}
