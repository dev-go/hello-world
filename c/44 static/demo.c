// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <stdint.h>
#include <stdio.h>

#include "demo.h"

int64_t static n3;

void f1()
{
    printf("f1: n1=%ld, n2=%ld, n3=%ld\n", n1, n2, n3);
    return;
}

void f2()
{
    printf("f1: n1=%ld, n2=%ld, n3=%ld\n", n1, n2, n3);
    printf("f1: n1_addr=%p\n", &n1);
    f1();
    return;
}

void set_n3(int64_t n)
{
    n3 = n;
    return;
}