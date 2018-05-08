#include <stdio.h>
#include <pthread.h>

void assisthread(void *arg)
{
	printf("I am helping to do some jobs.\n");
	sleep(1);
	pthread_exit(0);
}

int main()
{
	pthread_t assisthid;
	int status;

	pthread_create(&assisthid, NULL, (void*)assisthread, NULL);
	pthread_join(assisthid, (void*)&status);
	printf("assisthread's exit is caused %d\n", status);

	return 0;
}
