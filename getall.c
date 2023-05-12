//Slot 1
#include<stdio.h>
#include<ctype.h>
 int  avail[] = {3,3,2} ;
      int max[][10] = { {7,5,3} ,{3,2,2},{9,0,2} ,{2,2,2},{4,3,3}};
      int alloc[][10] = { {0,1,0} ,{2,0,0},{3,0,2} ,{2,1,1},{0,0,2}};
      
      int need[10][10] ;
          int m = 3 , n = 5 , i,j;
          void  get_allocation_matrix();

void main()
   {
    get_allocation_matrix();
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
   /*
   dell9@dell9-OptiPlex-3060:~/Desktop/Nisha/OS/assignment 1$ gcc getall.c
dell9@dell9-OptiPlex-3060:~/Desktop/Nisha/OS/assignment 1$ ./a.out

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
*/ 
