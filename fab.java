class fab implements Runnable
{
 public int i,y,k;

public static int[] fib = new int[100];

  public  int fabo(int j)
{

  if(j==0||j==1)
return j;
 else
  return(fib[j-1]+fib[j-2]);
}

public fab(int k)
{
 this.k=k;
}
public void run()
{

   fib[k]=fabo(k);
}

  public static void main(String args[])
 {
   int n;
   n=Integer.parseInt(args[0]);
 
   for(int i=0;i<n;i++)
     {

           Thread t=new Thread(new fab(i));
            t.start();
try{
t.join();
System.out.println(fib[i]);
}
catch(Exception e)
{}

}

}
}
