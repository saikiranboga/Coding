#include<stdio.h>
int main(){
  int t;
  float m,n,x,y,d,k;
  int num_cells;
  scanf("%d",&t);
  while(t--){
    scanf("%f%f%f%f%f%f",&d,&x,&y,&m,&n,&k);
    num_cells = d/(1.732*k);
    if(num_cells > m*n){
      printf("%d\n",m*n);
    }
    else if(m == 1 || n == 1){
      printf("%d\n",(num_cells/2));
    }
    else if(x == 0 && y == 0){
      printf("%d\n",num_cells);
    }
    else{
      printf("%d\n",num_cells*2);
    }
  }
  return 0;
}
