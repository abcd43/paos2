//Assignment no 3
//sstf 

#include<stdio.h>
#include<stdlib.h>

int main()
{
 int req[20],cpos,i,n,headmove=0,index,count=0,min,d;
 printf("Enter the number of requests\n");
 scanf("%d",&n);
 printf("Enter the sequence of requests\n");
 for(i=0;i<n;i++)
 scanf("%d",&req[i]);
 printf("Enter initial head position\n");
 scanf("%d",&cpos);
 
 //loop will execute until all process is completed
 while(count!=n)
 {
 int min=1000,d,intex;
 for(i=0;i<n;i++)
   {
     d=abs(req[i]-cpos);
     if(min>d)
      {
		min=d;
		index=i;
	   }
  }
  headmove=headmove+min;
  cpos=req[index];
  
  //1000 is for max
  //you can use any number
    
    req[index]=1000;
    count++;
 }//while
 
 printf("Total head movements is %d",headmove);
 return 0;
}    
