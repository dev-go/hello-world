// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include "farmer.h"

int64_t Farmer::id() const { return id_; }

void Farmer::set_id(int64_t id)
{
  id_ = id;
  return;
}

char *Farmer::to_string()
{
  char *buf = new char[64];
  memset(buf, 0, 64);
  sprintf(buf, "Farmet{id: %ld}", id_);
  return buf;
}

void Farmer::sow()
{
  printf("Farmer sow ... >>> %s\n", to_string());
  return;
}

Farmer::Farmer() : Person(2001) { printf("new Farmer >>>\n"); }

Farmer::Farmer(const Farmer &f) : Person(2001)
{
  id_ = f.id_;
  printf("copy Farmer >>>\n");
}

Farmer::~Farmer() { printf("delete Farmer >>>\n"); }
