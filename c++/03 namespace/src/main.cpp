// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <stdint.h>
#include <stdlib.h>

#include <iostream>

namespace utils
{
  int64_t get_max(int64_t *arr, int64_t len);
  int64_t get_min(int64_t *arr, int64_t len);

  static int64_t get(bool max, int64_t *arr, int64_t len)
  {
    int64_t result = arr[0];
    if (max)
    {
      for (int64_t i = 1; i < len; i++)
      {
        if (arr[i] > result)
        {
          result = arr[i];
        }
      }
    }
    else
    {
      for (int64_t i = 1; i < len; i++)
      {
        if (arr[i] < result)
        {
          result = arr[i];
        }
      }
    }
    return result;
  }

  int64_t get_max(int64_t *arr, int64_t len) { return get(true, arr, len); }

  int64_t get_min(int64_t *arr, int64_t len) { return get(false, arr, len); }
} // namespace utils

// // not use 'using namespace xxx'
// int main(int argc, char **argv)
// {
//   int64_t len = 6;
//   int64_t *arr = (int64_t *)malloc(len * sizeof(int64_t));
//   arr[0] = 56;
//   1 [arr] = 35;
//   *(arr + 2) = 98;
//   *(arr + 3) = 29;
//   arr[4] = 22;
//   arr[5] = 73;
//
//   std::cout << "max: " << utils::get_max(arr, len) << std::endl;
//   std::cout << "min: " << utils::get_min(arr, len) << std::endl;
//
//   return EXIT_SUCCESS;
// }

// use 'using namespace xxx'
using namespace std;
using namespace utils;
int main(int argc, char **argv)
{
  int64_t len = 6;
  int64_t *arr = (int64_t *)malloc(len * sizeof(int64_t));
  arr[0] = 56;
  1 [arr] = 35;
  *(arr + 2) = 98;
  *(arr + 3) = 29;
  arr[4] = 22;
  arr[5] = 73;

  cout << "max: " << get_max(arr, len) << endl;
  cout << "min: " << get_min(arr, len) << endl;

  return EXIT_SUCCESS;
}
