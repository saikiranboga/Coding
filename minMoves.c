#include<stdio.h>
int main(){
  int i,n;
  scanf("%d",&n);
  int array[n];
  for(i=0;i<n*n;i++){
    scanf("%d",&array[i]);
  }
  for(i=0;i<n*n;i++){
    printf("%d",array[i]);
  }
  return 0;
}
