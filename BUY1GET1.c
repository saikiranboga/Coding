#include<stdio.h>
#include<string.h>
int main(){
  int t,i,cost;
  char c;
  char str[210];
  scanf("%d",&t);
  while(t--){
    int arr[257]={0};
    cost = 0;
    str[0] = '\0';
    scanf("%s",&str);
    i = 0;
    while(str[i] != '\0'){
      arr[str[i]]++;
      i++;
    }
    for(i=65;i<=90;i++){
      cost += ((arr[i]/2)+(arr[i]%2));      
    }
    for(i=97;i<=122;i++){
      cost += ((arr[i]/2)+(arr[i]%2));      
    }
    printf("%d\n",cost);
  }
  return 0;
}
