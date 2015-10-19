#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<string.h>
#include<sys/times.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>

long clk_tck;
struct tms buff1,buff2;
clock_t start,end;
	
int main()
{
 	pid_t child,c;
 	int cstatus,i,cpp_flag, pro_choice;
 	char prog_name[20],output[20];
	char name[100], initial[100]="gnome-terminal -e --command=time ";
	
	puts("enter 1-> graphics 2-> normal c/cpp 3-> binary");
	scanf("%d",&pro_choice);
	if(pro_choice==3)
	{
		puts("enter the name of the binary");
		scanf("%s",name);
		strcat(initial,name);
		printf("%s\n",initial);
		//system(initial);
		sys_exec(initial);
	}
	else
	{
	puts("enter the program name:");
	scanf("%s",prog_name);

	if(strstr(prog_name,"cpp")!=NULL)
		cpp_flag=1;
	else
		cpp_flag=0;

//here the parent process will fork a child process
	child=fork();
	printf("\ncp #0 \n");
	if(child==(pid_t)-1)
		//parent fork failed
		puts("cant fork child process");

	else if(child==0)
		{//child thread of execution
			printf("\ncp #1 \n");
  			if(pro_choice==1)
  			{
  				if(cpp_flag==1)
  					execlp("g++","g++",prog_name,"-lgraph","-o","output",NULL);
  				else
  					execlp("gcc","gcc",prog_name,"-lgraph","-o","output",NULL);
  				
  			}
  			else	if(pro_choice==2)
  			{if(cpp_flag==1)
  					execlp("g++","g++",prog_name,"-o","output",NULL);
  				else
  					execlp("gcc","gcc",prog_name,"-o","output",NULL);
  				printf("\ncp #1.1 \n");
  			}
  			puts("excelp failed.....");
		}

	else 
		{
			printf("\ncp #2 \n");
			c=wait(&cstatus);
			//wait(NULL);
			printf("\npid c = %d\ncstatus = %d \n", c);
			sys_exec("gnome-terminal --hide-menubar -x time ./output");
		}
	}
	return 0;
	
}

 void sys_exec(char command[])
 {
 			start=times(&buff1);
			system("echo -e \"\033[1;33m\"");
			//system("gnome-terminal --command=");
			system(command);
			system("echo -e \"\033[0m\"");
			end=times(&buff2);
			clk_tck= sysconf(_SC_CLK_TCK);
			printf("\n real time elasped %-4.3lf",(end-start)/(double)clk_tck);
			double user_time=(buff2.tms_cutime-buff1.tms_utime)/(double)clk_tck;
			double sys_time=(buff2.tms_cstime-buff1.tms_stime)/(double)clk_tck;
			printf("\n user time elasped %-4.3lf\n system time elapsed %-4.3lf\n\n",user_time,sys_time);
			
			return;

 }
