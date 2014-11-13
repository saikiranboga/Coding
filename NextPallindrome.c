#include<stdio.h>
char num[1000000];

void palin(int start,int end){
  int a = num[start],b = num[end-1];
  if(a == b)
    palin(start+1,end-1);
  else if(a > b){
    num[end-1] += a-b;
    palin(start+1,end-1)
  }
  else{
    num[end]
  }
}


int main(){
  int i,len=0;
  scanf("%s",&num);
  for(i=0;num[i] != '\0';i++){
    len++;
    //printf("%d",num[i]-48);
  }
  palin(0,len);
  return 0;
}
