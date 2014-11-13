#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <math.h>

#define M 60
typedef long long int ll;
ll n;
ll a[M],b[M],u[M];
double p[M];

double calc(double prob, int level){
  int i;
  double ret = 0.0;
  if(level == n){
    return prob;
  }
  else{
    if(u[ a[level] ] != -1){
      u[ a[level] ] = -1;
      ret = calc(prob*p[level], level+1);
      u[ a[level] ] = 0;
    }
    if(u[ b[level] ] != -1){

      u[ b[level] ] = -1;
      ret += calc(prob*(1.0-p[level]), level+1);
      u[ b[level] ] = 0;
    }
    return ret;
  }
}

double call(){
  int i;
  u[ a[0] ] = -1;
  double ret = calc(p[0],1);
  u[ a[0] ] = 0;

  u[ b[0] ] = -1;
  ret += calc(1.0-p[0],1);
  u[ b[0] ] = 0;
  return ret;
}

int main(){
  int t,i;
  scanf("%d",&t);
  //  assert(t <= 10 && t >= 1);
  while(t--){
    scanf("%lld",&n);
    //    assert(n <= 50 && n >= 1);
    for(i=0;i<M;i++){
      u[i] = 0;
    }     
    for ( i=0; i<n; i++){
      scanf("%lf %lld %lld",&p[i],&a[i],&b[i]);
      //      assert(p[i] <= 100 && p[i] >= 0);
      //      assert(a[i] <= 16 && a[i] >= 1);
      //      assert(b[i] <= 16 && b[i] >= 1);
      p[i] = ((double)p[i])/100.0;
    }
    if(n>16){
      printf("0.0000000\n");
    }
    else{
      double ans = call();
      //      assert(ans >= 0 && ans <= 1);
      printf("%.10lf\n",ans);
    }
  }
  return 0;
}
