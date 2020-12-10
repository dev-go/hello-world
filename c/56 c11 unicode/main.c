// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <uchar.h>

int main(void)
{
    char s1[] = "中国";
    char s2[] = u8"中国";
    char16_t s3[] = u"中国";
    char32_t s4[] = U"中国";
    wchar_t s5[] = L"中国";

    printf("s1: val=%s, size=%lu, len=%lu\n", s1, sizeof(s1), sizeof(s1) / sizeof(*s1));
    printf("s2: val=%s, size=%lu, len=%lu\n", s2, sizeof(s2), sizeof(s2) / sizeof(*s2));

    printf("s3: size=%lu, len=%lu\n", sizeof(s3), sizeof(s3) / sizeof(*s3));
    printf("s4: size=%lu, len=%lu\n", sizeof(s4), sizeof(s4) / sizeof(*s4));
    printf("s5: size=%lu, len=%lu\n", sizeof(s5), sizeof(s5) / sizeof(*s5));

    return EXIT_SUCCESS;
}