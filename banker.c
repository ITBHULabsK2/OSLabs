#include<stdio.h>
#include <string.h>

#define MAX_ 100
int available[MAX_], max[MAX_][MAX_], allocation[MAX_][MAX_], need[MAX_][MAX_];
int work[MAX_], finish[MAX_];
int nop, nor;
int req_p, req_r[MAX_];

void init();
int check_safety();
int safety_final_step();
void safe_seq(int a[]);
void restore();

int main()
{
	int safe=0;
	system("clear");
	printf("Welcome to the BANKER'S ALGORITHM\n");
	printf("Enter initial information");
	init();
	safe=check_safety();
	return 0;
}

void init()
{
	int i,j;
	printf("\nenter total no. of processes ->\t");
	scanf("%d",&nop);
	printf("\nenter total type of resources ->\t");
	scanf("%d",&nor);
	printf("\n enter the present allocated resources ... give process wise allocation separated by a newline\n");
	for(i=0;i<nop;i++)
	{
		printf("\nProcess%d ->\t",i);
		for(j=0;j<nor;j++)
			scanf("%d",&allocation[i][j]);
	}
	printf("\n enter the present maximum resources required... give process wise allocation separated by a newline\n");
	for(i=0;i<nop;i++)
	{
		printf("\nProcess%d ->\t",i);
		for(j=0;j<nor;j++)
			scanf("%d",&max[i][j]);
	}
	printf("\nenter the currently available resources\n");
	for(j=0;j<nor;j++)
		scanf("%d",&available[j]);
	
	//calculating the need matrix
	for(i=0;i<nop;i++)
		for(j=0;j<nor;j++)
		{
			need[i][j]=available[j] - allocation[i][j];
			printf("%d  ",need[i][j]);
		}
		printf("\n");
	return;		
}

int check_safety()
{
	int i=0,j;
	int safe;
	int flag0=0,flag1=0, flag2=1;
	int safe_str[6];
	printf("\nwork init");
	while(i<nor)
	{
		work[i]=available[i];
		printf("%d ",work[i]);
		i++;
	}
	printf("\nfinish");
	for(i=0;i<nop;i++)
		{
			finish[i]=0;
			printf("%d  ",finish[i]);
		}
	printf("\n");
	for(i=0;i<nop;i++)
	{
		flag0=0; flag2=1;
		printf("\n");
		if(finish[i]==0)
		{
			flag0=1;
			for(j=0;j<nor;j++)
			{
				if(need[i][j]<=work[j])
					continue;
				else
					flag2=0;
			}
			if(flag2==0)
				flag1++;
		}
		else
			flag1++;
		
		if(flag0==1 && flag2==1)
			{
				for(j=0;j<nor;j++)
					work[j]+=allocation[i][j];
				finish[i]=1;
			}
		//error check point1
		printf("\nwork%d",i);
		for(j=0;j<nor;j++)
			printf("%d  ",work[j]);
	}
		
	//if(flag1==nop-1)
	safe=safety_final_step();
	/*else
	{
		for(i=0;i<nop;i++)
		{
			}
		safe=safety_final_step();	
	}*/
	if(safe==1)
	{
		safe_seq(safe_str);
		printf("\nThe system is in safe state with the sequence \n");
		for(i=0;i<nop;i++)
			printf("%d\t",safe_str[i]);
		return 1;
	}
	else
	{
		printf("\nERROR....sytem state becomes unsafe..... \n");
		restore();
		return 0;
	}
}

int safety_final_step()
{
	int i=0,flag3=0;
	for(i=0;i<nop;i++)
		if(finish[i]==0)
			flag3++;
	if(flag3!=0)
		return 0;
	else
		return 1;
}

void safe_seq(int safe_str[])
{
	int i=0,j,count=0,flag4;
	int done=0;
	int done_nop[nop];
	char seq[6];
	
	while(done!=nop)
	{
		flag4=0;
		if(i==nop)  //another way to deal with the process sequence :)
			i=0;
		
		if(done_nop[i]==1)
		{
			i++;
			continue;
		}
		
		for(j=0;j<nor;j++)
		{
			if(need[i][j]>available[j])
				flag4=1;
		}
		if(flag4==0)
		{	safe_str[count++]=i;
			done_nop[i]=1;
			 done++;
		 }
		 
		 i++;
		 //if(done==nop)
		 //	break;
	}
	//strcpy(safe_str,seq);
	return ;
}

void restore()
{
}

