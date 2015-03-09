#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
 
#define THREADS 8
 
void* task(void* argument);

int var=0;
int max= -2147483647;
int min= +2147483647;
pthread_mutex_t lock;


int main(void)
{
  pthread_mutex_init(&lock,NULL);

    pthread_t threads[THREADS];
    int threadArgs[THREADS];
 int t;
    //Create each thread
    for(t=0; t<THREADS; t++ ){
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
    printf("min= %d\n",min);
    printf("max= %d\n",max);
 
    printf("main: Completed\n");
    return 0;
}



void* task(void* arg)
{
    int myId;
 
    myId= *((int*)arg);
    printf("    thread %d: Started\n",myId);

    int incDec= +1;
    if(myId%2==1 ){
        incDec=-1;
    }
int i;
    for( i=0; i<10000; i++ ){
        pthread_mutex_lock(&lock);
	var=var+incDec;
	if( var> max ){
	  max= var;
	}
	if( var< min ){
	  min= var;
	}
        pthread_mutex_unlock(&lock);
    }

    printf("    thread %d: var= %d\n",myId,var);
    printf("    thread %d: Ending\n",myId);
 
    return NULL;
}
