#include <stdio.h>
inline void mul(long long int mul1[2][2],long long int mul2[2][2]){
  long long int dst[2][2];
  dst[0][0] = (mul1[0][0]*mul2[0][0]+mul1[0][1]*mul2[1][0])% 1000000007;
  dst[0][1] = (mul1[0][0]*mul2[0][1]+mul1[0][1]*mul2[1][1])% 1000000007;
  dst[1][0] = (mul1[1][0]*mul2[0][0]+mul1[1][1]*mul2[1][0])% 1000000007;
  dst[1][1] = (mul1[1][0]*mul2[0][1]+mul1[1][1]*mul2[1][1])% 1000000007;
  mul1[0][0] = dst[0][0];
  mul1[1][0] = dst[1][0];
  mul1[0][1] = dst[0][1];
  mul1[1][1] = dst[1][1];
}
inline void power(long long int a[2][2],long long int n){
  long long int res[2][2] = {{1,1},{1,0}};
  if (n==1)
    return;
  power(a,n/2);
  mul(a,a);
  if(n%2 == 1)
    mul(a,res);
}
long long int a[2][2] = {{1,1},{1,0}};
long long int fi[2][1] = {{1},{1}};
int main(){
  long long int t;
  scanf("%lld",&t);
  //Base case that is f(2) = 3 and f(1) = 1
  while(t--){
    long long int a[2][2] = {{1,1},{1,0}};
    long long int n;
    scanf("%lld",&n);
    //Base cases
    if(n==1){
      printf("1\n");
      continue;
    }
    if(n==2){
      printf("1\n");
      continue;
    }
    a[0][0] = 1;a[0][1] = 1;a[1][0] = 1;a[1][1] = 0;
    printf("%lld\n",(fi[0][0]*a[0][0]+fi[1][0]*a[0][1])%1000000007);
  }
  return 0;
}
