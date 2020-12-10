// Copyright (c) 2020, devgo.club
// All rights reserved.

#pragma once

#include "flyable.h"

class Plane : public Flyable
{
public:
  virtual void takeoff();
  virtual void land();
};
