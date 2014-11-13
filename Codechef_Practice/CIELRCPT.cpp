#include <cstdio>
#include <iostream>
using namespace std;

#define MAXN 100001

int nm[MAXN];
int c[12] = {1,2,4,8,16,32,64,128,256,512,1024,2048};

void calc(){
  int m,i,best;
  nm[0] = 0;

  for(m=1; m<MAXN; m++){
    best = 1000000000;
    for(i=0; i<12; i++){
      if(m >= c[i]){
	if( (nm[m-c[i]]+1) < best)
	  best = nm[m-c[i]] + 1;
      }
    }
    nm[m] = best;
  }

}

int main(){
  int t,p;
  calc();
  //  cin >> t;
  scanf("%d",&t);
  while(t--){
    //    cin >> p;
    scanf("%d",&p);
    //    cout << nm[p] << endl;
    printf("%d\n",nm[p]);
  }
  return 0;
}
