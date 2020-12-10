// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_info(char *, uint8_t);

int64_t sum(int64_t, int64_t);

int main(int argc, char const *argv[])
{
    char *name = "dev-go";
    uint8_t age = 18;
    print_info(name, age);

    int64_t n1 = 1 << 10;
    int64_t n2 = 1 << 10;
    int64_t n3 = sum(n1, n2);
    printf("n3=%ld\n", n3);

    return EXIT_SUCCESS;
}

void print_info(char *name, uint8_t age)
{
    printf("name: %s, age: %hhu\n", name, age);
    return;
}

int64_t sum(int64_t n1, int64_t n2)
{
    return n1 + n2;
}
