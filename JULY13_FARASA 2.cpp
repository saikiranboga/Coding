#include <iostream>
#include <stdio.h>
#include <map>
using namespace std;

map<long long int,int> freq;

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
  //  if(n*S[n]  2*100000){
  long long int k,check,sum,count = 0;
  for(i=1;i<=n;i++){
    for(j=i;j<=n;j++){
      sum = S[j] - S[i-1];
      if(freq.count(sum)){
      }
      else{
	freq[sum]++;
	count++;
      }
    }
  }
  printf("%lld\n",count-1);
/*
  else{
  long long int tmp;
  long long int val,ans,count=0;
  for(j=1;j<=S[n];j++){
  map<long long int,int>list;
  list[0]++;
  ans = 0;
  for(i=1;i<=n;i++){
  if(list.count(S[i]-j)){
  val = list[S[i]-j];
  ans += val;
  }
  list[S[i]]++;
  }
  if(ans != 0)
  count++;
  }
  printf("%d\n",count-1);

  }
*/
return 0;
}
