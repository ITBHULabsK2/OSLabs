#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#include<string.h>
//#include <time.h>
#include <sys/wait.h>
#define BUFFERSIZE 7


void *producer(void *param1);
void *consumer(void *param2);
sem_t full,empty;

pthread_t tid[100];
pthread_mutex_t mutex;
int in=0,out=0;
int main(int argv,char *argc[])
{
  	int END_TIME,n,m;
  	int i,j;
  	
  	sem_init(&full,0,0);
  	sem_init(&empty,0,BUFFERSIZE);
  
 	pthread_mutex_init(&mutex,NULL);
   
   	printf("enter end  time, no of producer & no of consumer\n");
   	scanf("%d %d %d",&END_TIME,&n,&m); 
	printf("\n");
	 
	printf("\nCreating the Producers \n"); 
	for(i=0;i<n;i++)
     		pthread_create(&tid[i],NULL,producer,&i);
    	
    	printf("\nCreating the Consumers \n"); 
	for( j=0;j<m;j++)
     		pthread_create(&tid[j],NULL,consumer,&j);
    
    	printf("\nInitiating the Producer-Consumer transaction . Process continues for %d secs \n",END_TIME);
    	sleep(END_TIME);
    	printf("\nAlloted time finished \t Process going to terminate\n");
	return 0;
}
	
void *producer(void *param1)
{
   int prod=*(int *)param1;
   printf("producer %d born\n",prod);
   
   while(1)
   {
    sleep(2);
	  printf("\nproducer %d try to enter in critical sec\n",prod);
     sem_wait(&empty);
     pthread_mutex_lock(&mutex);
        
     in=(in+1)%BUFFERSIZE;
        printf("producer %d holds critical section \n produces -> %d\n",prod,in);
       
      pthread_mutex_unlock(&mutex);
     sem_post(&full);
      printf("producer %d releases\n",prod);
     }
}	 

void *consumer(void *param2)
{
   int cons=*(int *)param2;
   printf("consumer %d born\n",cons);
   
   while(1)
   {
    sleep(2);
	  printf("\nconsumer %d try to enter in critical sec\n",cons);
     sem_wait(&full);
      pthread_mutex_lock(&mutex);
        
       out=(out+1)%BUFFERSIZE;
        printf("consumer %d hold critical section\n consume -> %d\n",cons,out);
       
      pthread_mutex_unlock(&mutex);
     sem_post(&empty);
      printf("consumer %d releases\n",cons);
     }
}	 

