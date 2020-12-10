// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAIN_FUN int main(int argc,
#define PI 3.1415926

MAIN_FUN char const *argv[])
{
    printf("PI: %.7f\n", PI);
    int64_t num = (int64_t)NUM;
    printf("num: %ld\n", num);
    return EXIT_SUCCESS;
}

/*
$ gcc -DNUM=1096 main.c
*/