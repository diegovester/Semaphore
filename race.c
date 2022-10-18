#include <pthread.h>
#include <stdio.h>
#include <semaphore.h>

#define NUM_THREADS 10000
pthread_t tid[ NUM_THREADS ];

int count = 0;
sem_t sema;

void * func( void * arg )
{
    sem_wait( &sema );
    {
        count ++;
    }
    sem_post( &sema );
    return NULL;
}

int main()
{
    int i;
    sem_init( &sema, 0, 1 );
    for( i = 0; i < NUM_THREADS; i++ )
    {
        pthread_create( &tid[i], NULL, func, NULL );

    }

    for( i = 0; i < NUM_THREADS; i++ )
    {
        pthread_join( tid[i], NULL );
    }

    printf("Count: %d\n", count );
}