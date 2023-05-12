//Assignment no 3
//fcfs No of head movements

#include<stdio.h>
#include<stdlib.h>
void main()
{
int req[20],cpos,i,n,j,index,dir,temp,headmove=0,size=200;
printf("\nEnter number of requests");
scanf("%d",&n);
printf("\n Enter request ");
for(i=0;i<n;i++)
scanf("%d",&req[i]);
printf("\nEnter curreent position");
scanf("%d",&cpos);
for(i=0;i<n;i++)
  {
   headmove=headmove+abs(cpos-req[i]);
   cpos=req[i];
   }
   printf("\nNumber of head movements=%d",headmove);
}   
