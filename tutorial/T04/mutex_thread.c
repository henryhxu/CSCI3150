#include <stdio.h>
#include <pthread.h>
#include<unistd.h>
#include<stdlib.h>

pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;

int shared_counter = 0;

int identity[2]={0,1};
void *increment_counter(void* num) {
  int i;
  int finish=0;
  while(finish==0)
  {
        int t = ((rand()) % 3) +1;
    	pthread_mutex_lock(&mtx);
        if(shared_counter>=20)
        {
            finish=1;
            pthread_mutex_unlock(&mtx);
            break;
        }
        shared_counter++;
    	printf("The %d thread increase counter from %d to %d\n",*(int *)num,shared_counter-1,shared_counter);
    	pthread_mutex_unlock(&mtx);
        sleep(t);

  }
  return NULL;
}

int main(void) {
  pthread_t first, second;

  pthread_create(&first, NULL, increment_counter, &identity[0]);
  pthread_create(&second, NULL, increment_counter, &identity[1]);

  pthread_join(first, NULL);
  pthread_join(second, NULL);

  printf("Final value of shared counter: %d\n", shared_counter);

  return 0;
}
