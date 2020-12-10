// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <stdarg.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

void output(int64_t count, ...);

int64_t sum(int64_t count, ...);

int main(int argc, char const *argv)
{
    output(3, "C", "Go", "Js");
    printf("sum: 1+2+3+4+5=%ld\n", sum(5, 1, 2, 3, 4, 5));
    return EXIT_SUCCESS;
}

void output(int64_t count, ...)
{
    va_list args;
    va_start(args, count);
    for (int64_t i = 0; i < count; i++)
    {
        char *s = va_arg(args, char *);
        printf("output: [%ld] %s\n", i, s);
    }
    va_end(args);
}

int64_t sum(int64_t count, ...)
{
    int64_t result = 0;
    va_list args;
    va_start(args, count);
    for (int64_t i = 0; i < count; ++i)
    {
        int64_t n = va_arg(args, int64_t);
        result += n;
    }
    va_end(args);
    return result;
}
