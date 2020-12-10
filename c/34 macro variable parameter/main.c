// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char buf[1 << 12];

#define LOG(LEVEL, FORMAT, ...)               \
    memset(buf, 0, (1 << 12) * sizeof(char)); \
    strcat(buf, "[");                         \
    strcat(buf, LEVEL);                       \
    strcat(buf, "] ");                        \
    strcat(buf, FORMAT);                      \
    strcat(buf, "\n");                        \
    printf(buf, __VA_ARGS__);

#define LOG_INFO(FORMAT, ...) LOG("INFO", FORMAT, __VA_ARGS__)
#define LOG_ERROR(FORMAT, ...) LOG("ERROR", FORMAT, __VA_ARGS__)

int main(int argc, char const *argv[])
{
    char *name = "dev-go";
    int64_t n1 = 1 << 20;
    LOG_INFO("name = %s, n1 = %ld", name, n1);
    LOG_ERROR("name = %s, n1 = %ld", name, n1);

    return EXIT_SUCCESS;
}
