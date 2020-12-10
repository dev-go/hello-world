// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "greet.h"

char *hi(char *name)
{
    char *str = (char *)malloc(8 + strlen(name));
    sprintf(str, "Hi, %s!", name);
    return str;
}