// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <stdint.h>
#include <stdlib.h>

#include <iostream>
#include <string>

class Student
{
public:
  std::string get_name() { return m_strName; };
  void set_name(std::string _name) { m_strName = _name; };
  int get_score() { return m_iScore; }
  void study(int _score) { m_iScore += _score; }

private:
  std::string m_strName;
  int m_iScore;
};

int main(int argc, char **argv)
{
  Student *stu = new Student();
  if (stu == NULL)
  {
    std::cout << "create new student failed" << std::endl;
    return EXIT_FAILURE;
  }
  stu->set_name("Terrence");
  stu->study(60);
  stu->study(60);

  std::cout << "name: " << stu->get_name() << ", score: " << stu->get_score()
            << std::endl;

  return EXIT_SUCCESS;
}
