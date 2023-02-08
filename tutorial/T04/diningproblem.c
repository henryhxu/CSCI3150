/* 

Compile program with 
 gcc -o diningproblem -pthread diningproblem.c
Run executable ./diningproblem
*/

#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

// Definitions for number of philosophers,
// left philosopher and right philosopher
#define NUMPHIL 5
#define LEFT ((id-1)+NUMPHIL) % 5
#define RIGHT (id+1) % 5

//Array for number of philosophers and Enum for their states
enum{THINKING, HUNGRY, EATING} state[NUMPHIL];
int identity[5] = {0,1,2,3,4};

// Mutex, condition variable array for each philosopher,
// and the phillosphers threads array
pthread_mutex_t lock;
pthread_cond_t cond[NUMPHIL];
pthread_t phil[NUMPHIL];

// Funtion declarations
void think(int id);
void pickup_forks(int id);
void eat(int id);
void return_forks(int id);
void *philosopher(void *num);

int main(){
	//Initialize the mutex lock and conditional variable
	int i=0;

	if (pthread_mutex_init(&lock,NULL) != 0) {
		printf("\n mutex init has failed\n");
		return 1;
	}

	//Create the five philosophers threads
	for (i = 0; i < NUMPHIL; i++) {
		if(pthread_cond_init(&cond[i], NULL)!=0){
			printf("\n cond init has failed\n");
			return 1;
		}
	}

	//Create the five philosophers threads
	for (i = 0; i < NUMPHIL; i++) {
		pthread_create(&phil[i], NULL, philosopher, &identity[i]);
	}

	//Join all five philosophers threads
	for (i = 0; i < NUMPHIL; i++) {
		pthread_join(phil[i], NULL);
	}

	//Destroy the mutex and conditional variables
	pthread_mutex_destroy(&lock);
	for (i = 0; i < NUMPHIL; i++) {
		pthread_cond_destroy(&cond[i]);
	}
	return 0;
}

//Philosopher wastes time to think now
void think(int id){
	int thinkTime = ((rand()) % 3) +1;

	printf("Philosopher %d is thinking for %d seconds\n", id, thinkTime);
	sleep(thinkTime);
	printf("Philosopher %d reappears from sleep from thinking\n", id);
}

//Checks to see if the philopher can pick up thier adjacent forks to eat
//If succesful, change enum state to HUNGRY FIRST AND EATING AFTER
//If not, philosopher is blocked by their conditional variable cond[id]
void pickup_forks(int id){
	int left = LEFT;
	int right = RIGHT;
	pthread_mutex_lock(&lock);
	state[id] = HUNGRY;

	while((state[id] == HUNGRY) && ((state[left] == EATING) || (state[right] == EATING))){
		printf("Philosopher %i is hungry and waiting to pickup forks to eat \n", id);
		pthread_cond_wait(&cond[id], &lock);
	}
	state[id] = EATING;
	printf("Philosopher %d is allowed to eat now \n", id);
	pthread_mutex_unlock(&lock);
}

//After getting the forks, the philosopher can eat now
void eat(int id){
	int eatingTime = ((rand()) % 3) +1;

	printf("Philosopher %d is eating for %d seconds\n", id, eatingTime);
	sleep(eatingTime);
	printf("Philosopher %d reappears from sleep from eating\n", id);
}

//After the philosophers eat, put down the forks and change enum state to THINKING.
//Signal the current left and right phillosphers blocked by their conditional
//variable to have a chance to see if they can eat now
void return_forks(int id){
	int left = LEFT;
	int right = RIGHT;
	pthread_mutex_lock(&lock);
	state[id]= THINKING;

	printf("Philosopher %d has put down forks\n", id);
	pthread_cond_signal(&cond[left]);
	printf("Philosopher %d signaled philosopher %d to see if it can eat\n", id, left);
	pthread_cond_signal(&cond[right]);
	printf("Philosopher %d signaled philosopher %d to see if it can eat\n", id, right);
	pthread_mutex_unlock(&lock);
}

//Main philosopher method  creating the five phillospher threads
void* philosopher(void* num){
	int id = *((int *) num);

	while(1){
		think(id);
		pickup_forks(id);
		eat(id);
		return_forks(id);
	}
}
