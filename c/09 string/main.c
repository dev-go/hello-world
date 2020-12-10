// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    uint8_t c1 = 65;
    putchar(c1);
    putchar('\n');
    char c2 = c1 + 32;
    putchar(c2);
    putchar('\n');

    char *s1 = "abc";
    puts(s1);
    printf("s1: %s (%p)\n", s1, s1);
    s1 = "xyz";
    printf("s1: %s (%p)\n", s1, s1);

    // s1[0] = 'a'; // Segmentation fault (core dumped)
    // *(s1 + 2) = 'c'; // Segmentation fault (core dumped)

    putchar(s1[0]);
    putchar('\n');
    putchar(*(s1 + 0));
    putchar('\n');

    char s2[] = "abc";
    printf("s2: %s (%p)\n", s2, s2);
    s2[1] = 'y';
    *(s2 + 2) = 'z';
    printf("s2: %s (%p)\n", s2, s2);

    // s2 = "xyz"; // error: assignment to expression with array type

    return EXIT_SUCCESS;
}