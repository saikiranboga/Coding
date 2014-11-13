#include <iostream>

using namespace std;
 
char sa[100000], sb[100000];
int cnt[41][41][41];
 
bool ok(int sz, int n, int P)
{
  for(int i=1; i<=n-sz+1; i++)
    for(int j=1; j<=n-sz+1; j++)
      for(int k=1; k<=n-sz+1; k++)
	{
	  int p = i+sz-1, q = j+sz-1, r = k+sz-1;
	  int c = cnt[p][q][r]-cnt[p][j-1][r]-cnt[p][q][k-1]-cnt[i-1][q][r]+cnt[i-1][j-1][r]+cnt[i-1][q][k-1]+cnt[p][j-1][k-1]-cnt[i-1][j-1][k-1];
	  if(c*100 >= P*sz*sz*sz)
	    return 1;
	}
  return 0;
}
 
int main()
{
  int t;
  cin >> t;
  while(t--)
    {
      int n, P;
      cin >> n >> P >> sa >> sb;
      for(int i=1; i<=n; i++)
	for(int j=1; j<=n; j++)
	  for(int k=1; k<=n; k++)
	    cnt[i][j][k] = 0;
      for(int i=1; i<=n; i++)
	for(int j=1; j<=n; j++)
	  for(int k=1; k<=n; k++)
	    cnt[i][j][k] = (sa[(i-1)*n*n+(j-1)*n+k-1] == sb[(i-1)*n*n+(j-1)*n+k-1] ? 1 : 0);
      for(int i=1; i<=n; i++)
	for(int j=1; j<=n; j++)
	  for(int k=1; k<=n; k++)
	    cnt[i][j][k] += cnt[i][j-1][k];
      for(int i=1; i<=n; i++)
	for(int j=1; j<=n; j++)
	  for(int k=1; k<=n; k++)
	    cnt[i][j][k] += cnt[i-1][j][k];
      for(int i=1; i<=n; i++)
	for(int j=1; j<=n; j++)
	  for(int k=1; k<=n; k++)
	    cnt[i][j][k] += cnt[i][j][k-1];
      int lo = 1, hi = n, sz = -1;
      while(lo <= hi)
	{
	  if(ok(hi, n, P))
	    {
	      sz = hi;
	      break;
	    }
	  hi--;
	}
      if(sz < 0)
	{
	  cout << -1 << '\n';
	  continue;
	}
      int ct = 0;
      for(int i=1; i<=n-sz+1; i++)
	for(int j=1; j<=n-sz+1; j++)
	  for(int k=1; k<=n-sz+1; k++)
	    {
	      int p = i+sz-1, q = j+sz-1, r = k+sz-1;
	      int c = cnt[p][q][r]-cnt[p][j-1][r]-cnt[p][q][k-1]-cnt[i-1][q][r]+cnt[i-1][j-1][r]+cnt[i-1][q][k-1]+cnt[p][j-1][k-1]-cnt[i-1][j-1][k-1];
	      if(c*100 >= P*sz*sz*sz)
		ct++;
	    }
      cout << sz << " " << ct << '\n';
    }
  return 0;
} 
