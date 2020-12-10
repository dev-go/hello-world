// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <stdint.h>
#include <stdlib.h>

#include <iostream>
#include <list>
#include <map>
#include <string>
#include <vector>

int main(int argc, char **argv)
{
  std::vector<std::string> vec;
  vec.push_back("hello");
  vec.push_back("world");
  vec.push_back("dev");
  vec.push_back("c++");
  std::vector<std::string>::iterator iter1 = vec.begin();
  for (; iter1 != vec.end(); iter1++)
  {
    std::cout << *iter1 << std::endl;
  }

  std::cout << "=========================" << std::endl;

  std::map<std::string, uint64_t> m;
  std::pair<std::string, uint64_t> p1("Beijing", 100);
  std::pair<std::string, uint64_t> p2("Shanghai", 90);
  m.insert(p1);
  m.insert(p2);
  std::map<std::string, uint64_t>::iterator iter2 = m.begin();
  for (; iter2 != m.end(); iter2++)
  {
    std::cout << iter2->first << " : " << iter2->second << std::endl;
  }

  return EXIT_SUCCESS;
}
