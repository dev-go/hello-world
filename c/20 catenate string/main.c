// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    puts("demo1:");
    int64_t const LEN = 15;
    char s1[LEN + 1];
    printf("s1: val=%s, addr=%p, len=%lu, size=%lu\n", s1, s1, strlen(s1), sizeof(s1));
    memset(s1, 0, (LEN + 1) * sizeof(char));
    printf("s1: val=%s, addr=%p, len=%lu, size=%lu\n", s1, s1, strlen(s1), sizeof(s1));

    puts("demo2:");
    char *s2 = "hello";
    char *s3 = "world";
    char s4[strlen(s2) + strlen(s3) + 1];
    memset(s4, 0, strlen(s2) + strlen(s3) + 1);
    strcat(s4, s2);
    strcat(s4, s3);
    s4[sizeof(s4) / sizeof(char) - 1] = '\0';
    printf("s4: val=%s, addr=%p, len=%lu, size=%lu\n", s4, s4, strlen(s4), sizeof(s4));

    puts("demo3:");
    char *s5 = "Hello, A!";
    char *s6 = "Hello, B!";
    char s7[LEN + 1];
    strncat(s7, s5, 8);
    strncat(s7, s6 + 5, 4);
    s7[strlen(s7)] = '\0';
    printf("s7: val=%s, addr=%p, len=%lu, size=%lu\n", s7, s7, strlen(s7), sizeof(s7));

    return EXIT_SUCCESS;
}
