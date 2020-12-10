// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <stdint.h>
#include <pthread.h>
#include <errno.h>
#include <string.h>

#include "account.h"

void *th_start_func(void *arg)
{
    transfer_t *transfer = (transfer_t *)arg;
    transfer_money(transfer);
    return NULL;
}

int main(int argc, char const *argv[])
{
    account_t *a1 = create_account(1, "001");
    account_t *a2 = create_account(2, "002");
    deposit_money(a1, 10000);
    deposit_money(a2, 5000);
    printf("[%ld] a1: %ld <%ld>, a2: %ld <%ld>\n",
           pthread_self(), a1->id, query_money(a1), a2->id, query_money(a2));

    pthread_t th_id1;
    transfer_t th_arg1 = {.from = a1,
                          .to = a2,
                          .money = 1000};
    pthread_t th_id2;
    transfer_t th_arg2 = {.from = a2,
                          .to = a1,
                          .money = 100};
    pthread_create(&th_id1, NULL, &th_start_func, (void *)&th_arg1);
    pthread_create(&th_id2, NULL, &th_start_func, (void *)&th_arg2);

    pthread_join(th_id1, NULL);
    pthread_join(th_id2, NULL);

    printf("[%ld] a1: %ld <%ld>, a2: %ld <%ld>\n",
           pthread_self(), a1->id, query_money(a1), a2->id, query_money(a2));

    return EXIT_SUCCESS;
}