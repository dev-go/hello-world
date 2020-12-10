// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_FUNC(A, B) \
    ((A) > (B) ? (A) : (B))

#define ITER_FUNC(START, END, FUNC)       \
    for (int64_t i = START; i < END; ++i) \
    {                                     \
        FUNC;                             \
    }

int main(int argc, char const *argv[])
{
    printf("max: %d\n", MAX_FUNC(114 + 3, 55 + 78));

    int64_t array[] = {11, 22, 33, 44, 55};
    int64_t len = sizeof(array) / sizeof(int64_t);
    ITER_FUNC(0, len, printf("array[%ld] = %ld\n", i, array[i]));

    return EXIT_SUCCESS;
}