// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef enum
{
    Mon = 1,
    Tues,
    Wed,
    Thurs,
    Fri,
    Sat,
    Sun
} week;

void output_week(week day)
{
    switch (day)
    {
    case Mon:
        puts("Monday");
        break;
    case Tues:
        puts("Tuesday");
        break;
    case Wed:
        puts("Wednesday");
        break;
    case Thurs:
        puts("Thursday");
        break;
    case Fri:
        puts("Friday");
        break;
    case Sat:
        puts("Saturday");
        break;
    case Sun:
        puts("Sunday");
        break;
    default:
        puts("Error!");
        break;
    }
    return;
}

int main(int argc, char const *argv[])
{
    printf("Tues: val = %d, size = %lu\n", Tues, sizeof(Tues));

    week day;
    scanf(" %d", (int32_t *)(&day));
    output_week(day);

    return EXIT_SUCCESS;
}