#include<stdio.h>
 
char Survey(int x, int y) {
    printf("S %d %d\n", x, y);
    fflush(stdout);
    char res;
    scanf(" %c", &res);
    return res;
}
 
void Neutralize(int x, int y) {
    printf("N %d %d\n", x, y);
    fflush(stdout);
}
 
int main(){
  int N,M,K,i,j,p,q,p1,q1,m,n;
  int board[50][50];
  char res;
  scanf("%d %d %d",&N,&M,&K);
 
  for(i=0;i<N;i++){
    for(j=0;j<N;j++){
      board[i][j] = -2;
    }
  }
  for(i=0;i<N;i++){
    for(j=0;j<N;j++){
      if(board[i][j] == -2){
	res = Survey(i,j);
	//	printf("%d\n",res == '0');
	if( res == 'M'){
	  Neutralize(i,j);
	}else if(res == '0'){
	  if(i-1 >= 0){
	    p = i-1;
	  }
	  else{
	    p = i;
	  }
	  if(j-1 >= 0){
	    q = j-1;
	  }
	  else{
	    q = j;
	  }
 
	  if(i+1 < N){
	    p1 = i+1;
	  }
	  else{
	    p1 = i;
	  }
	  if(j+1 < N){
	    q1 = j+1;
	  }
	  else{
	    q1 = j;
	  }
	  for(m=p;m<=p1;m++){
	    for(n=q;n<=q1;n++){
	      board[m][n] = -1;
	    }
	  }	
	}
	else if(res == '8'){
	  Neutralize(i,j+1);
	  board[i][j+1] = -1;

	  Neutralize(i+1,j-1);
	  board[i+1][j-1] = -1;

	  Neutralize(i+1,j);
	  board[i+1][j] = -1;

	  Neutralize(i+1,j+1);
	  board[i+1][j+1] = -1;
	}
      }
      else{
	 if(i-1 >= 0){
	    p = i-1;
	  }
	  else{
	    p = i;
	  }
	  if(j-1 >= 0){
	    q = j-1;
	  }
	  else{
	    q = j;
	  }
 
	  if(i+1 < N){
	    p1 = i+1;
	  }
	  else{
	    p1 = i;
	  }
	  if(j+1 < N){
	    q1 = j+1;
	  }
	  else{
	    q1 = j;
	  }
	  int cnt=0;
	  for(m=p;m<=p1;m++){
	    for(n=q;n<=q1;n++){
	      if(board[m][n] == -2){
		cnt++;
	      }
	    }
	  }
	  if(cnt == (res-48)){
	    for(m=p;m<=p1;m++){
	      for(n=q;n<=q1;n++){
		if(board[m][n] == -2){
		  board[m][n] = -1;
		  Neutralize(m,n);
		}
	      }
	    }
	  }
	  continue;
      }
    }
  }
  printf("Done\n");
  fflush(stdout);
  return 0;
} 
