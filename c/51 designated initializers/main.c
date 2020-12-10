// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int64_t id;
    char *name;
} user;

int main(int argc, char const *argv[])
{
    user u1 = {
        .id = 135139,
        .name = "dev",
    };
    printf("u1: id=%ld, name=%s\n", u1.id, u1.name);

    user arr[] = {
        [1].id = 135001,
        [1].name = "135001",
        {
            .id = 135002,
            .name = "135002",
        },
        [4] = {
            .id = 135004,
            .name = "135004",
        },
    };
    uint64_t len = sizeof(arr) / sizeof(user);
    printf("arr: length = %lu\n", len);
    for (uint64_t i = 0; i < len; ++i)
    {
        printf("arr[%lu]: id=%lu, name=%s\n", i, (arr + i)->id, (*(arr + i)).name);
    }

    return EXIT_SUCCESS;
}