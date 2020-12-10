// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int64_t result = 100 / 5 - 2 * 5;
    printf("result = %ld\n", result);

    printf("M_PI = %lf\n", M_PI);
    printf("sin(M_PI / 6) = %lf\n", sin(M_PI / 6));

    return EXIT_SUCCESS;
}