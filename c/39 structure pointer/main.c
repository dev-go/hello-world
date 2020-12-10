// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <memory.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct _user_
{
    int64_t id;
    char *name;
} user;

int main(int argc, char const *argv[])
{
    struct _user_ u1 = {.id = 135139, .name = "dev-go"};
    printf("u1: id=%ld, name=%s\n", u1.id, u1.name);

    user *u2 = (user *)malloc(sizeof(user));
    u2->id = 2011135139;
    (*u2).name = "shfu";
    printf("u2: id=%ld, name=%s\n", (*u2).id, u2->name);
    free(u2);

    u2 = &u1;
    printf("u1: id=%ld, name=%s\n", u1.id, u1.name);
    printf("u2: id=%ld, name=%s\n", (*u2).id, u2->name);
    u1.id = 2011135139;
    printf("u1: id=%ld, name=%s\n", u1.id, u1.name);
    printf("u2: id=%ld, name=%s\n", (*u2).id, u2->name);
    u1.id = 135139;
    printf("u1: id=%ld, name=%s\n", u1.id, u1.name);
    printf("u2: id=%ld, name=%s\n", (*u2).id, u2->name);

    return EXIT_SUCCESS;
}