// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include "person.h"
#include "worker.h"

void Worker::work()
{
  printf("Worker work >>>\n");
  printf("father: %s\n", to_string());
  printf("id: %ld\n", id_);
  printf("name: %s\n", name_);
  printf("salary: %ld\n", salary_);
  printf("<<<\n");
  return;
}

Worker::Worker(char *name, int64_t id, int64_t salary)
    : Person(name, id), salary_(salary)
{
  printf("new Worker\n");
  return;
}
