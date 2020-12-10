// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define D_LEN 15

int main(int argc, char const *argv[])
{
    puts("demo1:");
    char s1[] = {'h', 'i'}; // size = 2
    printf("s1: val=%s, addr=%p, len=%lu, size=%lu\n", s1, s1, strlen(s1), sizeof(s1));

    puts("demo2:");
    char s2[] = {'h', 'i', '\0'}; // size = 3
    printf("s2: val=%s, addr=%p, len=%lu, size=%lu\n", s2, s2, strlen(s2), sizeof(s2));

    puts("demo3:");
    char s3[] = "hi"; // size = 3
    printf("s3: val=%s, addr=%p, len=%lu, size=%lu\n", s3, s3, strlen(s3), sizeof(s3));

    puts("demo4:");
    char s4[] = "hi\0"; // size = 4
    printf("s4: val=%s, addr=%p, len=%lu, size=%lu\n", s4, s4, strlen(s4), sizeof(s4));

    puts("demo5:");
    char *s5 = "hi"; // size = 8
    // s5[0]='A'; // egmentation fault (core dumped)
    printf("s5: val=%s, addr=%p, len=%lu, size=%lu\n", s5, s5, strlen(s5), sizeof(s5));

    puts("demo6:");
    char *s6 = "hi\0"; // size = 8
    printf("s6: val=%s, addr=%p, len=%lu, size=%lu\n", s6, s6, strlen(s6), sizeof(s6));

    puts("=====================================================");

    puts("demo7:");
    int64_t const LEN = 15;
    char str1[LEN + 1];
    char *str2 = "hello";
    strcpy(str1, str2);
    printf("str1: val=%s, addr=%p, len=%lu, size=%lu\n", str1, str1, strlen(str1), sizeof(str1));

    puts("demo8:");
    // char str3[LEN + 1] = {'h', 'e', 'l', 'l', 'o'}; // error: variable-sized object may not be initialized
    // printf("str3: val=%s, addr=%p, len=%lu, size=%lu\n", str3, str3, strlen(str3), sizeof(str3));
    char str4[D_LEN + 1] = {'h', 'i', '\0', 'c'};
    printf("str4: val=%s, addr=%p, len=%lu, size=%lu\n", str4, str4, strlen(str4), sizeof(str4));

    puts("demo9:");
    char str5[LEN + 1];
    printf("str5: val=%s, addr=%p, len=%lu, size=%lu\n", str5, str5, strlen(str5), sizeof(str5));
    memset(str5, 0, sizeof(str5));
    strcpy(str5, "Hello, C!");
    printf("str5: val=%s, addr=%p, len=%lu, size=%lu\n", str5, str5, strlen(str5), sizeof(str5));
    for (int64_t i = 0; i < sizeof(str5) / sizeof(char); i++)
    {
        printf("str5[%ld]: %hhu, %c\n", i, str5[i], *(str5 + i));
    }

    return EXIT_SUCCESS;
}
