// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    puts("demo1:");
    int8_t i = 0;
    while (i < 10)
    {
        ++i;
        if (i == 6)
        {
            continue;
        }
        printf("i = %hhd\n", i);
    }

    puts("demo2:");
    i = 0;
    while (i < 10)
    {
        ++i;
        if (i == 6)
        {
            break;
        }
        printf("i = %hhd\n", i);
    }

    puts("demo3:");
    i = 0;
    do
    {
        ++i;
        printf("i = %hhd\n", i);
    } while (i > 100);

    return EXIT_SUCCESS;
}