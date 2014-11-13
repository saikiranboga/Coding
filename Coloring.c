/*
  This problem is a "Dynamic Programming"(DP) problem
  The recursion step is:
           C[i][c] = H[c] + min( C[i-1][x] such that x belongs to {R,B,G}-{c} ) 
	                 where 			
			     and c belongs to {R,B,G}

example:

   first house can be colored in 3 ways R,G,B
   so initialize 
         C[0][R] = cost of coloring it with red;
         C[0][G] = cost of coloring it with green;
         C[0][B] = cost of coloring it with blue;

   next, there are three possibilities of coloring the adjacent house: 

         1. If house 0 is colored in R then this can be colored in G or B.
         1. If house 0 is colored in G then this can be colored in R or B.
         1. If house 0 is colored in B then this can be colored in R or G.

   like this calculate recursively until the last house starting from the 2nd house(1st is initialize case)

   Then find the minimum of the last row (the possible colorings for the last house), this is the ans.

*/


#include<stdio.h>

// Initializing the constants R,G,B for using as indexes
// this will be initialized as: R=0; G=1; B=2
enum {R,G,B};  

// funtion that returns minimum of two numbers
int min(int a,int b){
  return a>b?b:a;
}

int main(){
  int N,r,g,b,i,j,n;
  scanf("%d",&N);

  //matrix to store the costs till the i'th house,
  //used for DP
  int cost[N][3];
  for(n=0;n<N;n++){
    scanf("%d %d %d",&r,&g,&b);
    if(n==0){
      cost[n][R] = r;
      cost[n][G] = g;
      cost[n][B] = b;
    }
    else{
      cost[n][R] = r + min(cost[n-1][G], cost[n-1][B]);
      cost[n][G] = g + min(cost[n-1][R], cost[n-1][B]);
      cost[n][B] = b + min(cost[n-1][R], cost[n-1][G]);
    }
  }
  int ans = min(cost[n-1][R], cost[n-1][G]);
  ans = min(ans, cost[n-1][B]);
  printf("%d\n",ans);
  return 0;
}
