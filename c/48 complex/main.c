// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <complex.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])

{
    _Complex double a = 1.22 + 3.33 * I;
    printf("a: size=%lu, real=%lf, imag=%lf\n", sizeof(a), creal(a), cimag(a));

    _Complex float b = 1.22 + 3.33 * I;
    printf("b: size=%lu, real=%f, imag=%f\n", sizeof(b), crealf(b), cimagf(b));

    _Complex long double c = 55.55 + 66.66 * I;
    printf("c: size=%lu, real=%Lf, imag=%Lf\n", sizeof(c), creall(c), cimagl(c));

    return EXIT_SUCCESS;
}