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
  sprintf(buf, "Worker{id: %ld, Person:{id: %ld}}", id_, Person::id_);
  return buf;
}

Worker::Worker(int64_t id) : Person(-id), id_(id)
{
  printf("new Worker >>>\n%s\n", to_string());
}

Worker::~Worker() { printf("delete Worker >>>\n%s\n", to_string()); }
