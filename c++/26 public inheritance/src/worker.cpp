// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include "person.h"
#include "worker.h"

void Worker::work()
{
  printf("Worker work ...\n%s\n", to_string());
  return;
}

char *Worker::to_string()
{
  char *buf = new char[128];
  memset(buf, 0, 128);
  // sprintf(buf, "Worker{salary: %ld, name: %s, id: %ld}", salary_, name_,
  // id_);
  sprintf(buf, "Worker{name: %s, salary: %ld}", name_, salary_);
  return buf;
}

Worker::Worker(char *name, int64_t id, int64_t salary) : Person(name, id)
{
  salary_ = salary;
}
