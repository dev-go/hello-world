// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    char *s1 = "hello, world!";
    printf("s1: val=\"%s\", addr=%p, len=%lu, size=%lu\n", s1, s1, strlen(s1), sizeof(s1));
    char *s2 = strchr(s1, 'o');
    printf("s2: val=\"%s\", addr=%p, len=%lu, size=%lu\n", s2, s2, strlen(s2), sizeof(s2));
    char *s3 = strrchr(s1, 'o');
    printf("s3: val=\"%s\", addr=%p, len=%lu, size=%lu\n", s3, s3, strlen(s3), sizeof(s3));
    char *s4 = strstr(s1, "ll");
    printf("s4: val=\"%s\", addr=%p, len=%lu, size=%lu\n", s4, s4, strlen(s4), sizeof(s4));

    int64_t const LEN = 1 << 4;
    char s5[LEN];
    strcpy(s5, s1);
    printf("s5: val=\"%s\", addr=%p, len=%lu, size=%lu\n", s5, s5, strlen(s5), sizeof(s5));

    char *s6 = s5 + 7;
    printf("s6: val=\"%s\", addr=%p, len=%lu, size=%lu\n", s6, s6, strlen(s6), sizeof(s6));

    char s7[LEN];
    memset(s7, 0, sizeof(char) * LEN);
    strncpy(s7, s1 + 7, 5);
    printf("s7: val=\"%s\", addr=%p, len=%lu, size=%lu\n", s7, s7, strlen(s7), sizeof(s7));

    return EXIT_SUCCESS;
}
