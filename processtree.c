#include <stdio.h>
#include <sys/wait.h>


int main()
{
	//A
	pid_t pid, c;
	int cstatus;
	pid = fork();
	if(pid == 0)
	{
		//B
		pid =fork();
		if(pid == 0)
		{
			//C
			while(1)
			{
				sleep(2);
				printf("\n%d",getpid());
			}
		}
		if(pid>0)
		{
			pid =fork();
			
			if(pid == 0)
			{
				//D
				while(1)
				{
					sleep(2);
					printf("\n%d",getpid());
				}
			}
			//wait(NULL);
			//while(1);
			/*if(pid>0)
			{
				c=wait(&cstatus);
				while(1)
				{
					sleep(2);cout<<"\n"<<getpid();
				}
			}*/
		}
		wait(NULL);
		wait(NULL);
		while(1);
		/*if(pid>0)
		{
			c=wait(&cstatus);
			while(1)
				{
					sleep(2);cout<<"\n"<<getpid();
				}
		}*/	
	}
	else if(pid>0)
	{
		//A
		pid = fork();
		if(pid == 0)
		{	
			//E
			pid =fork();
			if(pid == 0)
			{
				//F
				while(1)
				{
					sleep(2);
					printf("\n%d",getpid());
				}
			}
			if(pid>0)
			{
				//E
				pid =fork();
			
				if(pid == 0)
				{
					//G
					while(1)
					{
						sleep(2);
						printf("\n%d",getpid());
					}
				}
				//if(pid>0)
				//wait(NULL);
				//while(1);
				/*{
					c=wait(&cstatus);
					while(1)
					{
					sleep(2);cout<<"\n"<<getpid();
					}
				}*/
			}	
		}
		wait(NULL);
				
		wait(NULL);
		while(1);
		/*if(pid>0)
		{
			c=wait(&cstatus);
			while(1)
				{
					sleep(2);cout<<"\n"<<getpid();
				}
		}*/
	}
	wait(NULL);
	while(1);
	/*if(pid>0)
	
	{
		c=wait(&cstatus);
		while(1)
				{
					sleep(2);cout<<"\n"<<getpid();
				}
	}*/
}
