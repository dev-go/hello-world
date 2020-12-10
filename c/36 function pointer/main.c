// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <stdarg.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef int64_t (*calc_func)(int64_t, ...);

int64_t calc_add(int64_t count, ...)
{
    int64_t result = 0;
    va_list nums;
    va_start(nums, count);
    for (int i = 0; i < count; ++i)
    {
        int64_t n = va_arg(nums, int64_t);
        result += n;
    }
    va_end(nums);
    return result;
}

int64_t calc_sub(int64_t count, ...)
{
    int64_t result = 0;
    va_list nums;
    va_start(nums, count);
    for (int64_t i = 0; i < count; ++i)
    {
        int64_t n = va_arg(nums, int64_t);
        if (i == 0)
        {
            result = n;
        }
        else
        {
            result -= n;
        }
    }
    va_end(nums);
    return result;
}

int main(int argc, char const *argv[])
{
    calc_func f = calc_add;
    printf("add: 1 + 2 + 3 + 4 + 5 = %ld\n", f(5, 1, 2, 3, 4, 5));

    f = calc_sub;
    printf("sub: 100 - 10 - 20 - 30 - 4 = %ld\n", f(5, 100, 10, 20, 30, 4));

    return EXIT_SUCCESS;
}