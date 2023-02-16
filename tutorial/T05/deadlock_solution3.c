#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <pthread.h> 
#include <errno.h>

int number = 0;

// macros
#define RUN_ROUNDS 20

// mutex locks 
pthread_mutex_t m1 = PTHREAD_MUTEX_INITIALIZER; 
pthread_mutex_t m2 = PTHREAD_MUTEX_INITIALIZER; 
// function which will be executed by thread1 
void* thread1(void *arg) 
{ 
    // acquiring lock m1 
TOP1:pthread_mutex_lock(&m1); 
    printf("Thread 1 acquired lock m1.\n"); 
    // acquiring lock m2 
    if(pthread_mutex_trylock(&m2) == EBUSY){
        // failed to acquire m2, release m1
        pthread_mutex_unlock(&m1);
        sleep(1);
        goto TOP1;
    } 
    printf("Thread 1 acquired lock m2.\n"); 
    printf("Thread 1 in critical section.\n"); 
    number ++;
    // releasing both locks 
    pthread_mutex_unlock(&m2); 
    pthread_mutex_unlock(&m1); 
    return 0; 
} 
// function which will be executed by thread2 
void* thread2(void *arg) 
{ 
    // acquiring lock m2 
TOP2:pthread_mutex_lock(&m2); 
    printf("Thread 2 acquired lock m2.\n"); 
    // acquiring lock m1 
    if(pthread_mutex_trylock(&m1) == EBUSY){
        // failed to acquire m1, release m2
        pthread_mutex_unlock(&m2);
        sleep(1);
        goto TOP2;
    } 
    printf("Thread 2 acquired lock m1.\n"); 
    printf("Thread 2 in critical section.\n"); 
    number ++;
    // releasing both locks 
    pthread_mutex_unlock(&m1); 
    pthread_mutex_unlock(&m2); 
    return 0; 
} 
 int main() 
{ 
    // declare two threads 
    pthread_t t1, t2; 
    for(int i=0;i<RUN_ROUNDS;i++){
        printf("Current round:%d\n",i);
        // create threads 
        pthread_create(&t1, NULL, thread1, NULL); 
        pthread_create(&t2, NULL, thread2, NULL); 
        // wait for terminated state of threads 
        pthread_join(t1, NULL); 
        pthread_join(t2, NULL); 
    }
    printf("Congratulations! No deadlock occurred. number = %d\n",number);
    return 0; 
}