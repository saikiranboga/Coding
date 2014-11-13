#include <iostream>
#include <stdlib.h>
using namespace std;

int compare(const void *a,const void *b){
  return ( *(int*)a-*(int*)b );
}

int main(){
  int t,n,i;
  cin >> t;
  while(t--){
    cin >> n;
    int x[n],y[n],z[n];

    for(i=0;i<n;i++){
      cin >> x[i];
    }
    for(i=0;i<n;i++){
      cin >> y[i];
    }
    for(i=0;i<n;i++){
      z[i] = x[i]-y[i];
    }
    int ans = 0, flag = 1;
    if(n==1){
      if(z[0] < 0){
	flag = 0;
      }
      else{
	flag = 1;
	ans = z[0];
      }
    }
    else{
      while(1){
	qsort(z,n,sizeof(int),compare);
	if(z[0] == 0 && z[n-1] == 0){
	  break;
	}
	for(i=0;i<n-1;i++)
	  z[i]++;
	z[n-1]--;
	ans++;
	flag = 1;
	if(ans >= 50){
	  flag = 0;
	  break;
	}
      }
    }

    if(flag == 0){
      cout << -1 << endl;
    }
    else{
      cout << ans << endl;
    }
  }
  return 0;
}
