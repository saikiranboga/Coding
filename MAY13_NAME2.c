#include<stdio.h>
#include<string.h>

int subseq(char Y[],char X[]){
  /* int i,j=0,flag=1;
  for(i=0;i<strlen(Y);i++){
    while(X[j] != Y[i]){
      j++;
      if(j == strlen(X)){
	flag = 0;
	break;
      }
    }
    if(j < strlen(X))
      j++;
    else
      break;
  }
  return flag;*/
  int i=0,j=0;
  while(Y[j]!='\0'&&X[i]!='\0')
    {
      if(Y[j] == X[i])
	{j++;i++;}
      else
	{i++;}
    }
  if(Y[j] == '\0')
    {return 1;}
  else
    {return 0;}
}

int main(){
  int t;
  char str1[25005],str2[25005];
  scanf("%d",&t);
  while(t--){
    scanf("%s %s",&str1,&str2);
    int ans;
    if(strlen(str1) > strlen(str2)){
      ans = subseq(str2,str1);
    }
    else{
      ans = subseq(str1,str2);
    }
    if(ans == 1){
      printf("YES\n");
    }
    else{
      printf("NO\n");
    }
  }
  return 0;
}
