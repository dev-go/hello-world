// Copyright (c) 2020, devgo.club
// All rights reserved.

#pragma once

class Worker
{
public:
  char *name() const;
  void set_name(char *name);
  char *to_string();
  void work();
  Worker();
  Worker(const Worker &w);
  ~Worker();

protected:
  char *name_;
};
