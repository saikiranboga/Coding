#include <iostream>
#include <math.h>
using namespace std;

#define Mx 45

typedef struct Axis{
  int x;
  int y;
  int z;
}Axis;

typedef struct Planes{
  int xy;
  int yz;
  int zx;
}Planes;


//int xy[Mx+1][Mx+1][Mx+1],yz[Mx+1][Mx+1][Mx+1],zx[Mx+1][Mx+1][Mx+1];
int cub[Mx+1][Mx+1][Mx+1][Mx+1];

int main(){
  std::ios::sync_with_stdio(false);
  int t,i,j,k,l,m,n;
  //  double p;
  int p;
  cin >> t;
  while(t--){
    cin >> n >> p;
    char A[n+1][n+1][n+1];
    char B[n+1][n+1][n+1];

    Axis axs[n+1][n+1][n+1];
    Planes plns[n+1][n+1][n+1];
    //    p = p/100.0;
    int size[n+1];
    for(i=0;i<=n;i++){
      size[i] = 0;
    }

    for(i=0;i<=n;i++)      for(j=0;j<=n;j++)	for(k=0;k<=n;k++){
	  axs[i][j][k].x = 0;
	  axs[i][j][k].y = 0;
	  axs[i][j][k].z = 0;

	  plns[i][j][k].xy = 0;
	  plns[i][j][k].yz = 0;
	  plns[i][j][k].zx = 0;


	}

    for(i=0;i<=Mx;i++)      for(j=0;j<=Mx;j++)	for(k=0;k<=Mx;k++)	for(l=0;l<=Mx;l++){
	    cub[i][j][k][l] = 0;
	  }

    for(i=1;i<=n;i++)      for(j=1;j<=n;j++)	for(k=1;k<=n;k++){
	  cin >> A[i][j][k];
	}
    
    for(i=1;i<=n;i++)      for(j=1;j<=n;j++)	for(k=1;k<=n;k++){
	  cin >> B[i][j][k];
	}

    for(i=1;i<=n;i++)      for(j=1;j<=n;j++)	for(k=1;k<=n;k++){
	  if(A[i][j][k] == B[i][j][k]){
	    axs[i][j][k].x = axs[i-1][j][k].x + 1;
	    axs[i][j][k].y = axs[i][j-1][k].y + 1;
	    axs[i][j][k].z = axs[i][j][k-1].z + 1;
	  }
	  else{
	    axs[i][j][k].x = axs[i-1][j][k].x;
	    axs[i][j][k].y = axs[i][j-1][k].y;
	    axs[i][j][k].z = axs[i][j][k-1].z;
	  }
	}

    for(i=1;i<=n;i++)      for(j=1;j<=n;j++)	for(k=1;k<=n;k++){
	    plns[i][j][k].xy = plns[i-1][j][k].xy + axs[i][j][k].y;
	    plns[i][j][k].yz = plns[i][j-1][k].yz + axs[i][j][k].z;
	    plns[i][j][k].zx = plns[i][j][k-1].zx + axs[i][j][k].x;
	}

    for(i=1;i<=n;i++)      for(j=1;j<=n;j++)	for(k=1;k<=n;k++){
	  if(A[i][j][k] == B[i][j][k]){
	    cub[i][j][k][1] = 1;
	    size[1]++;
	  }
	  else{
	    cub[i][j][k][1] = 0;
	  }
	}
    int match;
    for(i=1;i<=n;i++)      for(j=1;j<=n;j++)	for(k=1;k<=n;k++)	for(l=2;l<=n;l++){

	    if( (i-l>=0) && (j-l>=0) && (k-l>=0) ){

	      int s0 = cub[i-1][j-1][k-1][l-1];
	      int s1 = plns[i][j][k].xy + plns[i][j][k].yz + plns[i][j][k].zx - axs[i][j][k].x - axs[i][j][k].y - axs[i][j][k].z + cub[i][j][k][1];
	      int s2 = -plns[i-l][j][k].xy - plns[i][j-l][k].xy + plns[i-l][j-l][k].xy;
	      int s3 = -plns[i][j][k-l].zx - plns[i-l][j][k].zx + plns[i-l][j][k-l].zx;
	      int s4 = -plns[i][j-l][k].yz - plns[i][j][k-l].yz + plns[i][j-l][k-l].yz;
	      int s5 = axs[i][j][k-l].z + axs[i-l][j][k].x + axs[i][j-l][k].y;
	      //	      cout << s0 << ',' << s1 << ',' << s2 << ',' << s3 << ',' << s4 << ',' << s5 << endl;
	      cub[i][j][k][l] = s0
		+ s1
		+ s2
		+ s3
		+ s4
		+ s5

		/*		+ plns[i-l][j][k].yz + plns[i][j-l][k].zx + plns[i][j][k-l].xy 
		- plns[i][j-l][k].xy - plns[i-l][j][k].xy + plns[i-l][j-l][k].xy
		- plns[i][j-l][k].yz - plns[i][j][k-l].yz + plns[i][j-l][k-l].yz
		- plns[i-l][j][k].zx - plns[i][j][k-l].zx + plns[i-l][j][k-l].zx
		- plns[i-l][j][k-l].xy - plns[i][j-l][k-l].xy + plns[i-l][j-l][k-l].xy
		- plns[i-l][j-l][k].yz - plns[i-l][j][k-l].yz + plns[i-l][j-l][k-l].yz
		- plns[i-l][j-l][k].zx - plns[i][j-l][k-l].zx + plns[i-l][j-l][k-l].yz
		+ axs[i-l][j][k].z - axs[i-l][j][k-l].z
		+ axs[i][j-l][k].z - axs[i][j-l][k-l].z
		+ axs[i][j][k-l].x - axs[i-l][j][k-l].x
		+ axs[i][j][k-l].y - axs[i][j-l][k-l].y
		+ axs[i-l][j-l][k].z - axs[i-l][j-l][k-l].z
		+ axs[i][j-l][k-l].x - axs[i-l][j-l][k-l].x
		+ axs[i-l][j][k-l].y - axs[i-l][j-l][k-l].y
		+ axs[i-l][j][k].y - axs[i-l][j-l][k].y
		+ axs[i][j-l][k].x - axs[i-l][j-l][k].x
		+ cub[i-l][j-l][k][1]
		+ cub[i-l][j][k][1]
		+ cub[i-l][j][k-l][1]
		+ cub[i][j-l][k][1]
		+ cub[i-l][j-l][k-l][1]
		+ cub[i][j][k-l][1]
		*/
		;

	      if( ceil( ( (double)cub[i][j][k][l]/((double)l*l*l))*100.0 ) >= p){
		size[l]++;
		//		cout << "match: " << l << endl;
	      }
	      //cout << i << ',' << j << ','  << k << ','  << l << "> " << cub[i][j][k][l] << endl;
	    }
	  }

    /*
    //axes
    cout << "axes\n";
    for(i=1;i<=n;i++)      for(j=1;j<=n;j++)	for(k=1;k<=n;k++){
	  cout << i << ',' << j << ','  << k << ',' << "> " << axs[i][j][k].x << ',' << axs[i][j][k].y << ',' << axs[i][j][k].z << endl ;
	}

    //planes
    cout << "planes\n";
    for(i=1;i<=n;i++)      for(j=1;j<=n;j++)	for(k=1;k<=n;k++){
	  cout << i << ',' << j << ','  << k << ',' << "> " << plns[i][j][k].xy << ',' << plns[i][j][k].yz << ',' << plns[i][j][k].zx << endl ;
	}

    //cubes
    cout << "cubes\n";
    for(i=1;i<=n;i++)      for(j=1;j<=n;j++)	for(k=1;k<=n;k++)	for(l=1;l<=n;l++){
	    cout << i << ',' << j << ','  << k << ','  << l << "> " << cub[i][j][k][l] << endl;
	  }
    */

    int maxSize = 0,maxCount = 0;
    if(p == 0){
      cout << n << " " << 1 << endl;
    }
    else{
      for(i=1;i<=n;i++){
	if(size[i] > 0 ){
	  maxCount = size[i];
	  maxSize = i;
	}
      }
      if(maxSize == 0)
	cout << -1 << endl;
      else
	cout << maxSize << " " << maxCount << endl;
    }
  }
  return 0;
}
/*
abcdefghijklmnopqrstuvwxyz-
abcdefghijklmnopqrabcdefghi
*/
