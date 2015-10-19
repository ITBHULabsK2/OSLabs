#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<sys/times.h>
#include<unistd.h>
#include<iostream>
using namespace std;

int main(int argc,char *argv[])
{
 int n,i;
 system("g++ fcfs.cpp -o fcfs -lgraph");
 system("g++ sstf.cpp -o sstf -lgraph");
 system("g++ scan.cpp -o scan -lgraph");
 system("g++ C-scan.cpp -o C-scan -lgraph");
 system("g++ C-LOOK.cpp -o C-LOOK -lgraph");
 l:
 printf("\n\n");
 system("clear");
 for(i=0;i<70;i++)
 {
  cout<<"*";
 }
 printf("\n");
 printf("              Disk-Schedule Menu\n");
 for(i=0;i<70;i++)
 {
  cout<<"*";
 }
 cout<<endl;
 printf("    1. First Come First Serve\n");
 printf("    2. Shortest Seek Time First\n");
 printf("    3. SCAN\n");
 printf("    4. C-SCAN\n");
 printf("    5. C-LOOK\n");
 printf("    6. Exit\n");
 printf("choice ->\t");
 scanf("%d",&n);
 switch(n)
 {
  case 1:
   system("./fcfs");
   break;
  case 2:
   system("./sstf");
   break;
  case 3:
   system("./scan");
   break;
  case 4:
   system("./C-scan");
   break;
  case 5:
   system("./C-LOOK");
   break;
  case 6:
   goto end;
   break;
 }
 goto l;
 end:
 system("clear");
}
