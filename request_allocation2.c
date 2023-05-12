//Slot 2
#define true 1
#define false 0
#include<stdlib.h>
#include<stdio.h>
#include<ctype.h>
 int  avail[] = {1,5,2,0} ,work[10] ,req[10];
      int max[][10] = { {0,0,1,2} ,{1,7,5,0},{2,3,5,6} ,{0,6,5,2},{0,6,5,2}};
      int alloc[][10] = { {0,0,1,2} ,{1,0,0,0},{1,3,5,4} ,{0,6,3,2},{0,0,1,4}};
      int safeseq[5] , ssi=-1 ;
      int need[10][10] , finish[10] ;
          int m = 4 , n = 5 , i,j ;
          void  get_allocation_matrix();
         int  safe_state(); 
         void get_alloc_request();
          int need_lte_work(int i);
          void print_safes();
          int req_lte_need(int i);
            int req_lte_avail();
void main()
   {
    get_allocation_matrix();
       if(safe_state())
       {
         printf("\n System is in safe state \n");
         print_safes();
       }
    else{
        printf(" \n system is not in safe state \n ");
     }
     get_alloc_request();
     if(safe_state())
       {
         printf("\n System is in safe state \n");
         print_safes();
       }
    else{
        printf(" \n system is not in safe state \n ");
     }
   }
   
      void get_allocation_matrix()
      {
      // calculate m , n 
     printf("\n Number of Resources of matrix have %d", m);
      printf("\n Number of Processes of matrix have %d", n);
      // calculating available
     printf("\n Number of Available resources are\t ");
          for(j=0;j<m;j++)
          {
            printf("%d \t ",avail[j]) ;
            }
       // calculating max
        printf("\n Number of Maximum need process can have \n ");
        for(i=0;i<n;i++)
          {
                 for (j=0;j<m;j++)
                   {
                     printf("%d\t",max[i][j]);
                    }
                        printf("\n");
           }
         
           // calculating alloc 
             printf("\n Number of Allocation of resources to process are \n ");
        for(i=0;i<n;i++)
          {
                 for (j=0;j<m;j++)
                   {
                     printf("%d\t",alloc[i][j]);
                    }
                        printf("\n");
           } 
      // calculating need 
       printf("\n Number of need of resources process can have \n ");
      for(i=0;i<n;i++)
          {
                 for (j=0;j<m;j++)
                   {
                     need[i][j] = max[i][j] - alloc[i][j] ;
                     printf("%d\t",need[i][j]);
                    }
                        printf("\n");
           }
        }
        
        int  safe_state()
      {
      
          // Step 1 check whether need of matrix is less than or equal to work matrix
           for(j=0;j<m ; j++)
           work[j] = avail[j] ;
           for(i=0;i<n;i++)
           finish[i] = false ;
        printf ("\n check whether process is in safe state \n ");   
           do
           {
           int found=false;
                    for(i=0;i<n;i++)
                    {
                    if( finish[i] == false && need_lte_work(i))
                       {
                          // step 3
                          printf("\n selected process %d ", i);
                          finish[i]=true;
                            for(j=0;j<m;j++)
                                work[j] = work[j] + alloc[i][j] ;
                                  safeseq[++ssi] = i;
                                  found = true ;
                                   break ;
                                   }
                                }
                    if(found == false)  // step 4 bno such a process
                        {
                           for(i=0;i<n;i++)
                              if(finish[i]==false)
                                  return (false);   // unsafe state
                               return (true);
                               }
                    } while (1) ;
                    
                       }  // safe_state 
      
      int need_lte_work(int i)
         {
           for(j=0;j<m;j++)
              {
                 if(need[i][j] > work[j] )
                  return (false);
                  }
              return(true);
           }
           
 void print_safes()
  {
                 printf("\n Safe Sequence  is \n ");          
                     for ( i = 0 ; i < ssi ; i++)
                         printf(" %d\t" , safeseq[i]);
                         printf(" \n ");      
  }  
  
 void get_alloc_request()
  {
     printf(" Enter the process who want to request \n ");
     scanf ("%d", &i);
     printf("Enter Request \n ");
     for(j=0;j<m;j++)
        scanf("%d",&req[j]);
        
      if(!req_lte_need(i))
      {
        printf("request of process is more than need of process \n ");
        exit(0);
      }
      if(!req_lte_avail())
      {
        printf("Request of process is more than available of process \n process %d has to be wait",i);
        exit(0);
      }
     
     for(j=0;j<m;j++) 
     {
      alloc[i][j] -= req[j];
      need[i][j] -= req[j];
      avail[j] -= req[j] ;
      }
  }
  
  int req_lte_need(int i)
      {
         for(j=0;j<n;j++)
            {
               if( req[j] > need[i][j])
                  return 0;
               }
             return 1;
      }
   
    int req_lte_avail()
      {
         for(j=0;j<n;j++)
            {
               if( req[j] > avail[j])
                  return 0;
               }
             return 1;
      }    
      
      /*
      dell9@dell9-OptiPlex-3060:~/Desktop/Nisha/OS/assignment 1/set b$ gcc request_safty.c
dell9@dell9-OptiPlex-3060:~/Desktop/Nisha/OS/assignment 1/set b$ ./a.out

 Number of Resources of matrix have 3
 Number of Processes of matrix have 5
 Number of Available resources are	 3 	 3 	 2 	 
 Number of Maximum need process can have 
 7	5	3	
3	2	2	
9	0	2	
2	2	2	
4	3	3	

 Number of Allocation of resources to process are 
 0	1	0	
2	0	0	
3	0	2	
2	1	1	
0	0	2	

 Number of need of resources process can have 
 7	4	3	
1	2	2	
6	0	0	
0	1	1	
4	3	1	

 check whether process is in safe state 
 
 selected process 1 
 selected process 3 
 selected process 0 
 selected process 2 
 selected process 4 
 System is in safe state 

 Safe Sequence  is 
  1	 3	 0	 2	 
  Enter the process who want to request 
 1	1	0	0
Enter Request 
 
 check whether process is in safe state 
 
 selected process 1 
 selected process 3 
 selected process 4  
 system is not in safe state 
 dell9@dell9-OptiPlex-3060:~/Desktop/Nisha/OS/assignment 1/set b$ 


*/
      

