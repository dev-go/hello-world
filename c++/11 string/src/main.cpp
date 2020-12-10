// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <stdint.h>
#include <stdlib.h>

#include <iostream>
#include <string>

int main(int argc, char **argv)
{
  std::cout << "initialize ..." << std::endl;
  std::string s1 = "c++";
  std::string s2("programming");
  std::string s3(s2);
  std::string s4(6, 'x');
  std::string s5;
  std::cout << "s1: " << s1 << ", s2: " << s2 << ", s3: " << s3
            << ", s4: " << s4 << ", s5: " << s5 << std::endl;
  std::cout << "====================================================="
            << std::endl;

  std::cout << "operate ..." << std::endl;
  std::cout << "s1 is empty: " << std::boolalpha << s1.empty() << std::endl;
  std::cout << "s1 size: " << s1.size() << std::endl;
  std::cout << "s1[0]: " << s1[0] << ", s1[1]: " << s1[1] << std::endl;
  std::cout << "s1 + s2: " << (s1 + s2) << std::endl;
  // std::cout << "\"hello\" + \"world\": " << ("hello" + "world") << std::endl;
  // // error: invalid operands to binary expression ('const char *' and 'const
  // char *')

  return EXIT_SUCCESS;
}
