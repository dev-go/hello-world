// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    puts("demo1:");
    for (int8_t i = 0; i < 10; ++i)
    {
        if (i == 5)
        {
            break;
        }
        printf("i = %hhd\n", i);
    }

    puts("demo2:");
    for (int8_t i = 0; i < 10; ++i)
    {
        if (i == 5)
        {
            continue;
        }
        printf("i = %hhd\n", i);
    }

    puts("demo3:");
    for (int8_t i = 1; i < 10; ++i)
    {
        for (int8_t j = 1; j <= i; ++j)
        {
            printf("%hhd x %hhd = %hhd\t", j, i, j * i);
        }
        putchar('\n');
    }
    return EXIT_SUCCESS;
}