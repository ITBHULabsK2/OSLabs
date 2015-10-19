#include<iostream>
#include<math.h>
#include<graphics.h>

int q[100],n,head;
void fcfs();
void sstf();
void scan();
void cscan();
void look();
void clook();
int main()

{       
        FILE *f;
        int choice;
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"c:\\tc\\bgi");
         f=fopen("disk_shedueling_sample.in","r");
     
	fscanf(f,"%d",&choice);
        //enter header  
        fscanf(f,"%d",&head);
        //enter num of request
        fscanf(f,"%d",&n);
        for(int i=1;i<=n;i++)
        fscanf(f,"%d",&q[i]);
        fclose(f);
        if(choice==1)
          fcfs();

        if(choice==2)
          sstf();
 
        if(choice==3)
          scan(); 

        if(choice==4)
         cscan();
      if(choice==5)
         look();

         if(choice==6)
         clook();
        getch();
        return 0;
}

void fcfs()
{
      int x1,y1,x2,y2;
      x1=head;
      y1=30;
      for(int j=1;j<=n;j++)
      {
        x2=q[j];
        y2=y1+30;
        line(x1,y1,x2,y2);
        x1=x2;
        y1=y2;
       }
}
    
void sstf()
{
   int temp,x1,y1,x2,y2;
   for(int j=1;j<=n-1;j++)
     {
          for(int i=j+1;i<=n;i++) 
          if(abs(q[j]-head)>abs(q[i]-head))
          {
             temp=q[j];
             q[j]=q[i];
             q[i]=temp;
           }
       }
     x1=head;
      y1=10;
      for(int j=1;j<=n;j++)
      {
        x2=q[j];
        y2=y1+10;
        line(x1,y1,x2,y2);
        x1=x2;
        y1=y2;
       }
} 

void scan()
{
     int m=1,l=1,temp,x1,y1,x2,y2,neg[10],pos[10];
   for(int j=1;j<=n;j++)
    {
       if(q[j]-head<0)
        {
              neg[m]=q[j];
              m++;
         }
        else{
           pos[l]=q[j];
           l++;
          }
      }

 
    for(int j=1;j<=m-2;j++)
     {
          for(int i=j+1;i<m;i++) 
          if(abs(neg[j]-head)>abs(neg[i]-head))
          {
             temp=neg[j];
             neg[j]=neg[i];
             neg[i]=temp;
           }
       }

    for(int j=1;j<=l-2;j++)
     {
          for(int i=j+1;i<l;i++) 
          if((pos[j]-head)>(pos[i]-head))
          {
             temp=pos[j];
             pos[j]=pos[i];
             pos[i]=temp;
           }
       }


       x1=head;
      y1=10;
      for(int j=1;j<m;j++)
      {
        x2=neg[j];
        y2=y1+10;
        line(x1,y1,x2,y2);
        x1=x2;
        y1=y2;
       }
     
      line(x1,y1,0,y1+10);
      x1=0;
      y1=y1+10;
  for(int j=1;j<l;j++)
      {
        x2=pos[j];
        y2=y1+10;
      
        line(x1,y1,x2,y2);
        x1=x2;
        y1=y2;
       }
      
   
     
}  


void cscan()
{
   int m=1,l=1,temp,x1,y1,x2,y2,neg[10],pos[10];
   for(int j=1;j<=n;j++)
    {
       if(q[j]-head<0)
        {
              neg[m]=q[j];
              m++;
         }
        else{
           pos[l]=q[j];
           l++;
          }
      }

 
    for(int j=1;j<=m-2;j++)
     {
          for(int i=j+1;i<m;i++) 
          if((neg[j]-head)>(neg[i]-head))
          {
             temp=neg[j];
             neg[j]=neg[i];
             neg[i]=temp;
           }
       }

    for(int j=1;j<=l-2;j++)
     {
          for(int i=j+1;i<l;i++) 
          if((pos[j]-head)>(pos[i]-head))
          {
             temp=pos[j];
             pos[j]=pos[i];
             pos[i]=temp;
           }
       }

  x1=head;
      y1=10;

for(int j=1;j<l;j++)
      {
        x2=pos[j];
        y2=y1+10;
      
        line(x1,y1,x2,y2);
        x1=x2;
        y1=y2;
       }

line(x1,y1,200,y1+10);
line(200,y1+10,0,y1+20);
x1=0;
y1=y1+20;
       for(int j=1;j<m;j++)
      {
        x2=neg[j];
        y2=y1+10;
        line(x1,y1,x2,y2);
        x1=x2;
        y1=y2;
       }
     

 
}      






void look()
{
     int m=1,l=1,temp,x1,y1,x2,y2,neg[10],pos[10];
   for(int j=1;j<=n;j++)
    {
       if(q[j]-head<0)
        {
              neg[m]=q[j];
              m++;
         }
        else{
           pos[l]=q[j];
           l++;
          }
      }

 
    for(int j=1;j<=m-2;j++)
     {
          for(int i=j+1;i<m;i++) 
          if(abs(neg[j]-head)>abs(neg[i]-head))
          {
             temp=neg[j];
             neg[j]=neg[i];
             neg[i]=temp;
           }
       }

    for(int j=1;j<=l-2;j++)
     {
          for(int i=j+1;i<l;i++) 
          if((pos[j]-head)>(pos[i]-head))
          {
             temp=pos[j];
             pos[j]=pos[i];
             pos[i]=temp;
           }
       }


       x1=head;
      y1=10;
      for(int j=1;j<m;j++)
      {
        x2=neg[j];
        y2=y1+10;
        line(x1,y1,x2,y2);
        x1=x2;
        y1=y2;
       }
     
      //line(x1,y1,0,y1+10);
      
  for(int j=1;j<l;j++)
      {
        x2=pos[j];
        y2=y1+10;
      
        line(x1,y1,x2,y2);
        x1=x2;
        y1=y2;
       }
      
   
     
}  



void clook()
{
   int m=1,l=1,temp,x1,y1,x2,y2,neg[10],pos[10];
   for(int j=1;j<=n;j++)
    {
       if(q[j]-head<0)
        {
              neg[m]=q[j];
              m++;
         }
        else{
           pos[l]=q[j];
           l++;
          }
      }

 
    for(int j=1;j<=m-2;j++)
     {
          for(int i=j+1;i<m;i++) 
          if((neg[j]-head)>(neg[i]-head))
          {
             temp=neg[j];
             neg[j]=neg[i];
             neg[i]=temp;
           }
       }

    for(int j=1;j<=l-2;j++)
     {
          for(int i=j+1;i<l;i++) 
          if((pos[j]-head)>(pos[i]-head))
          {
             temp=pos[j];
             pos[j]=pos[i];
             pos[i]=temp;
           }
       }

  x1=head;
      y1=10;

for(int j=1;j<l;j++)
      {
        x2=pos[j];
        y2=y1+10;
      
        line(x1,y1,x2,y2);
        x1=x2;
        y1=y2;
       }

//line(x1,y1,200,y1+10);
//line(200,y1+10,0,y1+20);
//x1=0;
//y1=y1+20;
       for(int j=1;j<m;j++)
      {
        x2=neg[j];
        y2=y1+10;
        line(x1,y1,x2,y2);
        x1=x2;
        y1=y2;
       }
     

 
}      








































































