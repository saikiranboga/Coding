#include <stdio.h>

#define FOR(i,start,n) for(i=start;i<n;i++)
#define sd(n) scanf("%d",&n)
#define plf(ans) printf("%0.10lf\n",ans)

int main(){
  int i,t,N;
  sd(t);
  while(t--){
    sd(N);
    double ans = 0.5*N;
    double sub = 0.05;
    FOR(i,0,(N<10?N:10) ){
      ans -= sub;
      sub /= 10;
    }
    plf(ans);
  }
  return 0;
}
