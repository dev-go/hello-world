// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <stdio.h>
#include <stdlib.h>

typedef float float32;
typedef double float64;
typedef long double float128;

int main(int argc, char const *argv[])
{
    float32 f1 = 3.14159265357939788292;
    float64 f2 = 3.14159265357939788292;
    float128 f3 = 3.14159265357939788292;
    printf("f1 = %f\n", f1);
    printf("f2 = %lf\n", f2);
    printf("f3 = %Lf\n", f3);

    printf("sizeof(float32) = %lu\n", sizeof(float32));
    printf("sizeof(float64) = %lu\n", sizeof(float64));
    printf("sizeof(float128) = %lu\n", sizeof(float128));

    return EXIT_SUCCESS;
}