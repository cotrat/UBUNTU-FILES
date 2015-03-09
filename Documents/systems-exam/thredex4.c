#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
 
#define THREADS 10000
 
void* task(void* argument);

int var=0;


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
 
    //Wait for each thread to complete
    for (t=0; t<THREADS; t++ ){
        int ok= pthread_join(threads[t],NULL);
	if( ok!=0 ){
	  printf("main: Could not JOIN thread %d\n",t);
	    return 1;
	}
	printf("Main: Thread %d complete\n",t);
    }

    printf("After all, var= %d\n",var);
 
    printf("main: Completed\n");
    return 0;
}



void* task(void* arg)
{
    int myId;
 	int i;
    myId= *((int*)arg);
    printf("    thread %d: Started\n",myId);

    int incDec= +1;
    if(myId%2==1 ){
        incDec=-1;
    }

    for( i=0; i<10000; i++ ){
        var=var+incDec;
    }

    printf("    thread %d: var= %d\n",myId,var);
    printf("    thread %d: Ending\n",myId);
 
    return NULL;
}
 
