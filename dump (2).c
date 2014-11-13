#include<stdio.h>
int main(){
  int i;  
  //scanf("%d",&i);  
  i = 5;
  i++;
  int j = i;
  i--;
  j += i;
  printf("%d\n",j);
  return 0;
}
