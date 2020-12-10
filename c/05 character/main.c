// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    char c1 = 'A';
    char c2 = c1 + 32;
    printf("c1 = %c(%hhu)\n", c1, c1);
    printf("c2 = %c(%hhu)\n", c2, c2);

    char *s1 = "abc";
    char *s2 = "中国";
    printf("s1 = %s(len: %lu)\n", s1, strlen(s1));
    printf("s2 = %s(len: %lu)\n", s2, strlen(s2));

    printf("Hello\tworld\fHello\tC\n\"C\" \\ \n");

    return EXIT_SUCCESS;
}