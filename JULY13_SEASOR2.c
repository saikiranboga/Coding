#include <stdio.h>

long long int ans[1000000] = {0};

int main(){
  long long int t,N,K,i,j,m;
  scanf("%lld",&t);
  while(t--){
    scanf("%lld %lld",&N,&K);
    long long int ar[N+1];
    ar[0] = 0;
    for(i=1;i<=N;i++){
      scanf("%lld",&ar[i]);
    }
    long long int count = 0;

    if(N<K && N != 1){
      ans[count] = 1;
      count++;
    }
    else{
      for(i=N-K+1,j=1; j<=N-K+1; j++){
	for(m=i;m>=j;m--){
	  ans[count] = m;
	  count++;
	}
      }
    }

    printf("%lld\n",count);

    for(i=0; i<count; i++){
      printf("%lld",ans[i]);
      if(i != count-1)
	printf(" ");
    }
    if(count !=0)
      printf("\n");

  }
  return 0;
}

/*

1
10 3
8 2 5 7 3 1 4 10 9 6

 */
