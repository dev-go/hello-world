// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <string>

class Teacher
{
public:
  std::string get_name();
  void set_name(std::string _name);
  int get_age();
  void set_age(int _age);
  void teach();

private:
  std::string m_strName;
  int m_iAge;
};
