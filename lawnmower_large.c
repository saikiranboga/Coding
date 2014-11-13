/*

GOOGLE CODEJAM 2013 - QUALIFICATION ROUND
LAWNMOWER_LARGE i/p
WRITTEN BY: Saikiran Boga
DATE: 14 April 2:36AM

 */
#include<stdio.h>
int main(){
  int t,k,N,M,m,n,i,j;
  int sq[100][100];
  FILE* fp = fopen("lawnmover_large_output.txt","w+");  
  scanf("%d",&t);

  for(k = 1; k <=t; k++){
    int pattern_possible = 1;
    scanf("%d%d",&N,&M);
    for(i=0;i<N;i++)
      for(j=0;j<M;j++)
	scanf("%d",&sq[i][j]);
    
    for( i=0; i<N; i++){
      for(j=0; j<M; j++){
	int flag = 1;
	for( m=0; m<M; m++)
	  if(sq[i][m] > sq[i][j]){
	    flag = 0;
	    break;
	  }
	if(flag)
	  continue;
	flag = 1;
	for(n=0; n<N; n++)
	  if(sq[n][j] > sq[i][j]){
	    flag = 0;
	    break;
	  }
	if(flag)
	  continue;
	fprintf(fp,"Case #%d: NO\n",k);
	pattern_possible = 0;
	break;
      }
      if(!pattern_possible)
	break;
    }
    if(pattern_possible)
      fprintf(fp,"Case #%d: YES\n",k);
  }
}
