// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

char *get_platform();

int main(int argc, char const *arg[])
{
    char *p = get_platform();
    printf("PLATFORM: %s\n", p);
    free(p);

    return EXIT_SUCCESS;
}

char *get_platform()
{
    char *info = (char *)malloc(1 << 6 * sizeof(char));
#if PLATFORM == 1
    sprintf(info, "Linux");
#elif PLATFORM == 2
    sprintf(info, "macOS");
#elif PLATFORM == 3
    sprintf(info, "Windows");
#else
    sprintf(info, "unkonwn");
#endif
    return info;
}

/*
$ gcc main.c 
$ ./a.out
PLATFORM: unkonwn
$ gcc -DPLATFORM=1 main.c 
$ ./a.out
PLATFORM: Linux
*/