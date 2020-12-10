// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <stdbool.h>

int main(int argc, char const *argv[])
{
    char const *ENV_K = "HELLO";
    char const *ENV_V1 = "C";
    char const *ENV_V2 = "C++";
    char *ret = 0;

    fprintf(stdout, "env : %s\n", getenv(ENV_K));

    if (setenv(ENV_K, ENV_V1, true) != 0)
    {
        fprintf(stderr, "setenv failed: %s, key = %s, value = %s\n", strerror(errno), ENV_K, ENV_V1);
        return errno;
    }

    fprintf(stdout, "env : %s\n", getenv(ENV_K));

    if (setenv(ENV_K, ENV_V2, true) != 0)
    {
        fprintf(stderr, "setenv failed: %s, key = %s, value = %s\n", strerror(errno), ENV_K, ENV_V2);
        return errno;
    }

    fprintf(stdout, "env : %s\n", getenv(ENV_K));

    if (unsetenv(ENV_K) != 0)
    {
        fprintf(stderr, "unsetenv failed: %s, key = %s\n", strerror(errno), ENV_K);
        return errno;
    }

    fprintf(stdout, "env : %s\n", getenv(ENV_K));

    return EXIT_SUCCESS;
}