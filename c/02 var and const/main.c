// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define PI 3.1415926
int64_t const MAX = 1 << 10;
int64_t num = 0;

int main(int argc, char const *argv[])
{
    printf("PI = %f\n", PI);
    printf("MAX = %ld\n", MAX);
    printf("num = %ld\n", num);
    // ++MAX; // error: increment of read-only variable 'MAX'
    ++num;
    printf("num = %ld\n", num);
    return EXIT_SUCCESS;
}