#include <stdio.h>
#include <stdlib.h>
int main(){
  int t;
  scanf("%d",&t);
  while(t--){
    long long int m,n;
    scanf("%lld %lld",&m,&n);
    //    long long int primes = new long long int[n-m+1];
    long long int *primes;
    primes = (long long int*)malloc((n-m+1)*sizeof(long long int));
    for (long long int j=0;j<(n-m+1);j++)
      primes[j] = 0;
    for (long long int k=2;k*k<n;k++){
      long long int low = (m/k)*k;
      for(long long int decide=low;decide<=n;decide+=k)
	if((decide!=k)&&(decide>=m))
	  primes[decide-m] = 1;
    }
    for (long long int itr = 0;itr<(n-m+1);itr++)
      if(!primes[itr]&&(itr+m)!=1)
	printf("%lld\n",(itr+m));
    printf("\n");
  }
  return 0;
}

