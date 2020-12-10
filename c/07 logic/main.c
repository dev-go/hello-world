// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

uint8_t const ALL = 100;
uint8_t const GOOD = 80;
uint8_t const PASS = 60;
uint8_t const ZERO = 0;

void grade_score(uint8_t score);

int main(int argc, char const *argv[])
{
    uint8_t score = 66;
    grade_score(score);
    score = 98;
    grade_score(score);
    score = 34;
    grade_score(score);

    return EXIT_SUCCESS;
}

void grade_score(uint8_t score)
{
    if (score < ZERO || score > ALL)
    {
        printf("invalid score: score = %hhu\n", score);
    }
    else if (score < PASS)
    {
        printf("fail: score = %hhu\n", score);
    }
    else if (score < GOOD)
    {
        printf("pass: score = %hhu\n", score);
    }
    else
    {
        printf("good: score = %hhu\n", score);
    }
    return;
}