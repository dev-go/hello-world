// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <stdlib.h>
#include <stdio.h>
#include <setjmp.h>

jmp_buf jmp;

int g_v = 1;

void func();

int main(int argc, char const *argv[])
{
    static int s_v = 1;
    auto int a_v = 1;
    register int r_v = 1;
    volatile int v_v = 1;
    int *h_v = (int *)malloc(sizeof(int));
    *h_v = 1;
    printf("g_v=%d, s_v=%d, a_v=%d, r_v=%d, v_v=%d, *h_v=%d\n",
           g_v, s_v, a_v, r_v, v_v, *h_v);

    if (setjmp(jmp) != 0)
    {
        printf(">>>\n");
        printf("g_v=%d, s_v=%d, a_v=%d, r_v=%d, v_v=%d, *h_v=%d\n",
               g_v, s_v, a_v, r_v, v_v, *h_v);
        printf("<<<\n");
        exit(EXIT_FAILURE);
    }

    g_v = 10;
    s_v = 10;
    a_v = 10;
    r_v = 10;
    v_v = 10;
    *h_v = 10;
    printf("g_v=%d, s_v=%d, a_v=%d, r_v=%d, v_v=%d, *h_v=%d\n",
           g_v, s_v, a_v, r_v, v_v, *h_v);

    func();

    return EXIT_SUCCESS;
}

void func()
{
    longjmp(jmp, 1);
}