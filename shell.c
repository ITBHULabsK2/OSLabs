#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <sys/param.h>
#include <sys/wait.h>
#include <signal.h>
#define MAX_HIST 10
#define MAX_BG 20

char history[MAX_HIST][100];
int top=-1;
char path[MAXPATHLEN];
char shell_name[MAXPATHLEN+10];

char pros_name[MAX_BG][100];
pid_t active_pros[MAX_BG];
pid_t fg_pros;
pid_t bg_pros;
void printJobs();
int findSpot();

void set_shell_name();
void arg_engine(char input[],char *j[], int *);
void cpy2hist(char in[]);
void show_history();

int main()
{
	//char *shell_name;
	char *arg[30];
	pid_t pid;
	char input[256];
	int background, free_pos;
	int count=0;
	
	system("echo  \"\033[1;33m\"");
	set_shell_name();
	
	while(1)
	{
		background=0;
		printf( "%s",shell_name );

		arg_engine(input, arg, &background);
		
		if(arg[0]==NULL)
			continue;
		
		if(strcmp(arg[0],"history")==0)
		{
			show_history();
			continue;
		}
				
		if(strcmp(arg[0],"exit")==0)
		{
			for(count=0;count<MAX_BG;count++)
				if(active_pros[count]!=0)
					kill(active_pros, SIGTERM);
			
			exit(0);
		}
		
		if(strcmp(arg[0],"cd")==0)
		{
			if(chdir(arg[1])==0)
				set_shell_name();
			else
				printf("\nError in command execution\n");
			
			continue;
		}
		
		if(strcmp(arg[0],"show_jobs")==0)
		{
			printJobs();
			continue;
		}
		
		if(strcmp(arg[0],"fg")==0)
		{
			bg_pros=atoi(arg[1]);
			printf("\nBringing process %d into foreground\n",bg_pros);
			kill(bg_pros,SIGCONT);
			fg_pros=bg_pros;
			
			for(count=0;count<MAX_BG;count++)
				if(active_pros[count]==bg_pros)
					{
						active_pros[count]=0;
						pros_name[count][0]='\0';
					}
			waitpid(bg_pros,NULL,0);
			continue;
		}
		
		pid = fork();
		if( pid==0 )
		{
			execvp( arg[0], arg );
			printf( "command failed\n" );
		}
		else
		{
			if(background==0)
			{
				fg_pros=pid;
				waitpid(pid, NULL, 0 );
			}
			else
			{
				free_pos=findSpot();
				if(free_pos!=-1)
					{
						active_pros[free_pos]=pid;
						strcpy(pros_name[free_pos],arg[0]);
					}
				else
					{
						active_pros[MAX_BG-1]=pid;
						strcpy(pros_name[MAX_BG-1],arg[0]);
					}
					
			}
			continue;
		}
	}
	return 0;
}

void arg_engine(char input[],char *arg[], int *background)
{
	int i,len,begin=-1;
	int count=0;
	gets(input);
	len = strlen( input );
	//printf("\n%s\nlen=%d\n",input,len);
	
	/*if (strcmp(input,"?*")==0)
		exit(0);	// ^d was entered, end of user command stream 
	if (len < 0) 
	{
		printf("error reading the command");
		exit(-1);	// terminate with error code of -1
	}*/

	cpy2hist(input);
	
	for(i=0;i<len+1;i++)
	{
		switch(input[i])
		{
			case ' ':
			case '\t':
				if(begin!=-1)
					{
						arg[count] = &input[begin];
						count++;
					}
				begin=-1;
				input[i]='\0';
				break;	
				
			case '\0':
				if(begin!=-1)
					{
						arg[count] = &input[begin];
						count++;
					}
				input[i]='\0';
				arg[count]=NULL;
				break;
				
			default:
				if(input[i]=='&')
					{
						*background=1;
						input[i]='\0';
					}
				else	if(begin==-1)
						begin = i;
										
		}
	}
	
	arg[count]=NULL;
	return;
}

void set_shell_name()
{
	//free(shell);
	//shell_name
	char shell[MAXPATHLEN+10]={'\0'};
	if(getcwd(path,MAXPATHLEN)==NULL)
		printf("\nError \n");
	else
		{
			//printf("\nCurrent Working Directory :\t%s\n",path);
			strcat(strcat(strcat(shell,"shell :"),path),"$");
			//shell_name[0]='\0';
			strcpy(shell_name,shell);
			//free (shell);
			//printf("\nNew Shell Name :\t%s\n", shell);
		}
	return ;
}

void cpy2hist(char input[])
{
	int i;
	if(strcmp(input,"")==0)
		return;
		
	if(top==MAX_HIST)
	{
		for(i=0;i<=top;i++)
			strcpy(history[i], history[i+1]);
		
		strcpy(history[top], input);
		return;
	}
	else
		top++;
		strcpy(history[top], input);
		return;
	
}

void show_history()
{
	int i=top;
//	printf("hello");
	while(i>=0)
		{
		printf("%d -> %s\n",i+1, history[i]);
		i--;
		}
	//printf("\n");
	return;
}

void printJobs()
{
	int i=0;
	while(i<MAX_BG)
	{
		if(active_pros[i]!=0)
			printf("\n%d -> %s\t%d",i+1,pros_name[i],active_pros[i]);
		
		i++;
	}
	printf("\n");
	return;
}

int findSpot()
{
	int i=0;
	while(i<MAX_BG)
	{
		if(active_pros[i]==0)
			return i;
		i++;
	}
	return -1;
}


