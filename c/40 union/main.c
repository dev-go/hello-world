// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <memory.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef union
{
    char c;
    uint8_t b;
} byte;

typedef struct
{
    uint8_t a;
    uint8_t b;
    uint8_t g;
    uint8_t r;
} rgba;

typedef union
{
    uint32_t value;
    rgba rgba;
} color;

typedef union
{
    uint64_t f1;
    uint32_t f2;
    uint16_t f3;
    uint16_t f4;
    uint8_t f5;
} u1;

typedef struct
{
    uint64_t f1;
    uint32_t f2;
    uint16_t f3;
    uint16_t f4;
    uint8_t f5;
} s1;

typedef struct
{
    uint64_t f1;
    uint32_t f2;
    uint16_t f3;
    uint16_t f4;
    uint8_t f5;
} __attribute__((__packed__)) s2;

int main(int argc, char const *argv[])
{
    byte b1;
    b1.c = 'A';
    printf("b1: char=%c, byte=%hhu\n", b1.c, b1.b);
    b1.b += 32;
    printf("b1: char=%c, byte=%hhu\n", b1.c, b1.b);
    printf("byte: size=%lu\n", sizeof(byte));

    puts("======================================");

    printf("rgba: size=%lu\n", sizeof(rgba));
    printf("color: size=%lu\n", sizeof(color));
    color *c1 = (color *)malloc(sizeof(color));
    c1->value = 0xAABBCCDD;
    printf("c1: r=%hhX, g=%hhX, b=%hhX, a=%hhX\n", c1->rgba.r, c1->rgba.g, (*c1).rgba.b, (*c1).rgba.a);
    free(c1);

    puts("======================================");

    printf("u1: size=%lu\n", sizeof(u1));
    printf("s1: size=%lu\n", sizeof(s1));
    printf("s2: size=%lu\n", sizeof(s2));

    return EXIT_SUCCESS;
}