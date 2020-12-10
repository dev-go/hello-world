// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <stdio.h>
#include <string.h>

#include "worker.h"

char *Worker::name() const { return name_; }

void Worker::set_name(char *name)
{
  memset(name_, 0, 32);
  strcpy(name_, name);
  return;
}

char *Worker::to_string()
{
  char *buf = new char[64];
  memset(buf, 0, 64);
  sprintf(buf, "Worker{name: %s}", name_);
  return buf;
}

void Worker::work()
{
  printf("Worker work ... >>> %s\n", to_string());
  return;
}

Worker::Worker() : Person(1991)
{
  name_ = new char[32];
  memset(name_, 0, 32);
  printf("new Worker >>>\n");
}

Worker::Worker(const Worker &w) : Person(1991)
{
  name_ = new char[32];
  memset(name_, 0, 32);
  strcpy(name_, w.name_);
  printf("copy Worker >>>\n");
}

Worker::~Worker()
{
  delete[] name_;
  name_ = NULL;
  printf("delete Worker >>>\n");
}
