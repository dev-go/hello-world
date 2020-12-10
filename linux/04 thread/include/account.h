// Copyright (c) 2020, devgo.club
// All rights reserved.

#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <stdint.h>
#include <pthread.h>

#define ACCOUNT_NAME_LEN 20

typedef struct account_t
{
    int64_t id;
    char name[21];
    int64_t money;

    pthread_mutex_t locker;
} account_t;

typedef struct transfer_t
{
    account_t *from;
    account_t *to;
    int64_t money;
} transfer_t;

account_t *create_account(int64_t id, char *name);

void destroy_account(account_t *account);

int64_t query_money(account_t *account);

int deposit_money(account_t *account, int64_t money);

int withdraw_money(account_t *account, int64_t money);

int transfer_money(transfer_t *transfer);

#endif