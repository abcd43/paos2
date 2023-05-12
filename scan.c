//Assignment 3
//SCAN

#include<stdio.h>
#include<stdlib.h>

int main()
{
 int req[20],cpos,i,n,headmove=0,index,dir,j,temp,size=20;
 printf("Enter the number of requests\n");
 scanf("%d",&n);
 printf("Enter the sequence of requests\n");
 for(i=0;i<n;i++)
 scanf("%d",&req[i]);
 printf("Enter initial head position\n");
 scanf("%d",&cpos);
 printf("Enter head movement direction 0 for left and 1 for right");
 scanf("%d",&dir);
 req[n]=cpos;  //add cpos in array at last location
 n=n+1;  //number of requests incremented by 1 
 
 //sort request array
 
 for(i=0; i<n; i++)
 {
   for(j=i+1; j<n; j++)
    { 
      if(req[i]>req[j])
      {
        temp=req[i];
        req[i]=req[j];
        req[j]=temp;
       }
    }
 }
 //find index of cpos
 for(i=0; i<n; i++)
 {
 	if(req[i]==cpos)
 	{
 	  index=i;
 	  break;
 	 }
 }
if(dir==0)
{
 for(i=index-1; i>=0; i--)
 {
   headmove=headmove+abs(cpos-req[i]);
   cpos=req[i];
  }
 headmove=headmove+(cpos-0);
 cpos=0;
 for(i=index+1; i<n; i++)
 {
   headmove=headmove+abs(cpos-req[i]);
   cpos=req[i];
  }
}

else if(dir==1)
{
  for(i=index+1; i<n; i++)
   {
    headmove=headmove+abs(cpos-req[i]);
    cpos=req[i];
  }
 headmove=headmove+(cpos-(size-1));
 cpos=(size-1);
 for(i=index-1; i>=0; i--)
 {
   headmove=headmove+abs(cpos-req[i]);
   cpos=req[i];
   }
  }
printf("\nNumber of head movements=%d",headmove);
}  
   
       
    	 
 	         
 
