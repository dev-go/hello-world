// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <stdio.h>

#include "a.h"
#include "b.h"

void b1()
{
    printf("b1\n");
    a2();
    return;
}

void b2()
{
    printf("b2\n");
    return;
}