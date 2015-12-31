// Copyright (c) 2015 Runtime Verification, Inc. (RV-Match team). All Rights Reserved.

#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>


pthread_mutex_t * lock_ptr;

int main(void)
{
    lock_ptr = malloc(sizeof(pthread_mutex_t));
    pthread_mutex_destroy(lock_ptr);
    return 0;
}
