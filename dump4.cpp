#include<iostream>
#include<cstdio>

using namespace std;

#define max 1000001

long long int a[max];

void add(long long int v,int long idx){
  while(idx<max){
    a[idx] += v;
    idx += (idx & -idx);
  }
}

long long int sum(int long idx){
  long long int s=0;
  while(idx>0){
    s += a[idx];
    idx -= (idx & -idx);
  }
  printf("%d\n",s);
  return s;
}

int main(){
  int t;
  scanf("%d",&t);
  for(long long int w=0;w<t;w++){
    long long int n;
    scanf("%lld",&n);

    for(long long int i=0;i<max;i++)
      a[i]=0;

    long long int arr[n];
    for(long long int i=0;i<n;i++)
      scanf("%lld",&arr[i]);

    long long int res=0;

    for(long long int i=0;i<n;i++){
      if(arr[i]!=0){
	add(arr[i],arr[i]);
	res += (sum(arr[i]-1));
      }  
    }

    printf("%lld\n",res);
  }

  return 0;
}
