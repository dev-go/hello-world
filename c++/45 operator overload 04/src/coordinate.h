// Copyright (c) 2020, devgo.club
// All rights reserved.

#pragma once

#include <stdint.h>

#include <iostream>

class Coordinate
{
  friend Coordinate operator+(const Coordinate &c1, const Coordinate &c2);
  friend std::ostream &operator<<(std::ostream &output, const Coordinate &coor);

public:
  //    Coordinate operator+(const Coordinate &coor);
  int32_t operator[](uint8_t index);
  Coordinate(int32_t x = 0, int32_t y = 0);
  Coordinate(const Coordinate &coor);

private:
  int32_t x_;
  int32_t y_;
};
