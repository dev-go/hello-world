// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include <iostream>

typedef struct _User
{
  uint32_t ID;
  char *Name;
} User;

void swap(int32_t &a, int32_t &b)
{
  int32_t tmp = a;
  a = b;
  b = tmp;
  return;
}

int main(int argc, char **argv)
{
  int32_t a = 66;
  // int32_t &b; // error: declaration of reference variable 'b' requires an
  // initializer
  int32_t &b = a;
  b = 88;
  std::cout << "a: " << a << std::endl;
  std::cout << "b: " << b << std::endl;

  std::cout << "=============" << std::endl;

  const uint8_t len = 10;
  char *name01 = (char *)malloc(len * sizeof(char));
  memset(name01, 0, len);
  strcpy(name01, "Terrence");
  char *name02 = (char *)malloc(len * sizeof(char));
  memset(name02, 0, len);
  strcpy(name02, "Ma");
  User u1 = {2011135139, name01};
  std::cout << "id: " << u1.ID << std::endl;
  std::cout << "name: " << u1.Name << std::endl;
  User &u2 = u1;
  u2.ID = 2011135141;
  u2.Name = name02;
  std::cout << "id: " << u1.ID << std::endl;
  std::cout << "name: " << u1.Name << std::endl;

  std::cout << "=============" << std::endl;

  std::cout << "a: " << a << std::endl;
  int32_t *c = &a;
  int32_t *&d = c;
  *d = 99;
  std::cout << "a: " << a << std::endl;

  std::cout << "=============" << std::endl;

  int32_t e = 1 << 10;
  std::cout << "a: " << a << std::endl;
  std::cout << "e: " << e << std::endl;
  swap(a, e);
  std::cout << "a: " << a << std::endl;
  std::cout << "e: " << e << std::endl;

  return EXIT_SUCCESS;
}
