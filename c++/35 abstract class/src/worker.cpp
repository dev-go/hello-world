// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include "worker.h"

char *Worker::to_string()
{
  char *buf = new char[64];
  memset(buf, 0, 64);
  sprintf(buf, "Worker{id: %lu, Person: %s}", id_, Person::to_string());
  return buf;
}

void Worker::work()
{
  printf("work\t >>> %s\n", to_string());
  return;
}

Worker::Worker(char *name, uint64_t id) : Person(name), id_(id)
{
  printf("new\t >>> %s\n", to_string());
}

Worker::Worker(const Worker &w) : Person(w.name_), id_(w.id_)
{
  printf("copy\t >>> %s\n", to_string());
}

Worker::~Worker() { printf("delete\t >>> %s\n", to_string()); }
