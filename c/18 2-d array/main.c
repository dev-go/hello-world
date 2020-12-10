// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <memory.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    puts("demo1:");
    int64_t LEN_1 = 4;
    int64_t LEN_2 = 5;
    int64_t arr1[LEN_1][LEN_2];
    printf("arr1: size = %lu\n", sizeof(arr1));
    memset(arr1, 0, sizeof(arr1));
    for (int64_t i = 0; i < LEN_1; ++i)
    {
        for (int64_t j = 0; j < LEN_2; ++j)
        {
            arr1[i][j] = i * 100 + j;
        }
    }
    for (int64_t i = 0; i < LEN_1; ++i)
    {
        for (int64_t j = 0; j < LEN_2; ++j)
        {
            printf("arr1[%ld][%ld] = %ld\t", i, j, *(arr1[i] + j));
        }
        putchar('\n');
    }
    for (int64_t i = 0; i < LEN_1; ++i)
    {
        for (int64_t j = 0; j < LEN_2; ++j)
        {
            printf("arr1[%ld][%ld] = %ld\t", i, j, (*(arr1 + i))[j]);
        }
        putchar('\n');
    }
    for (int64_t i = 0; i < LEN_1; ++i)
    {
        for (int64_t j = 0; j < LEN_2; ++j)
        {
            printf("arr1[%ld][%ld] = %ld\t", i, j, *(*(arr1 + i) + j));
        }
        putchar('\n');
    }

    puts("demo2:");
    int64_t arr2[][3] = {
        {77, 23, 43},
        {61, 57, 32},
    };
    printf("arr2: size = %lu\n", sizeof(arr2));
    for (int64_t i = 0; i < sizeof(arr2) / sizeof(int64_t) / 3; i++)
    {
        for (int64_t j = 0; j < 3; j++)
        {
            printf("arr2[%ld][%ld] = %ld\t", i, j, *(*(arr2 + i) + j));
        }
        putchar('\n');
    }

    puts("demo3:");
    int64_t **arr3 = (int64_t **)malloc(3 * sizeof(int64_t *));
    int64_t arr3_1[] = {1, 2, 3, 4, 5};
    int64_t arr3_len1 = sizeof(arr3_1) / sizeof(int64_t);
    int64_t arr3_2[] = {21, 22, 23, 24};
    int64_t arr3_len2 = sizeof(arr3_2) / sizeof(int64_t);
    int64_t arr3_3[] = {234, 331, 454, 224, 908, 776};
    int64_t arr3_len3 = sizeof(arr3_3) / sizeof(int64_t);
    arr3[0] = arr3_1;
    *(arr3 + 1) = arr3_2;
    *(arr3 + 2) = arr3_3;
    for (int64_t i = 0; i < 3; ++i)
    {
        if (i == 0)
        {
            for (int64_t j = 0; j < arr3_len1; ++j)
            {
                printf("arr3[%ld][%ld] = %ld\t", i, j, *(*(arr3 + i) + j));
            }
            putchar('\n');
        }
        if (i == 1)
        {
            for (int64_t j = 0; j < arr3_len2; ++j)
            {
                printf("arr3[%ld][%ld] = %ld\t", i, j, *(*(arr3 + i) + j));
            }
            putchar('\n');
        }
        if (i == 2)
        {
            for (int64_t j = 0; j < arr3_len3; ++j)
            {
                printf("arr3[%ld][%ld] = %ld\t", i, j, *(*(arr3 + i) + j));
            }
            putchar('\n');
        }
    }
    free(arr3);

    return EXIT_SUCCESS;
}