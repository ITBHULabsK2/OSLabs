#include<pthread.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int m,n,k,i,j;
int A[150][150],B[150][150],c[150][150],rc[150];
void *runner(void *h);

int main(void)
{
 	pthread_t tid[100][100];
	pthread_attr_t attr;

	pthread_attr_init(&attr);


	scanf("%d %d %d",&m,&k,&n);

	for(i=1;i<=m;i++)
	{  
 		for(j=1;j<=k;j++)
     		{
         		scanf("%d",&A[i][j]);
     		}
 	}



	for(i=1;i<=k;i++)
	{  
 		for(j=1;j<=n;j++)
     		{
         		scanf("%d",&B[i][j]);
     		}
 	}

	for(i=1;i<=m;i++)
	{
		for(j=1;j<=n;j++)
		{
   			rc[0]=i;
   			rc[1]=j;
  			pthread_create(&tid[i][j],&attr,runner,rc);
		}
	}


for(i=1;i<=m;i++)
  for(j=1;j<=n;j++)
    pthread_join(tid[i][j],NULL);


for(i=1;i<=m;i++)
{
  printf("\n");
  for(j=1;j<=n;j++)
  printf("%d ",c[i][j]);
}


return 0;
}


void *runner(void *h)
{
  int r,*z,tor=0;
  z=(int *) h;
 i=z[0];
 j=z[1];
//printf("%d %d\n",i,j);
for(r=1;r<=k;r++)
{
//printf("%d\n",B[2][2]);
 tor+=A[i][r]*B[r][j]; 
//printf("%d\n",tor);
 }
c[i][j]=tor;

return(NULL);
}

