#include <stdio.h>

int main(void) {
 
  int n ;
  int CT = 0; // CT = compilation time 
  int TAT = 0;// TAT = turn around time 
  int WT = 0  ;// WT = waiting time 
  
  scanf( "%d" , &n ) ; 
  
  for (int i = 0 ; i<n ; i++ ) {
    int p , q ; 
    scanf( "%d %d" , &p , &q ) ;
      if ( p > CT  ) {
        CT = p ; 
        WT += p - CT ; 
      } 
       WT += CT - p ;  
       CT += q ;
       TAT += CT - q;   
  }
  printf ("Completion time = %d \n" , CT ) ;
  printf ("Turn around time = %d \n" , TAT ) ; 
  printf ("Waiting time = %d \n" , WT ) ; 
  printf ("Average Turnaround time = %d \n" , TAT/n ) ; 
  printf ("Average waiting time = %d \n" , WT/n ) ; 
  
  return 0;
}
