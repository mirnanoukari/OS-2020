#include <stdio.h>
int min ( int p , int q ) {
  if ( p <= q ) return p ; 
  return q  ;
}
int main(void) {
  int n ,m;
  int CT = 0; // CT = compilation time 
  int TAT = 0;// TAT = turn around time 
  int WT = 0  ;// WT = waiting time 
  
  scanf( "%d %d" , &n , &m ) ; 
  int process[100][100] ; 
  for (int i = 0 ; i<n ; i++ ) {
      int p , q ; 
      scanf( "%d %d" , &p , &q ) ;
      process[i][0] = p ; 
      process[i][1] = q ;
      process[i][2] = p ;
  } 
  int l = 1 ;
  while (l == 1 ) {
   l = 0 ; 
    for (int i = 0 ; i<n ; i++ ) { 
      int p = process[i][0] ; 
      int q = process[i][1] ;
      if (q > 0) l = 2 ; 
      if (p <= CT && q > 0 ) {
        l = 1 ; 
        WT += CT - process[i][2] ; 
        int x = min( q , m ) ;
        CT += x ; 
        process[i][2] = CT ;
        process[i][1] -= x ;
        if (process[i][1] == 0 ) 
        TAT += CT ; 
      }
    }
    if ( l == 2 ) {
      l = 1 ; 
      CT++ ; 
    }
  }
  printf ("Completion time = %d \n" , CT ) ;
  printf ("Turn around time = %d \n" , TAT ) ; 
  printf ("Waiting time = %d \n" , WT ) ; 
  printf ("Average Turnaround time = %d \n" , TAT/n ) ; 
  printf ("Average waiting time = %d \n" , WT/n ) ; 
  return 0;
}
