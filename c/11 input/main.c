// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    char c1 = 0;
    puts("please enter one character:");
    scanf(" %c", &c1);
    printf("c1 = %c (%hhu)\n", c1, c1);
    puts("please enter one character");
    scanf(" %c", &c1);
    printf("c1 = %c (%hhu)\n", c1, c1);

    int64_t n1 = 0;
    puts("please enter one number(int64_t):");
    scanf(" %ld", &n1);
    printf("n1 = %ld\n", n1);
    puts("please enter one number(int64_t):");
    scanf(" %ld", &n1);
    printf("n1 = %ld\n", n1);

    int64_t len = 0;
    puts("please enter your name's length:");
    scanf(" %ld", &len);
    printf("len = %ld (%p)\n", len, &len);

    char str[len];
    memset(str, 0, len * sizeof(char));
    printf("str = %s (%p)\n", str, &str);
    puts("please enter your name:");
    scanf(" %s", str);
    printf("str = %s (%p)\n", str, &str);

    return EXIT_SUCCESS;
}