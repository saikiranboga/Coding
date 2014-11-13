#include <stdio.h>
#include <string.h>
#include <math.h>
/* Head ends here */
void nextMove(int n, int r, int c, char grid[101][101]){
  int i,j,flag=0;
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      if(grid[i][j] == 'p'){
	flag = 1;
	break;
      }
    }
    if(flag == 1)
      break;
  }
  if(i==r){
    if(j<c)
      printf("LEFT\n");
    else
      printf("RIGHT\n");
  }
  else if(j==c){
    if(i<r)
      printf("UP\n");
    else
      printf("DOWN\n");
  }
  else{
    if(i>r)
      printf("DOWN\n");
    else
      printf("UP\n");
  }
}
/* Tail starts here */
int main(void) {

  int i,n, x, y;
  
  scanf("%d", &n);
  scanf("%d", &x);
  scanf("%d", &y);

  char grid[101][101];
    
  for(i=0; i<n; i++) {
    scanf("%s[^\n]%*c", grid[i]);
  }
  nextMove(n, x, y, grid);
  return 0;
}
