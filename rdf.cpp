#include <stdio.h>

double rdf(int n,int k);

int main()
{
  int t,n,k;
  double ans;
  scanf("%d",&t);
  while(t--)
    {
      scanf("%d%d",&n,&k);
      ans = rdf(n,k);
      printf("%f",ans);
    }
  return 0;
}

double rdf(int n, int k)
{
  int i;
  double ans;
  if(k==1)
    {
      ans = n*(n-1.0000000)/2.0000000;
    }
  if(n==0)
    {
      ans = 0.0000000;
    }
  if(n!=0&&k!=0)
    {
      for(i=1;i<=n-1;i++)
	{
	  ans += rdf(r,k-1);
	}
      ans /= n;
    }
  return ans;
}
