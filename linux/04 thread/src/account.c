// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

#include "account.h"

account_t *create_account(int64_t id, char *name)
{
    if (name == NULL || strlen(name) == 0)
    {
        return NULL;
    }

    account_t *account = calloc(1, sizeof(account_t));
    account->id = id;
    strncpy(account->name, name,
            strlen(name) > 20 ? 20 : strlen(name));
    pthread_mutex_init(&(account->locker), NULL);
    return account;
}

void destroy_account(account_t *account)
{
    if (account == NULL)
    {
        return;
    }

    pthread_mutex_destroy(&(account->locker));
    free(account);
    return;
}

int64_t query_money(account_t *account)
{
    if (account == NULL)
    {
        return -1;
    }

    pthread_mutex_lock(&(account->locker));
    int64_t money = account->money;
    pthread_mutex_unlock(&(account->locker));
    return money;
}

int deposit_money(account_t *account, int64_t money)
{
    if (account == NULL || money < 0)
    {
        return EINVAL;
    }

    pthread_mutex_lock(&(account->locker));
    account->money += money;
    pthread_mutex_unlock(&(account->locker));
    return 0;
}

int withdraw_money(account_t *account, int64_t money)
{
    if (account == NULL || money < 0)
    {
        return EINVAL;
    }

    int ret = 0;
    pthread_mutex_lock(&(account->locker));
    if (account->money < money)
    {
        ret = -2;
    }
    else
    {
        account->money -= money;
    }
    pthread_mutex_unlock(&(account->locker));
    return ret;
}

int transfer_money(transfer_t *transfer)
{
    if (transfer == NULL || transfer->from == NULL ||
        transfer->to == NULL || transfer->money < 0)
    {
        return -2;
    }

    int ret = 0;
    if (transfer->from->id < transfer->to->id)
    {
        pthread_mutex_lock(&(transfer->from->locker));
        pthread_mutex_lock(&(transfer->to->locker));
    }
    else
    {
        pthread_mutex_lock(&(transfer->to->locker));
        pthread_mutex_lock(&(transfer->from->locker));
    }

    // TODO: >>>
    printf(">>> [%ld] transfer: from = %ld <%ld>, to = %ld <%ld>, money = %ld\n",
           pthread_self(), transfer->from->id, transfer->from->money,
           transfer->to->id, transfer->to->money, transfer->money);
    // TODO: <<<

    if (transfer->from->money < transfer->money)
    {
        ret = -2;
    }
    else
    {
        transfer->from->money -= transfer->money;
        transfer->to->money += transfer->money;
    }

    // TODO: >>>
    sleep(2);
    printf("<<< [%ld] transfer: from = %ld <%ld>, to = %ld <%ld>, money = %ld\n",
           pthread_self(), transfer->from->id, transfer->from->money,
           transfer->to->id, transfer->to->money, transfer->money);
    // TODO: <<<

    if (transfer->from->id < transfer->to->id)
    {
        pthread_mutex_unlock(&(transfer->to->locker));
        pthread_mutex_unlock(&(transfer->from->locker));
    }
    else
    {
        pthread_mutex_unlock(&(transfer->from->locker));
        pthread_mutex_unlock(&(transfer->to->locker));
    }

    return ret;
}