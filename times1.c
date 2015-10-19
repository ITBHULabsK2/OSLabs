#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<string.h>
#include<sys/times.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>

extern long times();

long clk_tck;

int main()
{
	pid_t c;
	int i,cstatus;
	struct tms pb1,pb2;
	long pt1,pt2;
	
	clk_tck=sysconf(_SC_CLK_TCK);
	
	pt1 = times(&pb1);
	for(i=0; i<100; i++)
		if(fork() == 0)
			child(i);
		else
			c=wait(&cstatus);
			
	for(i=0; i<10; i++)
		wait((int *) 0);
		
	pt2 = times(&pb2);
	printf("parent \t real %lf \t user %lf \t sys %lf \t cuser %lf \t csys %lf \n",
			(pt2 - pt1)/(double)clk_tck, (pb2.tms_cutime - pb1.tms_utime)/(double)clk_tck, (pb2.tms_cstime - pb1.tms_stime)/(double)clk_tck,(pb2.tms_cutime - pb1.tms_cutime)/(double)clk_tck, (pb2.tms_cstime - pb1.tms_cstime)/(double)clk_tck);
			
	return 0;
}

child(int n)
{
	int i,j=0;
	struct tms cb1,cb2;
	long t1,t2;
	
	t1 = times(&cb1);
	for(i=0; i<100000; i++)
		j=j+2;
		;
	
	printf("\n%d\n",j);
	t2 = times(&cb2);
	printf("child %d : \t real %lf \t user %lf \t sys %lf \n", n, (t2 - t1)/(double)clk_tck,
		    (cb2.tms_cutime - cb1.tms_utime)/(double)clk_tck, (cb2.tms_cstime - cb1.tms_stime)/(double)clk_tck);
	
	_exit(0);

}	
