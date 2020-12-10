// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    uint8_t u8 = 10;
    printf("u8 = %hhu\n", u8);
    uint16_t u16 = 100;
    printf("u16 = %hu\n", u16);
    uint32_t u32 = 1 << 20;
    printf("u32 = %u\n", u32);
    uint64_t u64 = 1 << 30;
    printf("u64 = %lu\n", u64);

    int8_t i8 = -10;
    printf("i8 = %hhd\n", i8);
    int16_t i16 = 100;
    printf("i16 = %hd\n", i16);
    int32_t i32 = 200000000;
    printf("i32 = %d\n", i32);
    int64_t i64 = 10000000000;
    printf("i64 = %ld\n", i64);

    printf("sizeof(uint8_t) = %lu\n", sizeof(uint8_t));
    printf("sizeof(uint16_t) = %lu\n", sizeof(uint16_t));
    printf("sizeof(uin32_t) = %lu\n", sizeof(uint32_t));
    printf("sizeof(uint64_t) = %lu\n", sizeof(uint64_t));
    printf("sizeof(int8_t) = %lu\n", sizeof(int8_t));
    printf("sizeof(int16_t) = %lu\n", sizeof(int16_t));
    printf("sizeof(in32_t) = %lu\n", sizeof(int32_t));
    printf("sizeof(int64_t) = %lu\n", sizeof(int64_t));

    return EXIT_SUCCESS;
}