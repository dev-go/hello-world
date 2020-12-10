// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "calc.h"
#include "greet.h"

int main(int argc, char const *argv[])
{
    int64_t n1 = 109;
    int64_t n2 = 23;
    int64_t n3 = add(n1, n2);
    int64_t n4 = sub(n1, n2);
    printf("n1 = %ld, n2 = %ld, n3 = %ld, n4 = %ld\n", n1, n2, n3, n4);

    char *s = hi("dev-go");
    printf("s: %s\n", s);
    free(s);

    return EXIT_SUCCESS;
}