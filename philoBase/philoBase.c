/*
 * Gabriel Espinosa
 * Lab/Task: Lab6
 * March 4, 2019
 */

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
pthread_mutex_t monitor_mutex;
#define DELAY ( (rand() % 5 + 1) * 1000)
int numOfSeats, numOfTurns;
void *philosopher(void *id);
pthread_cond_t *self;
//pthread_mutex_t *chopstick;
void putdown(int i);
void pickup(int i);

void test(int i );


enum State {
    THINKING = 0,
    HUNGRY,
    EATING
}*state;


void initialization_code(int numOfSeats);
void putdown(int i);
void pickup(int i);

void test(int i );

int main(int argc, char **argv)
{
    if (argc < 3)
    {
        printf("Usage: philosophers <number of seats> <number of turns>");
        return 1;
    }

    numOfSeats = strtod(argv[1], NULL);
    numOfTurns = strtod(argv[2], NULL);



    // set the see for random number generator
    srand(time(NULL));

    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

    printf("Start a dinner for %d diners\n", numOfSeats);
    initialization_code(numOfSeats);
    state = malloc(numOfSeats*sizeof(int));
    self = malloc(numOfSeats*sizeof(pthread_cond_t));
    pthread_t philosopher_tid[numOfSeats];

    long i;
//    for (i = 0; i < numOfSeats; i++)
//        pthread_mutex_init(chopstick + i, NULL);

    for (i = 0; i < numOfSeats; i++)
        pthread_create(&philosopher_tid[i], NULL, philosopher, (void *) i);

    for (i = 0; i < numOfSeats; i++)
        pthread_join(philosopher_tid[i], NULL);
//
//    for (i = 0; i < numOfSeats; i++)
     pthread_mutex_destroy(&monitor_mutex );
         free(state);
    printf("Dinner is no more.\n");

    return 0;
}


void *philosopher(void *num)
{
    int id = (long) num;

    printf("Philsopher no. %d sits at the table.\n", id);

    // philosophers arrive at the table at various times
    usleep(DELAY);

    for (int i = 0; i < numOfTurns; i++)
    {
          printf("Philsopher no. %d gets hungry for the %d time!\n", id, i + 1);
//
//        printf("Philsopher no. %d tries to grab chopstick %d\n", id, id);
          pickup(id);

//        pthread_mutex_lock(&(chopstick[id]));
//        printf("Philsopher no. %d has grabbed chopstick %d\n", id, id);


          printf("Philsopher no. %d tries to grab chopstic %d\n", id, (id + 1) % numOfSeats);
//        pthread_mutex_lock(&(chopstick[(id + 1) % numOfSeats]));
//        printf("Philsopher no. %d grabbed chopstick %d\n", id, (id + 1) % numOfSeats);
//
//        // YEEEAAAAH !!!
          printf("Philsopher no. %d eating\n", id);
//
          usleep (DELAY);
//
//        printf("Philsopher no. %d stopped eating\n", id);
//        pthread_mutex_unlock(&(chopstick[id]));
//        printf("Philsopher no. %d has returned chopstick %d\n", id, id);
//        usleep(DELAY * 1);
//        pthread_mutex_unlock(&(chopstick[(id + 1) % numOfSeats]));
//        printf("Philsopher no. %d has returned chopstick %d\n", id, (id + 1) % numOfSeats);
//
//        printf("Philsopher no. %d finished turn %d\n", id, i + 1);

          putdown(id);
          printf("Philsopher no. %d stopped eating\n", id);
          printf("Philsopher no. %d finished turn %d\n", id, i + 1);

    }

    printf(">>>>>> Philsopher no. %d finished meal. <<<<<<\n", id);

    pthread_exit(NULL);
}


void pickup(int i)
{
    pthread_mutex_lock(&monitor_mutex);
    state[i] = HUNGRY;
    test(i);
    if(state[i] != EATING)
    {
        printf("Philosopher %d is Waiting to eat\n", i);
        pthread_cond_wait(&self[i],&monitor_mutex);
    }pthread_mutex_unlock(&monitor_mutex);
}
void putdown(int i)
{
    state[i] = THINKING;
    printf("Philosopher %d is finished eating\n", i);
    test((i+numOfSeats-1)%numOfSeats);
    /////////////////////////////////////////////////////
}
void test(int i )
{
    if ( (state[(i + numOfSeats-1) % numOfSeats] != EATING) && (state[(i + 1) % numOfSeats] != EATING)&&(state[i] == HUNGRY) )
    {
        state[i] = EATING;
        printf("Philosopher %d is eating\n", i);
        pthread_cond_signal(&self[i]);
    }
}
void initialization_code(int numOfSeats)
{
    for(int i = 0; i < numOfSeats; i ++)
    {
        state[i] = THINKING;
    }
}