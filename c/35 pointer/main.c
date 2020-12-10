// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <memory.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    int64_t n1 = 1 << 12;
    int64_t *p1 = &n1;
    printf("n1: val=%ld, addr=%p\n", n1, &n1);
    printf("p1: val=%p, addr=%p, ref=%ld\n", p1, &p1, *p1);
    n1 = n1 << 8;
    printf("n1: val=%ld, addr=%p\n", n1, &n1);
    printf("p1: val=%p, addr=%p, ref=%ld\n", p1, &p1, *p1);
    *p1 = (*p1) >> 10;
    printf("n1: val=%ld, addr=%p\n", n1, &n1);
    printf("p1: val=%p, addr=%p, ref=%ld\n", p1, &p1, *p1);

    puts("==============================================");

    int64_t n2 = 53;
    int64_t const *p2 = &n2;
    printf("n2: val=%ld, addr=%p\n", n2, &n2);
    printf("p2: val=%p, addr=%p, ref=%ld\n", p2, &p2, *p2);
    // *p2 = 66; // error: assignment of read-only location '*p2'
    n2 = 66;
    printf("n2: val=%ld, addr=%p\n", n2, &n2);
    printf("p2: val=%p, addr=%p, ref=%ld\n", p2, &p2, *p2);
    p2 = p1;
    printf("n2: val=%ld, addr=%p\n", n2, &n2);
    printf("p2: val=%p, addr=%p, ref=%ld\n", p2, &p2, *p2);

    puts("==============================================");

    int64_t n3 = 88;
    int64_t *const p3 = &n3;
    printf("n3: val=%ld, addr=%p\n", n3, &n3);
    printf("p3: val=%p, addr=%p, ref=%ld\n", p3, &p3, *p3);
    n3 = 87;
    printf("n3: val=%ld, addr=%p\n", n3, &n3);
    printf("p3: val=%p, addr=%p, ref=%ld\n", p3, &p3, *p3);
    *p3 = *p3 + 5;
    printf("n3: val=%ld, addr=%p\n", n3, &n3);
    printf("p3: val=%p, addr=%p, ref=%ld\n", p3, &p3, *p3);
    // p3 = p2; // error: assignment of read-only variable 'p3'
    // p3 = &n2; // error: assignment of read-only variable 'p3'

    puts("==============================================");

    int64_t n4 = 166;
    int64_t const *const p4 = &n4;
    printf("n4: val=%ld, addr=%p\n", n4, &n4);
    printf("p4: val=%p, addr=%p, ref=%ld\n", p4, &p4, *p4);
    n4 = 188;
    printf("n4: val=%ld, addr=%p\n", n4, &n4);
    printf("p4: val=%p, addr=%p, ref=%ld\n", p4, &p4, *p4);
    // p4 = p1; // error: assignment of read-only variable 'p4'
    // *p4 = 200; // error: assignment of read-only location '*p4'

    puts("==============================================");

    char const *s1 = "HelloWorld";
    printf("s1 = %s\n", s1);
    s1 = "hello";
    printf("s1 = %s\n", s1);
    // s1[0] = 'H';     // error: assignment of read-only location '*s1'
    // *(s1 + 0) = 'H'; // error: assignment of read-only location '*s1'
    char s2[] = "dev-go";
    char *const s3 = s2;
    printf("s3 = %s\n", s3);
    s3[0] = 'D';
    printf("s3 = %s\n", s3);
    *(s3 + 0) = 'd';
    printf("s3 = %s\n", s3);
    // s3 = "devgo.club"; // error: assignment of read-only variable 's3'
    char const *const s4 = s2;
    printf("s4 = %s\n", s4);
    // s4[0] = 'D'; // error: assignment of read-only location '*s4'
    // *(s4 + 0) = 'D'; // error: assignment of read-only location '*s4'
    // s4 = s3; // error: assignment of read-only variable 's4'

    return EXIT_SUCCESS;
}