// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <stdint.h>
#include <stdlib.h>

#include <iostream>

int main(int argc, char **argv)
{
  int32_t x = 11;
  int32_t y = 12;
  int32_t z = 13;
  std::cout << "x: " << x << ", y: " << y << ", z: " << z << std::endl;
  std::cout << "====================================" << std::endl
            << std::endl;

  const int32_t a = x;
  // a = 89; // error: cannot assign to variable 'a' with const-qualified type
  // 'const int32_t' (aka 'const int')
  std::cout << "a: " << a << ", &a: " << &a << std::endl;
  std::cout << "x: " << x << ", y: " << y << ", z: " << z << std::endl;
  std::cout << "====================================" << std::endl
            << std::endl;

  const int32_t *b = &x;
  std::cout << "b: " << b << ", *b: " << *b << std::endl;
  b = &y;
  std::cout << "b: " << b << ", *b: " << *b << std::endl;
  // *b = 88; // error: read-only variable is not assignable
  std::cout << "x: " << x << ", y: " << y << ", z: " << z << std::endl;
  std::cout << "====================================" << std::endl
            << std::endl;

  int32_t const *c = &x;
  std::cout << "c: " << c << ", *c: " << *c << std::endl;
  c = &y;
  std::cout << "c: " << c << ", *c: " << *c << std::endl;
  // *c = 88; // error: read-only variable is not assignable
  std::cout << "x: " << x << ", y: " << y << ", z: " << z << std::endl;
  std::cout << "====================================" << std::endl
            << std::endl;

  int32_t *const d = &x;
  std::cout << "d: " << d << ", *d: " << *d << std::endl;
  *d = 19;
  std::cout << "d: " << d << ", *d: " << *d << std::endl;
  // d = &z; // error: cannot assign to variable 'd' with const-qualified type
  // 'int32_t *const' (aka 'int *const')
  *d = 11;
  std::cout << "x: " << x << ", y: " << y << ", z: " << z << std::endl;
  std::cout << "====================================" << std::endl
            << std::endl;

  const int32_t *const e = &x;
  std::cout << "e: " << e << ", *e: " << *e << std::endl;
  // *e = y; // error: read-only variable is not assignable
  // e = &z; // error: cannot assign to variable 'e' with const-qualified type
  // 'const int32_t *const' (aka 'const int *const')
  std::cout << "x: " << x << ", y: " << y << ", z: " << z << std::endl;
  std::cout << "====================================" << std::endl
            << std::endl;

  const int32_t &f = x;
  std::cout << "f: " << f << ", &f: " << &f << std::endl;
  // f = 19; // error: cannot assign to variable 'f' with const-qualified type
  // 'const int32_t &' (aka 'const int &')
  x = 19;
  std::cout << "f: " << f << ", &f: " << &f << std::endl;
  x = 11;
  std::cout << "x: " << x << ", y: " << y << ", z: " << z << std::endl;
  std::cout << "====================================" << std::endl
            << std::endl;

  return EXIT_SUCCESS;
}
