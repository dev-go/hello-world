// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[], char const *envp[])
{
    for (int i = 0; i < argc; ++i)
    {
        printf("argv[%d] = %s\n", i, *(argv + i));
    }

    puts("==============================");

    for (int64_t i = 0; envp[i] != NULL; ++i)
    {
        printf("envp[%ld] = \"%s\"\n", i, envp[i]);

        for (int64_t j = 0; j < strlen(envp[i]); ++j)
        {
            if (envp[i][j] == '=')
            {
                char key[j + 1];
                strncpy(key, envp[i], j);
                key[sizeof(key) - 1] = '\0';
                char value[strlen(envp[i]) - j];
                strcpy(value, envp[i] + (j + 1));
                value[sizeof(value) - 1] = '\0';
                printf("\t key: %s, value: %s\n", key, value);
                break;
            }
        }
    }

    return EXIT_SUCCESS;
}
