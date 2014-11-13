#include <stdio.h>

long double fact( int p)
{
 long double facts = 1;
 int i;
 for( i = 1; i<= p; i++)
  facts = facts * i;
 return( facts);
}
 
int ncr ( int n, int r)
{
 return( fact( n) / (fact( r) * fact(n- r) ) ) ;
}


int main()
{
  int t,n,k,i;
  int x,y;
  long long int sum = 0;
  long long int num;
  scanf("%d",&t);
  while(t--){
    scanf("%d",&n);
    for(i=0;i<=n;i++){
      x  = ncr(n,i);
      y = ncr(n+i,i);
      sum += x*y;
    }
    num = sum%(n*n);
    printf("%lld",num);
  }
  return 0;
}
