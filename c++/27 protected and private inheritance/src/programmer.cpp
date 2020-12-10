// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include "programmer.h"

void Programmer::dev()
{
  printf("Programmer dev >>>\n");
  printf("grandfather: %s\n", to_string());
  printf("father: ");
  work();
  printf("id: %ld\n", id_);
  printf("name: %s\n", name_);
  printf("salary: %ld\n", salary_);
  printf("<<<\n");
  return;
}

Programmer::Programmer(char *name, int64_t id, int64_t salary)
    : Worker(name, id, salary)
{
  printf("new Programmer\n");
}
