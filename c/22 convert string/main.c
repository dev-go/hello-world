// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef float float32;
typedef double float64;

int main(int argc, char const *argv[])
{
    puts("demo1:");
    char *s1 = "1024";
    int64_t n1;
    sscanf(s1, "%ld", &n1);
    printf("s1=\"%s\", n1=%ld\n", s1, n1);

    puts("demo2:");
    int32_t n2 = atoi(s1);
    printf("%d\n", n2);

    puts("demo3:");
    char *s2 = "3.1415926";
    float64 f1 = atof(s2);
    printf("%.7f\n", f1);

    puts("demo4:");
    int64_t n3 = 1024;
    uint8_t n4 = 245;
    char *s3 = malloc(sizeof(char) * (1 << 6));
    sprintf(s3, "n3=%ld, n4=%hhu", n3, n4);
    printf("s3: val=%s, addr=%p\n", s3, s3);
    free(s3);

    return EXIT_SUCCESS;
}