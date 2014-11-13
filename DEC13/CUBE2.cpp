#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

#define Mx 45

int cub[Mx+1][Mx+1][Mx+1];

int main(){
  int t,i,j,k,l,m,n;
  double p;
  cin >> t;
  while(t--){
    cin >> n >> p;
    char A[n+1][n+1][n+1];
    char B[n+1][n+1][n+1];

    int C[n+1][n+1][n+1];

    p = p/100.0;
    int size[n+1];
    for(i=0;i<=n;i++){
      size[i] = 0;
    }

    for(i=1;i<=n;i++)      for(j=1;j<=n;j++)	for(k=1;k<=n;k++){
	  cin >> A[i][j][k];
	}
    for(i=1;i<=n;i++)      for(j=1;j<=n;j++)	for(k=1;k<=n;k++){
	  cin >> B[i][j][k];
	}
    for(i=1;i<=n;i++)      for(j=1;j<=n;j++)	for(k=1;k<=n;k++){
	  if(A[i][j][k] == B[i][j][k]){
	    C[i][j][k] = 1;
	  }
	  else{
	    C[i][j][k] = 0;
	  }
	}
    int mn = 50;
    for(i=2;i<=n;i++)      for(j=2;j<=n;j++)	for(k=2;k<=n;k++){
	  if(C[i][j][k] == 1){
	    mn = 50;
	    mn = min( mn, C[i-1][j][k]);
	    mn = min( mn, C[i][j-1][k]);
	    mn = min( mn, C[i][j][k-1]);
	    mn = min( mn, C[i-1][j-1][k]);
	    mn = min( mn, C[i-1][j][k-1]);
	    mn = min( mn, C[i][j-1][k-1]);
	    mn = min( mn, C[i-1][j-1][k-1]);
	    C[i][j][k] = mn + 1;
	  }
	}

    for(i=1;i<=n;i++)      for(j=1;j<=n;j++)	for(k=1;k<=n;k++){
	  if(C[i][j][k] > 0){
	    size[C[i][j][k]]++;
	  }
	}

    int maxSize = 0,maxCount = 0;
    for(i=1;i<=n;i++){
      if(size[i] > 0 ){
	maxCount = size[i];
	maxSize = i;
      }
    }
    if(maxSize == 0){
      cout << -1 << endl;
    }
    else{
      cout << maxSize << " " << maxCount << endl;
    }
  }
  return 0;
}
/*
abcdefghijklmnopqrstuvwxyz-
abcdefghijklmnopqrabcdefghi
*/
