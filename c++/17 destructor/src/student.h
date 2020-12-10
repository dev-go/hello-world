// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <string>

class Student
{
public:
  Student(std::string name);
  Student(const Student &stu);
  ~Student();
  std::string name();
  void set_name(std::string name);

private:
  std::string name_;
};
