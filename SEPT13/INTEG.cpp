#include <iostream>
#include <algorithm>
using namespace std;

typedef long long int ll;

int compare(const void * a, const void * b){
  if( (*(ll *)a - *(ll *)b) > 0)
    return 1;
  else
    return -1;
}

int main(){
  int n,i;
  cin >> n;
  ll a[n];
  ll x;
  ll num_neg = 0;
  ll sum_neg = 0;
  for(i=0; i<n; i++){
    cin >> a[i];
    if(a[i] < 0)
      num_neg++;
  }
  cin >> x;
  qsort(a,n,sizeof(a[0]),compare);
  ll s[num_neg];
  ll sm[num_neg];
  s[0] = -1*a[num_neg-1];
  for(i=num_neg-2; i>=0; i--)
    s[num_neg-1-i] = -1*a[i];
  sm[0] = s[0];
  for(i=1;i<num_neg;i++)
    sm[i] = sm[i-1]+s[i];

  ll times,ans=0;
  if(x == 0){
    ans = 0;
  }
  else if( num_neg >= x ){
    times = s[num_neg-x];
    ans += (times*x);
    sum_neg = sm[num_neg-1] - sm[num_neg-x] - (x-1)*times;
    ans += sum_neg;      
  }
  else{
    ans = sm[num_neg-1];
  }
  cout << ans << endl;
  return 0;
}
