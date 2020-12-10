// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    printf("version = %ld\n", __STDC_VERSION__);
    static_assert(__STDC_VERSION__ >= 201112L, "c version is too old!");

    return EXIT_SUCCESS;
}