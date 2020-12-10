// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

uint64_t const RED_MASK = 0xFF000000;
uint64_t const GREEN_MASK = 0x00FF0000;
uint64_t const BLUE_MASK = 0x0000FF00;
uint64_t const ALPHA_MASK = 0x000000FF;
uint64_t const RED_OFFSET = 24;
uint64_t const GREEN_OFFSET = 16;
uint64_t const BLUE_OFFSET = 8;
uint64_t const ALPHA_OFFSET = 0;

int main(int argc, char const *argv[])
{
    uint8_t u1 = 0b00001001;
    uint8_t u2 = 0b00001100;
    printf("u1 & u2 = %hhu\n", (u1 & u2));
    printf("u1 | u2 = %hhu\n", (u1 | u2));
    printf("u1 ^ u2 = %hhu\n", (u1 ^ u2));
    printf("~u1 = %hhu\n", (~u1));
    printf("~u2 = %hhu\n", (~u2));
    printf("u1 >> 2 = %hhu\n", (u1 >> 2));
    printf("u1 << 2 = %hhu\n", (u1 << 2));

    uint64_t color = 0xAABBCCDD;
    uint8_t red = (color & RED_MASK) >> RED_OFFSET;
    uint8_t green = (color & GREEN_MASK) >> GREEN_OFFSET;
    uint8_t blue = (color & BLUE_MASK) >> BLUE_OFFSET;
    uint8_t alpha = (color & ALPHA_MASK) >> ALPHA_OFFSET;
    printf("color = 0x%lX\n", color);
    printf("red = 0x%hhX\n", red);
    printf("green = 0x%hhX\n", green);
    printf("blue = 0x%hhX\n", blue);
    printf("alpha = 0x%hhX\n", alpha);

    return EXIT_SUCCESS;
}