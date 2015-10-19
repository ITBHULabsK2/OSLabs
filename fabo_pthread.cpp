#include<pthread.h>
#include<stdio.h>
int fab[100];
int fabo(int p);
int n;
void *runner(void *param);
int main(int argv,char *argc[])
{
 pthread_t tid[100];
 pthread_attr_t attr;
 pthread_attr_init(&attr);

printf("enter value of n");
 scanf("%d",&n);
 
for(int i=0;i<n;i++)
 pthread_create(&tid[i],&attr,runner,&i);

for(int i=0;i<n;i++)
pthread_join(tid[i],NULL);

for(int i=0;i<n;i++)
printf("%d ",fab[i]);
}

void *runner(void *param)
{
 int h=*(int *)param;
 fab[h]=fabo(h);
 
}

int fabo(int j)
{
 if(j==0||j==1)
return j;
 else
return(fab[j-1]+fab[j-2]);
}

 

