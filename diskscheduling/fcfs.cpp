#include<stdio.h>
#include<graphics.h>
#include<math.h>
void input(int arr[],int n,FILE *fp);
void sort(int arr[],int n);
int scale(int x);
int xmax;
char s[20];
int sum=0;
int main(int argc,char *argv[])
{
  int gd=DETECT,gm,yincr;
  initgraph(&gd,&gm,NULL);
  //outtextxy(100,100,6);
  FILE *fp;
  fp=fopen("input","r");
  setcolor(GREEN);
  int n,arr[51],start,i,x1,y1,x2,y2;
  //printf("Enter no of requests\n");
  fscanf(fp,"%d",&n);
  fscanf(fp,"%d",&xmax);
  fscanf(fp,"%d",&start);
  yincr=400/n;
  input(arr,n,fp);
  //printf("Enter the initial point of the head\n");
 
 x1=start;
 y1=5;
 for(i=0;i<n;i++)
 {
  x2=arr[i];
  y2=y1+yincr;
  line(scale(3*x1),y1,scale(3*x2),y2);
  sprintf(s,"%d",x2);
  outtextxy(scale(3*x2),y2,s);
  sprintf(s,"st=%du",abs(x2-x1));
  sum+=abs(x2-x1);
  outtextxy(scale(3*x2)+30,y2,s);
  x1=x2;
  y1=y2;
 }
 fclose(fp);
 printf("total seek time=%du\n",sum);
 printf("average seek time=%f\n",(float)sum/n);
 printf("total no of movements=%d\n",sum);
 getch();
 
}
void input(int arr[],int n,FILE *fp)
{
 int i;
 for(i=0;i<n;i++)
 {
  fscanf(fp,"%d",&arr[i]);
 }
 //sort(arr,n);
}
void sort(int arr[],int n)
{
 int i=0,j,temp;
 for(i=0;i<n-1;i++)
  for(j=i+1;j<n;j++)
    {
     if(arr[i]>arr[j])
     {
	 temp=arr[j];
	 arr[j]=arr[i];
	 arr[i]=temp;
     }
    }
}
int scale(int x)
{
 //printf("%d  ",x);
 float te;
 te=((float)x/xmax)*205;
 //printf("%d ",te);
 return((int)te);//return((x/xmax)*210);
}
