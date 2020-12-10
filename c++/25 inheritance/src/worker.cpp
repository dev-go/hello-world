// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <stdint.h>
#include <stdio.h>

#include "worker.h"

void Worker::work() { printf("work ...\n"); }

Worker::Worker() : salary_(0) { printf("new Worker\n"); }

Worker::~Worker() { printf("delete Worker\n"); }
