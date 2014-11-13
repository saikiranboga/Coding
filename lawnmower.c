/*

GOOGLE CODEJAM 2013 - QUALIFICATION ROUND
WRITTEN BY: Saikiran Boga
DATE: 14 April 2:09AM

 */

#include<stdio.h>
int main(){
  int t,k,N,M,i,j,m,n;
  FILE* fp = fopen("lawnmover_output.txt","w");
  //STORE THE FIELD IN THIS TABLE
  int sq[10][10];
  scanf("%d",&t);

  //k LOOPS OVER THE TEST CASES
  for(k=1;k<=t;k++){    
    int pattern_possible = 1;

    //N => NUMBER OF ROWS ,, M => NUMBER OF COLS
    scanf("%d%d",&N,&M);
    
    //READ THE FIELD PATTERN
    for(i=0;i<N;i++){
      for(j=0;j<M;j++){
	scanf("%d",&sq[i][j]);
      }
    }
    
    for(i=0;i<N;i++){
      for(j=0;j<M;j++){
	if(sq[i][j]==1){

	  //FLAG TO CHECK WHETHER IF ANY ROW OR COL HAS 1 AND ANY OTHER ELEMENET IS 2
	  int flag = 1;

	  //CHECKING IN THE ROW
	  for( m=0; m<M; m++)
	    if(sq[i][m] != 1){
	      flag = 0;
	      break;
	    }

	  //ALL IS WELL IN THE ROW THE NO NEED TO CHECK COL
	  if(flag){
	    continue;
	  }
	  flag = 1;

	  //CHECKING IN THE COL
	  for( n=0; n<N; n++)
	    if(sq[n][j] != 1){
	      flag = 0;
	      break;
	    }
	  //ALL IS WELL IN THE COL BUT BOT ROW THEN CONTINUE TO NEXT ELEMENT
	  if(flag)
	    continue;

	  //IF WE HAVE REACHED HERE THEN THE FIELD PATTERN IS NOT POSSIBLE
	  fprintf(fp,"Case #%d: NO\n",k);
	  pattern_possible = 0;
	  //NO NEED TO CHECK OTHER ELEMENTS 
	  break;
	}
      }
      //NO NEED TO CHECK OTHER ROWS IF PATTERN IF NOT OKAY TILL NOW
      if(!pattern_possible){
	break;
      }
    }
    // IF EVERYTHING GOES ALLRIGHT
    if(pattern_possible)
      fprintf(fp,"Case #%d: YES\n",k);
  }
  return 0;
}
