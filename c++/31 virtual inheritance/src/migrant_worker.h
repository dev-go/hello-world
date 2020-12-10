// Copyright (c) 2020, devgo.club
// All rights reserved.

#pragma once

#include "farmer.h"
#include "worker.h"

class MigrantWorker : public Worker, public Farmer
{
public:
  MigrantWorker(char *name, int64_t id);
  MigrantWorker(const MigrantWorker &mw);
  virtual ~MigrantWorker();

protected:
};
