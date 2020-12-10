// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int64_t n1 = 0;
    int64_t n2 = 0;

    puts("please enter a number:");
    scanf(" %ld", &n1);
    puts("please enter another number:");
    scanf(" %ld", &n2);

    if (n1 > n2)
    {
        printf("max: %ld\n", n1);
    }
    else
    {
        printf("max: %ld\n", n2);
    }

    printf("max: %ld\n", n1 > n2 ? n1 : n2);

    return EXIT_SUCCESS;
}