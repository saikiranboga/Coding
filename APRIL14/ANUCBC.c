#include <stdio.h>
#include <stdlib.h>

#define ll long long

int a[100010];
int n;

void generateSubsets(int m){
  int i,j;
  /*
  dp[i][j] represents the number of subset till i that are congruent to j
  so dp[n][j] gives the total number of subsets with sum congruent to j

  rec: dp[i][j] = dp[i-1][j] + dp[i-1][j-a[i]]

  base cases:
  dp[0][0] = 1
  dp[0][i] = 1;
  */

  ll dp[n+1][m+1];
  dp[0][0] = 1;
  for(i=0;i<=n;i++)
    dp[i][0] = 1;
  for(i=1;i<=m;i++)
    dp[0][i] = 0;

  for(i=1; i<=n; i++){
    for(j=0; j<=m; j++){
      dp[i][j] = dp[i-1][j];
      if(j>=a[i])
        dp[i][j] += dp[i-1][j-a[i]];
    }
  }

  printf("   ");
  for(j=0;j<=m;j++)
    printf("%d ",j);
  printf("\n");
  for(i=0;i<=n;i++){
    printf("%d: ",i);
    for(j=0;j<=m;j++){
      printf("%d ",dp[i][j]);
    }
    printf("\n");
  }
  printf("%ld\n", dp[n][m]);
  return;
}

int main(){
  int t;
  scanf("%d",&t);
  while(t--){
    int i,q,m;
    scanf("%d %d",&n,&q);
    a[0] = 0;
    for(i=1;i<=n;i++)
      scanf("%d",&a[i]);
    for(i=0;i<q;i++){
      scanf("%d",&m);
      generateSubsets(m);
    }
  }
  return 0;
}