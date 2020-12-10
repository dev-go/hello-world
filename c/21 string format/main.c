// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    char *s1 = "Hello";
    int64_t n1 = 1024;
    int64_t const LEN1 = 1 << 5;
    char s2[LEN1];
    memset(s2, 0, LEN1 * sizeof(char));
    sprintf(s2, "s1: %s, n1=%ld.", s1, n1);
    puts(s2);

    char *s3 = "name: dev-go, age: 18.";
    char name[7];
    int64_t age;
    sscanf(s3, "name: %6s, age: %ld.", name, &age);
    printf("name: %s, age: %ld\n", name, age);

    return EXIT_SUCCESS;
}