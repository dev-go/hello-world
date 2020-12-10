// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *bool_to_str(int b)
{
    return b == 0 ? "false" : "true";
}

char *str_cmp(char *s1, char *s2)
{
    int r = strcmp(s1, s2);
    if (r == 0)
    {
        return "=";
    }
    else if (r > 0)
    {
        return ">";
    }
    else
    {
        return "<";
    }
}

int main(int argc, char const *argv[])
{
    char *s1 = "Hello";
    printf("s1: val=\"%s\", addr=0x%p, len=%lu, size=%lu\n", s1, s1, strlen(s1), sizeof(s1));
    char *s2 = "Hello";
    printf("s2: val=\"%s\", addr=0x%p, len=%lu, size=%lu\n", s2, s2, strlen(s2), sizeof(s2));
    char *s3 = "Hello\0";
    printf("s3: val=\"%s\", addr=0x%p, len=%lu, size=%lu\n", s3, s3, strlen(s3), sizeof(s3));
    char s4[] = {'H', 'e', 'l', 'l', 'o'};
    printf("s4: val=\"%s\", addr=0x%p, len=%lu, size=%lu\n", s4, s4, strlen(s4), sizeof(s4));
    char s5[] = {'H', 'e', 'l', 'l', 'o', '\0'};
    printf("s5: val=\"%s\", addr=0x%p, len=%lu, size=%lu\n", s5, s5, strlen(s5), sizeof(s5));
    char s6[] = "Hello";
    printf("s6: val=\"%s\", addr=0x%p, len=%lu, size=%lu\n", s6, s6, strlen(s6), sizeof(s6));
    char s7[] = "Hello\0";
    printf("s7: val=\"%s\", addr=0x%p, len=%lu, size=%lu\n", s7, s7, strlen(s7), sizeof(s7));

    printf("s1==s2: %s\n", bool_to_str(s1 == s2));
    printf("s1==s3: %s\n", bool_to_str(s1 == s3));
    printf("s1==s4: %s\n", bool_to_str(s1 == s4));
    printf("s1==s5: %s\n", bool_to_str(s1 == s5));
    printf("s4==s5: %s\n", bool_to_str(s4 == s5));

    printf("strcmp(s1,s2): %s\n", str_cmp(s1, s2));
    printf("strcmp(s1,s3): %s\n", str_cmp(s1, s3));
    printf("strcmp(s1,s4): %s\n", str_cmp(s1, s4));
    printf("strcmp(s1,s5): %s\n", str_cmp(s1, s5));
    printf("strcmp(s4,s5): %s\n", str_cmp(s4, s5));

    return EXIT_SUCCESS;
}