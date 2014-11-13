#include <iostream>
#include <stdio.h>
using namespace std;

long long int freq[1000000][2];

int main(){
  long long int i,j,n;
  scanf("%lld",&n);
  long long int ar[n+1],S[n+1];
  ar[0] = 0;
  for(i=1;i<=n;i++)
    scanf("%lld",&ar[i]);
  S[0] = 0;
  for(i=1;i<=n;i++)
    S[i] = ar[i]+S[i-1];

  for(i=0;i<1000000;i++){
    freq[i][0] = 0;
    freq[i][1] = 0;
  }

  long long int k,sum,count = 0;
  for(i=1;i<=n;i++){
    for(j=i;j<=n;j++){
      sum = S[j] - S[i-1];
      for(k=0;;k++){
	if(freq[k][0]){
	  if(freq[k][0] == sum){
	    freq[k][1]++;
	    break;
	  }
	}
	else{
	  freq[k][0] = sum;
	  freq[k][1]++;
	  count++;
	  break;
	}
      }
      //      freq[sum]++;
    }
  }
  printf("%lld\n",count-1);
  return 0;
}
