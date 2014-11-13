#include <iostream>

using namespace std;

int isSubset(int set[], int n, int sum){
  int i,j;
  bool subset[sum+1][n+1];

  for(i=0;i<=sum;i++)
    subset[i][0] = false;

  for(i=0; i<=n; i++)
    subset[0][i] = true;

  for(i=1; i<=sum; i++){
    for(j=1; j<=n; j++){
      if(set[j-1] > i)
	subset[i][j] = subset[i][j-1];
      else
	subset[i][j] = subset[i][j-1] || subset[i-set[j-1]][j-1];
    }
  }
  /*
  for(i=0; i<=sum; i++){
    for(j=0; j<=n; j++){
      cout << subset[i][j] << " ";
    }
    cout << endl;
  }
  */
  return subset[sum][n];
}

int main(){
  int t,n,i,m;
  cin >> t;
  while(t--){
    cin >> n >> m;
    int set[n];
    for(i=0; i<n ;i++)
      cin >> set[i];
    if(isSubset(set,n,m))
      cout << "Yes\n";
    else
      cout << "No\n";
  }
  return 0;
}
