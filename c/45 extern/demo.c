// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <stdint.h>
#include <stdio.h>

#include "demo.h"

int64_t num = 1 << 10;

// n1 = 99; // warning: type defaults to 'int' in declaration of 'n1'  error: conflicting types for 'n1'

// int64_t n2 = 88; // error: redefinition of 'n2'

void func()
{
    ++num;
    printf("func: num: val=%ld, addr=%p\n", num, &num);
}