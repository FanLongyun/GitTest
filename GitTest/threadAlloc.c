#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

int count;
pthread_mutex_t Mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_condattr_t Cond = PTHREAD_COND_INITIALIZER;

void *thread_proc(void* pArg)
{
	while(1)
	{
		pthread_mutex_lock(&Mutex);
		while(!count)
		{
			pthread_cond_wait(&Cond, &Mutex);
		}
		pthread_mutex_unlock(&Mutex);

		for(int i = 0; i < 25; i++)
			printf("thread running %d\n", i);
	}
}

int main(int argc, char **argv)
{
	count = 1;
	pthread_mutex_init(&Mutex, NULL);
	pthread_cond_init(&Cond, NULL);
	pthread_t th_ch1;
	pthread_create(&th_ch1, 0, thread_proc, 0);

	while(1)
	{
		pthread_mutex_lock(&Mutex);
		count = 0;
		pthread_mutex_unlock(&Mutex);
		
		printf("main thread running\n");

		if(count == 0)
		{
			pthread_mutex_lock(&Mutex);
			count = 1;
			pthread_cond_signal(&Cond);
			pthread_mutex_unlock(&Mutex);
		}
	}
	return 0;
}
