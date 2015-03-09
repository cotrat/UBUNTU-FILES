#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
 
#define THREADS 15
 
void* task(void* argument);


int main(void)
{
    pthread_t threads[THREADS];
    int threadArgs[THREADS];
 	int t;
    //Create each thread
    for( t=0; t<THREADS; t++ ){
        threadArgs[t]= t;
        printf("main: Creating thread %d\n", t);
        int ok= pthread_create(&threads[t],NULL,task,(void*)&threadArgs[t]);
	if( ok!=0 ){
	  printf("main: could not create thread %d\n",t);
	    return 1;
	}
    }
 	t=0;
    //Wait for each thread to complete
    for (t=0; t<THREADS; t++ ){
        int ok= pthread_join(threads[t],NULL);
	if( ok!=0 ){
	  printf("main: Could not JOIN thread %d\n",t);
	    return 1;
	}
	printf("Main: Thread %d complete\n",t);
    }
 
    printf("main: Completed\n");
    return 0;
}



void* task(void* arg)
{
    int myId;
 
    myId= *((int*)arg);
    printf("    thread %d: Started\n",myId);
    
    sleep(3+myId);

    printf("    thread %d: Ending\n",myId);
 
    return NULL;
}
