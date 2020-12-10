// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    uint8_t n = 0;

LABEL:
    if (n < 100)
    {
        n++;
        goto LABEL;
    }

    printf("n = %hhu\n", n);

    return EXIT_SUCCESS;
}