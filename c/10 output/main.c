// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef float float32;
typedef double float64;
typedef long double float128;

int main(int argc, char const *argv[])
{
    printf("Hello, C!\n");

    char name[] = "dev-go";
    uint8_t age = 18;
    printf("name = %s, age = %hhu\n", name, age);
    printf("age = 0o%hho\n", age);
    printf("age = 0x%hhx\n", age);
    printf("name[2] = %c\n", name[2]);
    printf("name[4] = %s\n", &(name[4]));
    printf("name + 4 = %s\n", name + 4);

    float64 f1 = 3.1415926L;
    printf("f1 = %lf\n", f1);
    printf("f1 = %5.3lf\n", f1);
    int64_t num = 5;
    printf("num = %04ld\n", num);
    printf("num = %-4ld\n", num);
    printf("num = %4ld\n", num);

    return EXIT_SUCCESS;
}