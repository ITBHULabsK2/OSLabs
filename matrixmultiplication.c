//#include<pthread.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int m,n,k,i,j;
int A[100][100],B[100][100],c[100][100],rc[10];
int mult(int *h);

int main(void)
{
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
  			mult(rc);
		}
	}

	for(i=1;i<=m;i++)
	{
  		printf("\n");
  		for(j=1;j<=n;j++)
  			printf("%d ",c[i][j]);
	}

return 0;
}

int mult(int *h)
{
	int r,*z,tor=0;
	z=(int *)h;
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

