// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

char *bool_to_string(_Bool b);

int main(int argc, char const *argv[])
{
    _Bool b1 = 0;
    printf("b1: val=%hhd(%s) size=%lu\n", b1, bool_to_string(b1), sizeof(b1));
    b1 = 99;
    printf("b1: val=%hhd(%s) size=%lu\n", b1, bool_to_string(b1), sizeof(b1));
    b1 = -88;
    printf("b1: val=%hhd(%s) size=%lu\n", b1, bool_to_string(b1), sizeof(b1));

    return EXIT_SUCCESS;
}

char *bool_to_string(_Bool b)
{
    return b ? "true" : "false";
}