#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<string.h>
#include<sys/times.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>

int main()
{
	pid_t pid;
	pid=fork();
	if(pid==0)
	{
		execlp("gcc","gcc","shell.c","-o","shell",NULL);
		puts("\n\nshell launch failed\n");
		printf("\nchild process still continuing\n");
	}
	else if(pid>0)
	{
		wait(NULL);
		system("gnome-terminal --hide-menubar -t MyShell_v1.0 -x ./shell");
		exit(0);
	}
	else{
			puts("fork failed");
			exit(0);
		}
		
	return 0;
}

