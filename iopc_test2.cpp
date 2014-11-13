#include<stdio.h>
#include<iostream>
using namespace std;
#include<vector>

/* This function calculates power of p in n! */
long long int countFact(long long int n, long long int p)
{
  long long int k=0;
  while (n>=p)
    {
      k+=n/p;
      n/=p;
    }
  return k;
}

/* This function calculates (a^b)%MOD */
long long int pow(long long int a, long long int b, long long int MOD)
{
  long long int x=1,y=a; 
  while(b > 0)
    {
      if(b%2 == 1)
	{
	  x=(x*y);
	  if(x>MOD) x%=MOD;
	}
      y = (y*y);
      if(y>MOD) y%=MOD; 
      b /= 2;
    }
  return x;
}

long long int factMOD(long long int n, long long int MOD)
{
  long long int res = 1; 
  while (n > 0)
    {
      for (long long int i=2, m=n%MOD; i<=m; i++)
	res = (res * i) % MOD;
      if ((n/=MOD)%2 > 0) 
	res = MOD - res;
    }
  return res;
}

long long int C(long long int n, long long int MOD)
{
  return (factMOD(n, MOD)) % MOD;
}

int main()
{    
  long long int n,p,t;
  scanf("%lld",&t);
  while (t--)
    {
      scanf("%lld %lld",&n,&p);
      printf("%lld\n",C(n,p));
    }
  return 0;
}
