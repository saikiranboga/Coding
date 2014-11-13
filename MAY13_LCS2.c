#include<stdio.h>
#include<stdlib.h>
#include<string.h>
 
int LCSLength( char X[], char Y[] ){
  int i,j;
  int m = strlen(X);
  int n = strlen(Y);
  int C[m+1][3];
 
  for(i=0;i<3;i++)
    C[i][0] = 0;
 
  for(i=0;i<n+1;i++)
    C[0][i] = 0;
 
  for( i=1; i<m+1; i++ ){
    for( j=1; j<n+1; j++ ){
      if(X[i-1] == Y[j-1]){
	C[i][j] = C[i-1][j-1] + 1;
      }
      else{
	C[i][j] = (C[i][j-1]>C[i-1][j]) ? C[i][j-1]:C[i-1][j];
      }
    }
  }
  if(C[m][n] == m || C[m][n] == n)
    return 1;
  else
    return 0;
}
int main(){
  int t;
  char str1[25002], str2[25002];
 
  scanf("%d",&t);
  while(t--){
    scanf("%s%s",&str1,&str2);
    if(LCSLength(str1,str2) == 1)
      printf("YES\n");
    else
      printf("NO\n");
  }
  return 0;
}
 
