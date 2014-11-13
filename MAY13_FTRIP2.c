#include<stdio.h>
long long int a[1001][1001];

void init(){
  int i,j;
  for(i=0;i<1001;i++){
    for(j=0;j<1001;j++){
      a[i][j] = 0;
    }
  }
  for (i=0;i<1001;i++){
    a[i][0] = 1;
    a[i][i] = 1;
  }
  for(i=1;i<1001;i++){
    for(j=1;j<1001;j++){
      if (i != j){
	a[i][j] = a[i-1][j] + a[i-1][j-1];
      }
    }
  }
}
int main(){
  init();
  int t,i,s,n,m,k,j;
  scanf("%d",&t);
  while(t--){
    scanf("%d %d %d %d",&s,&n,&m,&k);
    double mul = 0.000000;
    double div = (double)(a[s-1][n-1]);
    if(s == n){
      printf("1.000000\n");
      continue;
    }
    if(k>n){
      printf("0.000000\n");
      continue;
    }
    int temp;
    if(m>n){
      temp = n;
    }
    else{
      temp = m;
    }
    for(i=k;i<temp;i++){
      mul += ((a[m-1][i])*(a[s-m][n-i-1]));
    }
    printf("%.12lf\n",((double)(mul/div)));
    }
  return 0;
}
