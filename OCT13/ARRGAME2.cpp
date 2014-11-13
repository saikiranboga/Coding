#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
#define ll long long int

int compare(const void *a, const void *b){
  return ( *(int*)a - *(int*)b );
}

int main(){
  ll t,i,j,n,tmp;
  scanf("%lld",&t);
  while(t--){
    scanf("%lld",&n);
    ll a[n], b[n];
    ll a_ones = 0, b_ones = 0, b_twos = 0;
    for(i=0;i<n;i++){
      scanf("%lld",&tmp);
      if(tmp == 1)
	a_ones++;
      a[i] = tmp;
    }

    for(i=0;i<n;i++){
      scanf("%lld",&tmp);
      if(tmp == 1)
	b_ones++;
      else if(tmp == 2)
	b_twos++;
      b[i] = tmp;
    }
    qsort(a,n,sizeof(ll),compare);
    qsort(b,n,sizeof(ll),compare);

    ll lb,cnt,x,y;
    double store,ans = 0.00;
    double div = 1.0/((double)n);
    for(i = a_ones; i<n; i++){
      store = 0;
      x = a[i];
      if(x == 2){
	x = 5;
      }
      else{
	x++;
      }
      lb = lower_bound(b,b+n,x)-b;
      cnt = lb;
      if(cnt < n){
	store += (n-cnt);
      }
      if(x == 4){
	store += b_twos;
      }
      //      cout << a[i] << ": " << store << endl;
      store = ((double)store)*((double)div);
      ans += store;
    }

    ans = ans + ( ((double)(b_ones*(n-a_ones)) )*( (double)div) );

    printf("%0.8lf\n",ans);
  }
  return 0;
}
