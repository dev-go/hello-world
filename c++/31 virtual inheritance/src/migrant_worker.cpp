// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include "farmer.h"
#include "migrant_worker.h"
#include "worker.h"

MigrantWorker::MigrantWorker(char *name, int64_t id) : Worker(), Farmer()
{
  set_name(name);
  set_id(id);
  printf("new MigrantWorker >>>\n");
}

MigrantWorker::MigrantWorker(const MigrantWorker &mw) : Worker(), Farmer()
{
  set_name(mw.name());
  set_id(mw.id());
  printf("copy MigrantWorker >>>\n");
}

MigrantWorker::~MigrantWorker() { printf("delete MigrantWorker >>>\n"); }
