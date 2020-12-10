// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <string>

class Coordinate
{
public:
  double x();
  double y();
  void set_x(double x);
  void set_y(double y);
  std::string to_string();
  Coordinate(double x = 0.0, double y = 0.0);
  Coordinate(const Coordinate &coordinate);
  ~Coordinate();

private:
  double x_;
  double y_;
};
