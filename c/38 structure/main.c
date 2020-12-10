// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <memory.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int64_t id;
    char *name;
} user;

user *create_user(int64_t id, char *name)
{
    char *_name = malloc(strlen(name) * sizeof(char));
    strcpy(_name, name);
    user *_user = (user *)malloc(sizeof(user));
    _user->id = id;
    _user->name = _name;
    return _user;
}

void delete_user(user *_user)
{
    free(_user->name);
    free(_user);
    return;
}

char *to_string(user *_user)
{
    int64_t const _len = (1 << 5) + strlen(_user->name);
    char *buf = malloc(_len);
    memset(buf, 0, _len);
    sprintf(buf, "{id: %ld, name: \"%s\"}", _user->id, _user->name);
    return buf;
}

int main(int argc, char const *argv[])
{
    user *u1 = create_user(2011135139, "dev-go");
    char *s1 = to_string(u1);
    printf("u1: %s\n", s1);
    free(s1);
    u1->id = 135139;
    s1 = to_string(u1);
    printf("u1: %s\n", s1);
    free(s1);
    printf("u1: id=%ld, name=%s\n", u1->id, (*u1).name);
    delete_user(u1);

    return EXIT_SUCCESS;
}