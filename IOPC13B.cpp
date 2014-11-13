#include<stdio.h>
#include<vector>
#include <numeric>

int main(){
  long long int t,N,M,i;
  long long int quos;
  std::vector<long long int> rem;
  scanf("%lld",&t);
  while(t--){
    scanf("%lld%lld",&N,&M);
    long long int r,len,i=1;
    rem.push_back(0);
    while(i<M){
      r = (i*N)%M;
      //      printf("%lld-",r);
      i++;
      if(r == 0)
	break;
      rem.push_back(r);
    }
    long long int sum_of_elems =std::accumulate(rem.begin(),rem.end(),0);
    len = rem.size();
    quos = 2*((N*M*(M-1)/2)-sum_of_elems*(M/len)-std::accumulate(rem.begin(),rem.begin()+(M%len),0));
    quos /= M;
    printf("%lld\n",quos);
  }
  return 0;
}
