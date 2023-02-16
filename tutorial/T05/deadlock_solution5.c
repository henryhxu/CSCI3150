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
    pthread_mutex_lock(&m1); 
    printf("Thread 1 acquired lock m1.\n"); 
    // acquiring lock m2 
    pthread_mutex_lock(&m2); 
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
    pthread_mutex_lock(&m2); 
    printf("Thread 2 acquired lock m2.\n"); 
    // acquiring lock m1 
    pthread_mutex_lock(&m1); 
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
    int policy = SCHED_FIFO;
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_attr_setinheritsched(&attr, PTHREAD_EXPLICIT_SCHED);
    pthread_attr_setschedpolicy(&attr, policy);
    struct sched_param param;
    for(int i=0;i<RUN_ROUNDS;i++){
        printf("Current round:%d\n",i);
        // create threads 
        pthread_create(&t1, &attr, thread1, NULL);
        pthread_create(&t2, &attr, thread2, NULL);
        // wait for terminated state of threads 
        pthread_join(t1, NULL); 
        pthread_join(t2, NULL); 
    }
    printf("Congratulations! No deadlock occurred. number = %d\n",number);
    return 0; 
}