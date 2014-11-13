#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int LCSLength( char X[], char Y[] ){
  int i,j;
  int m = strlen(X);
  int n = strlen(Y);

  int start = 0;
  int m_end = m-1;
  int n_end = n-1;

  int count = 0;

  while( (start <= m_end) && (start <= n_end) && (X[start] == Y[start])){
    start++;
    count++;
  }

  while( (start <= m_end) && (start <= n_end) && (X[m_end] == Y[n_end])){
    m_end--;
    n_end--;
    count++;
  }

  //  printf("start=%d,m=%d,n=%d,m_end=%d,n_end=%d,count=%d\n",start,m,n,m_end,n_end,count);

  int m_mod = m_end-start+1;
  int n_mod = n_end-start+1;
  int C[m_mod+1][n_mod+1];

  //  int C[m+1][n+1];

  for(i=0;i<m_mod+1;i++)
    C[i][0] = 0;

  for(i=0;i<n_mod+1;i++)
    C[0][i] = 0;

  for( i=start+1; i<start+m_mod+1; i++ ){
    for( j=start+1; j<start+n_mod+1; j++ ){
      if(X[i-1] == Y[j-1]){
	C[i-start][j-start] = C[i-1-start][j-1-start] + 1;
      }
      else{
	C[i-start][j-start] = (C[i-start][j-1-start]>C[i-1-start][j-start]) ? C[i-start][j-1-start]:C[i-1-start][j-start];
      }
    }
  }


  if(C[m_mod][n_mod]+count == m || C[m_mod][n_mod]+count == n)
    return 1;
  else
    return 0;
}
int main(){
  int t;
  char str1[40002], str2[40002];

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
