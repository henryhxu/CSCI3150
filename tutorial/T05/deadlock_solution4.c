#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <pthread.h> 

int number = 0;

// macros
#define RUN_ROUNDS 20

// mutex locks 
pthread_mutex_t m1 = PTHREAD_MUTEX_INITIALIZER; 
pthread_mutex_t m2 = PTHREAD_MUTEX_INITIALIZER; 

int compare_and_add(int *p, int old){
    if(*p == old){
        *p = old + 1;
        return 1;
    }
    return 0;
}

// function which will be executed by thread1 
void* thread1(void *arg) 
{ 
    
    int old;
    do{
        old = number;
    }while(compare_and_add(&number, old) == 0);

    return 0; 
} 
 // function which will be executed by thread2 
void* thread2(void *arg) 
{ 
    
    int old;
    do{
        old = number;
    }while(compare_and_add(&number, old) == 0);
 
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