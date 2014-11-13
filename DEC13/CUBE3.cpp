#include <iostream>
using namespace std;

#define Mx 45

int cub[Mx+1][Mx+1][Mx+1];

int main(){
  std::ios::sync_with_stdio(false);
  int t,i,j,k,l,m,n,p;
  cin >> t;
  while(t--){
    cin >> n >> p;
    char str1[n*n*n];
    char str2[n*n*n];
    char A[n+1][n+1][n+1];
    char B[n+1][n+1][n+1];

    int size[n+1];
    for(i=0;i<=n;i++){
      size[i] = 0;
    }
    for(i=0;i<=Mx;i++)      for(j=0;j<=Mx;j++)	for(k=0;k<=Mx;k++){
	  cub[i][j][k] = 0;
	}
    cin >> str1 >> str2;
    
    for(i=1;i<=n;i++)      for(j=1;j<=n;j++)	for(k=1;k<=n;k++){
	  A[i][j][k] = str1[(i-1)*n*n + (j-1)*n + k-1];
	}
    for(i=1;i<=n;i++)      for(j=1;j<=n;j++)	for(k=1;k<=n;k++){
	  B[i][j][k] = str2[(i-1)*n*n + (j-1)*n + k-1];
	}

    int counter = 0;
    for(i=1;i<=n;i++)      for(j=1;j<=n;j++)	for(k=1;k<=n;k++){
	  //	  counter++;
	  //	  cout << i << "," << j << "," << k << "," << 1 <<endl;
	  if(A[i][j][k] == B[i][j][k]){
	    cub[i][j][k] = 1;
	    //	    size[1]++;
	  }
	  else{
	    cub[i][j][k] = 0;
	  }
	}

    for(i=1; i<=n; i++)
      for(j=1; j<=n; j++)
	for(k=1; k<=n; k++)
	  cub[i][j][k] += cub[i-1][j][k];

    for(i=1; i<=n; i++)
      for(j=1; j<=n; j++)
	for(k=1; k<=n; k++)
	  cub[i][j][k] += cub[i][j-1][k];

    for(i=1; i<=n; i++)
      for(j=1; j<=n; j++)
	for(k=1; k<=n; k++)
	  cub[i][j][k] += cub[i][j][k-1];

    /*
    for(i=1;i<=n;i++)      for(j=1;j<=n;j++)	for(k=1;k<=n;k++){

	      int s0 = cub[i-1][j-1][k-1];
	      int s1 = plns[i][j][k].xy + plns[i][j][k].yz + plns[i][j][k].zx - axs[i][j][k].x - axs[i][j][k].y - axs[i][j][k].z + cub[i][j][k];
	      assert(s0 >= 0);
	      assert(s1 >= 0);
	      cub[i][j][k] = s0 + s1;
	      assert(cub[i][j][k] >= 0);
	      assert(cub[i][j][k] <= 100000);

	      //	      cout << i << ',' << j << ','  << k << ">" << cub[i][j][k]<< endl;
	}
    */


    //    for(l=n;l>=2;l--){

    //      for(i=n;i>=l;i--)     for(j=n;j>=l;j--)     for(k=n;k>=l;k--){

    int cnt;
    for(l=1;l<=n;l++){
      for(i=1;i<=n-l+1;i++)      for(j=1;j<=n-l+1;j++)	for(k=1;k<=n-l+1;k++)	{
	    //	    counter++;
	    int i1 = i+l-1;
	    int j1 = j+l-1;
	    int k1 = k+l-1;
	    cnt = cub[i1][j1][k1]-cub[i-1][j1][k1]-cub[i1][j-1][k1]-cub[i1][j1][k-1]+cub[i-1][j-1][k1]+cub[i1][j-1][k-1]+cub[i-1][j1][k-1]-cub[i-1][j-1][k-1];
	    if( cnt*100 >= (p*l*l*l))
	      size[l]++;
	    //	    cout << i << ',' << j << ','  << k << ','  << l << cnt << endl;
	  }
      }
    //    int cubes = (n*n*(n+1)*(n+1))/4;
    //    assert(counter == cubes );
    //cout << counter << " " << cubes << endl;
    //    if(p == 0){
    //      cout << n << ' ' << 1 << '\n';
    //    }
    //    else{
    int maxSize = 0,maxCount = 0;
    for(i=n;i>=1;i--){
      if(size[i] > 0 ){
	maxCount = size[i];
	maxSize = i;
	break;
      }
    }
    if(i == 0 && maxSize == 0){
      cout << -1 << '\n';
    }
    else{
      cout << maxSize << ' ' << maxCount << '\n';
    }
    //    }
  }
  return 0;
}
/*
abcdefghijklmnopqrstuvwxyz-
abcdefghijklmnopqrabcdefghi
*/
