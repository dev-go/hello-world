// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

struct student
{
    struct
    {
        int64_t id;
        int64_t coin;
    };

    int64_t work_years;
};

int main(int argc, char const *argv[])
{
    struct student s =
        {
            {
                .id = 135,
                .coin = 1024,
            },
            .work_years = 10,
        };
    printf("s: id=%ld, coin=%ld, work_years=%ld\n", s.id, s.coin, s.work_years);

    return EXIT_SUCCESS;
}