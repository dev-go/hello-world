// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

class Bird
{
public:
  void fly()
  {
    printf("Bird fly ...\n");
    return;
  };
  Bird() { printf("Bird new ...\n"); };
  ~Bird() { printf("Bird delete ...\n"); };
};

class Dog
{
public:
  virtual void bark()
  {
    printf("Dog bark ...\n");
    return;
  };
  Dog() { printf("Dog new ...\n"); };
  ~Dog() { printf("Dog delete ...\n"); };
};

class Shape
{
public:
  double calc_area()
  {
    printf("Shape calc_area ...\n");
    return 0;
  };
  Shape() { printf("Shape new ...\n"); };
  virtual ~Shape() { printf("Shape delete ...\n"); };
};

class Circle : public Shape
{
public:
  double calc_area()
  {
    printf("Circle calc_area ...\n");
    return 3.14 * r_ * r_;
  };
  Circle(uint64_t r) : r_(r) { printf("Circle new ...\n"); };
  ~Circle() { printf("Circle delete ...\n"); };

private:
  uint64_t r_;
};

int main(int argc, char **argv)
{
  Bird bird;
  printf("Bird\t object size: %lu\n", sizeof(bird));

  printf("===================================\n");

  Dog dog;
  printf("Dog\t object size: %lu\n", sizeof(dog));

  printf("===================================\n");

  Circle circle(10);
  printf("Circle\t object size: %lu\n", sizeof(circle));
  uint64_t *p = (uint64_t *)(&circle);
  printf("vftable address: %p\n", p);
  p++;
  printf("r value: %lu\n", (uint64_t)(*p));

  printf("===================================\n");

  return EXIT_SUCCESS;
}
