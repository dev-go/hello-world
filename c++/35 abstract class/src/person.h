// Copyright (c) 2020, devgo.club
// All rights reserved.

#pragma once

class Person
{
public:
  virtual char *to_string();
  virtual void work() = 0;
  Person(char *name = (char *)"");
  Person(const Person &p);
  virtual ~Person();

protected:
  char *name_;
};
