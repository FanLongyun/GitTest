#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

int *thread(void *arg)
{
	pthread_t newthid;
	newthid = pthread_self();
	printf("this is a new thread, thread ID = %u\n", newthid);

	return 0;
}

int main()
{
	pthread_t thid;
	printf("main thread ,ID is %u\n", pthread_self());
	if(pthread_create(&thid, NULL, (void*)thread, NULL) != 0)
	{
		printf("thread creation failed.\n");
		exit(1);
	}
	sleep(1);
	return 0;
}
