// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int64_t fact(int64_t);

int main(int argc, char const *argv[])
{
    int64_t n = 5;
    printf("fact(%ld) = %ld\n", n, fact(n));
    n = 6;
    printf("fact(%ld) = %ld\n", n, fact(n));

    return EXIT_SUCCESS;
}

int64_t fact(int64_t n)
{
    int64_t register result = 1;
    for (int64_t register i = 1; i <= n; ++i)
    {
        result *= i;
    }
    return result;
}