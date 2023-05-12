//Assignment 2//
//slot 3
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define SIZE 100
#define NEWNODE (struct direntry*)malloc(sizeof(struct direntry))

struct direntry
{
char fname[14];
int ibno,blist[20],k;
struct direntry *next;
}*dirst=NULL, *dirend=NULL;

 int bitvector[SIZE];
 
void main()
{
 int ch1=0,i,j,n,flag;
 char fname[14];
 int rand();
 struct direntry *t1, *t2;
 for(i=0; i<SIZE;i++)
    bitvector[i]=rand()%2;   
 
 while(ch1!=5)
 {
   printf("\n\n1.Print Bit Vector");
   printf("\n\n2.Create File");
   printf("\n\n3.Print Directory");    
   printf("\n\n4.Delete File");
   printf("\n\n5.Exit");
    printf("\nEnter Your Choice :");
    scanf("%d",&ch1);
    
switch(ch1)
{ 

case 1:
 	for(i=0; i<SIZE; i++)
 	  printf("%4d",bitvector[i]);
          break;
   
  case 2:
          if(dirst==NULL)
          dirst=dirend=NEWNODE;
             else
              {
                dirend->next=NEWNODE;
                dirend=dirend->next;
               }
           dirend->next=NULL;
           printf("\n Enter A Filename :");
           scanf("%s",dirend->fname);
           printf("\nEnter the blocks to allocate :");
           scanf("%d",&n);
           dirend->k=n;
           i=j=flag=0;
           while(n>0)
            {
            	if(bitvector[i]==1)//found ith block free
            	 { 
            	 if(flag==0)
            	 {
            	 	dirend->ibno=i;
            	 	flag=1;
            	} 	
       else//allocate data block
       {
          dirend->blist[j++]=i;  	//store block i in blist[j]
          n--;
        }
      bitvector[i]=0;//mark ith block allocate    
       
        if(n==0)
        
     break;
       }//if
       i++;
     }//while
     
     break;
     
case 3:
	   printf("\nDirectory");
	   printf("\n---------------------------");
       printf("\nFilename   IndexBlockNo     BlockList");       
       printf("\n--------------------------------------------------------"); 
       for(t1=dirst; t1!=NULL; t1=t1->next)
          {
          	printf("\n%-10s %6d ",t1->fname, t1->ibno);
          	for(j=0; j<t1->k; j++)
          	printf("%6d",t1->blist[j]);
        }  	
       printf("\n---------------------------------------------------");
       break;
      
 case 4:
        printf("\nEnter a Filename :");
        scanf("%s",fname);
        t1=dirst;
        while(t1!=NULL)
        	{
        		if(strcmp(t1->fname,fname)==0)
			 break;
			   t2=t1;
			   t1=t1->next;
        }  
    if(t1!=NULL)//file found
     {
     for(j=0; j<t1->k; j++)//mark data block as free
          bitvector[t1->blist[j]]=1;
     	  bitvector[t1->ibno]=1; 
    if(t1==dirst)
     dirst=dirst->next;
    else
      t2->next=t1->next;
          if(dirst==NULL)
               dirend=NULL;
               
               free(t1);
       }
         else
         printf("\nFile not found...\n");
         break;
     }
  }
}

  /*1.Print Bit Vector

2.Create File

3.Print Directory

4.Delete File

5.Exit
Enter Your Choice :1
   1   0   1   1   1   1   0   0   1   1   0   1   0   1   1   0   0   0   0   0   1   0   1   1   0   0   0   1   1   1   1   0   0   0   1   1   1   0   1   0   1   1   1   1   0   1   0   0   1   0   1   0   1   0   0   1   0   0   0   1   1   1   0   1   0   1   0   1   1   1   0   1   0   1   0   1   0   0   1   0   1   0   0   0   0   0   1   1   0   1   0   0   0   0   1   0   0   0   0   1

1.Print Bit Vector

2.Create File

3.Print Directory

4.Delete File

5.Exit
Enter Your Choice :2

 Enter A Filename :file.c

Enter the blocks to allocate :6


1.Print Bit Vector

2.Create File

3.Print Directory

4.Delete File

5.Exit
Enter Your Choice :1
   0   0   0   0   0   0   0   0   0   0   0   1   0   1   1   0   0   0   0   0   1   0   1   1   0   0   0   1   1   1   1   0   0   0   1   1   1   0   1   0   1   1   1   1   0   1   0   0   1   0   1   0   1   0   0   1   0   0   0   1   1   1   0   1   0   1   0   1   1   1   0   1   0   1   0   1   0   0   1   0   1   0   0   0   0   0   1   1   0   1   0   0   0   0   1   0   0   0   0   1

1.Print Bit Vector

2.Create File

3.Print Directory

4.Delete File

5.Exit
Enter Your Choice :3

Directory
---------------------------
Filename   IndexBlockNo     BlockList
--------------------------------------------------------
file.c          0      2     3     4     5     8     9
---------------------------------------------------

1.Print Bit Vector

2.Create File

3.Print Directory

4.Delete File

5.Exit
Enter Your Choice :4

Enter a Filename :file.c


1.Print Bit Vector

2.Create File

3.Print Directory

4.Delete File

5.Exit
Enter Your Choice :1
   1   0   1   1   1   1   0   0   1   1   0   1   0   1   1   0   0   0   0   0   1   0   1   1   0   0   0   1   1   1   1   0   0   0   1   1   1   0   1   0   1   1   1   1   0   1   0   0   1   0   1   0   1   0   0   1   0   0   0   1   1   1   0   1   0   1   0   1   1   1   0   1   0   1   0   1   0   0   1   0   1   0   0   0   0   0   1   1   0   1   0   0   0   0   1   0   0   0   0   1

1.Print Bit Vector

2.Create File

3.Print Directory

4.Delete File

5.Exit
Enter Your Choice :5

*/       
     	                     	

