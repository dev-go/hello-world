// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <memory.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    void *str = "Hello, World!";
    printf("str: val=%s, addr=%p\n", (char *)str, str);

    int64_t const BYTES = 16;
    void *p1 = malloc(BYTES);
    memset(p1, 0, BYTES);
    int64_t *p2 = (int64_t *)p1;
    int8_t *p3 = (int8_t *)p1;
    for (int64_t i = 0; i < BYTES / sizeof(int64_t); ++i)
    {
        p2[i] = 0x1122334455667788;
    }
    for (int64_t i = 0; i < BYTES / sizeof(int8_t); ++i)
    {
        printf("p3[%ld] = 0x%hhX\n", i, p3[i]);
    }
    free(p1);

    return EXIT_SUCCESS;
}