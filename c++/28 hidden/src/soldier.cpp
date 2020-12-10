// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <iostream>
#include <string>

#include "soldier.h"

void Soldier::play()
{
  std::cout << "Soldier{code: " << code << "} play ..." << std::endl;
}

void Soldier::work()
{
  std::cout << "Soldier work ..." << std::endl;
  std::cout << "Soldier code: " << code << std::endl;
  std::cout << "Person code: " << Person::code << std::endl;
}

Soldier::Soldier(int i_code, std::string str_code)
    : Person(str_code), code(i_code)
{
  std::cout << "new Soldier" << std::endl;
}
