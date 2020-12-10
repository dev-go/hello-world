// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <memory.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int64_t *create_array(int64_t len);

void delete_array(int64_t *array);

void print_array(int64_t *arr, int64_t len);

int main(int argc, char const *argv[])
{
    puts("demo1:");
    int64_t const LEN = 12;
    int64_t arr1[LEN];
    print_array(arr1, LEN);
    memset(arr1, 0, LEN * sizeof(int64_t));
    print_array(arr1, LEN);
    for (int64_t i = 0; i < LEN; ++i)
    {
        arr1[i] = 100 + i * 10;
    }
    for (int64_t i = 0; i < LEN; ++i)
    {
        printf("arr1[%ld] = %ld\n", i, *(arr1 + i));
    }
    printf("arr1 = %p\n", arr1);
    printf("&arr1[0] = %p\n", &arr1[0]);
    printf("&arr1[1] = %p\n", &arr1[1]);
    printf("arr1 + 1 = %p\n", (arr1 + 1));
    printf("arr1: size = %lu\n", sizeof(arr1));
    printf("arr1: len = %lu\n", sizeof(arr1) / sizeof(int64_t));

    puts("demo2:");
    int64_t *arr2 = create_array(LEN);
    print_array(arr2, LEN);
    printf("arr2 = %p\n", arr2);
    printf("&arr2[0] = %p\n", &arr2[0]);
    printf("&arr2[1] = %p\n", &arr2[1]);
    printf("arr2 + 1 = %p\n", arr2 + 1);
    printf("arr2: size = %lu\n", sizeof(arr2));
    delete_array(arr2);

    puts("demo3:");
    int64_t arr3[] = {1, 3, 5, 7, 9};
    int64_t len = sizeof(arr3) / sizeof(int64_t);
    for (int64_t i = 0; i < len; i++)
    {
        printf("arr3[%ld] = %ld\n", i, *(arr3 + i));
    }

    return EXIT_SUCCESS;
}
int64_t *create_array(int64_t len)
{
    int64_t *arr = malloc(len * sizeof(int64_t));
    memset(arr, 0, len * sizeof(int64_t));
    return arr;
}

void delete_array(int64_t *array)
{
    return free(array);
}

void print_array(int64_t *arr, int64_t len)
{
    for (int64_t i = 0; i < len; ++i)
    {
        printf("arr[%ld] = %ld\n", i, arr[i]);
    }
    return;
}