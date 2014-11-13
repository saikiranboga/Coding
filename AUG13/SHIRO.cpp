#include<iostream>

using namespace std;

int n,a[110];
double p[110];

double calc(int level, int count_a, int count_b, double prob){
  if(level == n){
    if(count_a >= count_b)
      return prob;
    else
      return 0;
  }
  else if(prob == 0){
    return 0;
  }
  else{
    return ( calc(level+1, count_a + a[level], count_b, prob*p[level]) + calc(level+1, count_a, count_b + a[level], prob*(1-p[level]) ) );
  }
}

int main(){
  int t,i;
  cin >> t;
  while(t--){
    cin >> n;
    for(i=0;i<n;i++)
      cin >> a[i];
    for(i=0;i<n;i++){
      cin >> p[i];
      p[i] /= 100;
    }
    double ans = calc(1, a[0],0,p[0]) + calc(1, 0,a[0],1-p[0]);
    cout << ans << endl;
  }
  return 0;
}
