#include <iostream>
using namespace std;

int main(){
  int n,m,i,j;
  cin >> n >> m;
  int a[n][m], b[n][m];
  int cnt = 1;

  for(i=0;i<n;i++){
    for(j=0;j<m;j++){
      a[i][j] = cnt++;
    }
  }

  for(i=0;i<n;i++){
    for(j=0;j<m;j++){
      cout << a[i][j] << '\t';
    }
    cout << endl;
  }

  cnt = 1;
  for(i=0;i<m;i++){
    for(j=0;j<n;j++){
      b[i][j] = cnt++;
    }
  }

  for(i=0;i<m;i++){
    for(j=0;j<n;j++){
      cout << b[i][j] << '\t';
    }
    cout << endl;
  }


  int ans = 0;
  for(i=0;i<n;i++){
    for(j=0;j<m;j++){
      if(a[i][j] == b[i][j])
	ans++;
    }
  }
  cout << a[5][6] << " " << b[5][6] << endl;
  cout << ans << endl;
  return 0;
}
