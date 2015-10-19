#include<pthread.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int fab[100];
void *runner(void *h);
int fabo(int g);

int main(void)
{
  pthread_t tid[100];
 pthread_attr_t attr;
 int i,n;



printf("enter the value of n");
scanf("%d",&n);

pthread_attr_init(&attr);

//printf("enter value of n\n");






for(i=0;i<n;i++)
{
   pthread_create(&tid[i],&attr,runner,&i);
}

for(i=0;i<n;i++)
{
   pthread_join(tid[i],NULL);
}
for(i=0;i<n;i++)
{
   printf("%d ",fab[i]);
}


  


return 0;
}


void *runner(void *h)
{
int p=*(int *)h;
//printf("%d",fabo(p));
fab[p]=fabo(p);
}
int fabo(int j)
{
  if(j==0||j==1)
return j;
 else
 return(fab[j-1]+fab[j-2]);
}

