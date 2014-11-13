#include<stdio.h>
#include<map>

using namespace std;

int main(){
  int t,i;
  scanf("%d",&t);
  while(t--){
    map<long long int,int>list;
    long long int n;
    scanf("%lld",&n);
    long long int tmp;
    long long int sum[n+1];
    sum[0] = 0;
    list[0]++;
    long long int ans=0,val;
    for(i=1;i<=n;i++){
      scanf("%lld",&tmp);
      sum[i]=tmp+sum[i-1];
      if(list.count(sum[i]-47)){
	val = list[sum[i]-47];
	ans += val;
      }
      list[sum[i]]++;
    }
    printf("%lld\n",ans);
 }
}
