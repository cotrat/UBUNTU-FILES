#include <pthread.h>
#include <stdio.h>
#include "assert.h"
#include "buffer.h"



void bufInit(buffer* buf)
{
    buf->inp= 0;
    buf->oup= 0;
    buf->count= 0;
    
    int ok;
    ok= pthread_mutex_init(&buf->lock,NULL);
    assert(ok==0,"Can't init lock");
    ok= pthread_cond_init(&buf->notFull,NULL);
    assert(ok==0,"Can't init notFull");
    ok= pthread_cond_init(&buf->notEmpty,NULL);
    assert(ok==0,"Can't init notEmpty");

    pthread_cond_signal(&buf->notFull);
}


void bufPut(buffer* buf, char* str)
{
    int ok;
    ok= pthread_mutex_lock(&buf->lock);
    assert(ok==0,"bufPut can't lock");
    
    //Wait for space
    while( buf->count==BUFSIZE ){
        ok= pthread_cond_wait(&buf->notFull,&buf->lock);
	assert(ok==0,"bufPut can't await notFull");
    }

    //Store the data
    buf->data[buf->inp]= str;
    buf->inp++;
    if( buf->inp==BUFSIZE ){
        buf->inp= 0;
    }
    buf->count++;

    //Signal data available
    ok= pthread_cond_signal(&buf->notEmpty);
    assert(ok==0,"bufPut can't signal notEmpty");
    ok= pthread_mutex_unlock(&buf->lock);
    assert(ok==0,"bufPut can't unlock");
}



char* bufGet(buffer* buf)
{

    pthread_mutex_lock(&buf->lock);

    //Wait for data
    while( buf->count==0 ){
        int ok= pthread_cond_wait(&buf->notEmpty,&buf->lock);
	assert(ok==0,"bufPut can't await notEmpty");
    }

    //Fetch the data
    char* str= buf->data[buf->oup];
    buf->oup++;
    if( buf->oup==BUFSIZE ){
        buf->oup= 0;
    }
    buf->count--;

    //Signal space available
    pthread_cond_signal(&buf->notFull);
    pthread_mutex_unlock(&buf->lock);

    return str;
}

