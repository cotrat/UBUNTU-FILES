#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void control_backslash_handler();
void control_c_handler();

int main(void)
{
	//signal(SIGINT, INThandler);
	signal(SIGINT,control_c_handler);
	signal(SIGQUIT,control_backslash_handler);

	
    	/*pthread_t threads[THREADS];
    	int threadArgs[THREADS];

        int ok= pthread_create(&threads[0],NULL,task,NULL);
	int ok= pthread_create(&threads[0],NULL,task,NULL);

        int ok= pthread_join(threads[t],NULL);*/
	while(1) {};
}

void control_backslash_handler()
{
	//signal(SIGQUIT,control_backslash_handler);
	printf("THE SIGQUIT HANDLER HAS BEEN CALLED\n");
	sleep(10);
	printf("THE SIGQUIT HANDLER HAS FINISHED\n");
	
}

void control_c_handler()
{
	//signal(SIGINT,control_c_handler);
	printf("THE SIGQINT HANDLER HAS BEEN CALLED\n");
	sleep(10);
	printf("THE SIGQINT HANDLER HAS FINISHED\n");
	
}

/*
void* task(void* arg)
{

}*/
