#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
 
bool inp[1005][1005];
int n,m;
int k,q;
int hist[1005][1005];
int mini[1005];		// read (min height on row)
int maxi[1005];		// read (max height on row)
int all[1005][1005];		// read (row, max histogram area given height)
int areas[1005];
int dp[1005][1005];
bool glob=0;
// returns (from,to)
pair<int,int> recurse(int *a,int *res,int size)
{
	if(size<=1)
	{
		res[a[0]] = a[0];
		return make_pair(a[0],a[0]);
	}
	int i,least=10000,ind=-1;
	int lol=-1,hil=-1,lor=-1,hir=-1;
	pair<int,int> ans;
 
	for(i=0;i<size;i++)
	if(a[i]<least)
	{	
		least = a[i];
		ind = i;
	}
	int left[n+1],right[n+1];
	if(ind>0)
	{
		ans = recurse(a,left,ind);
		lol = ans.first;
		hil = ans.second;
	}
	if(ind+1<size)
	{
		ans = recurse(a+ind+1,right,(size-ind-1));
		lor = ans.first;
		hir = ans.second;
	}
	for(i=least;i<=max(hil,hir);i++)
	{
		res[i] = least*size;
		// Possible from left
		if(lol!=-1)
		{	if(i<=lol) res[i] = max(res[i],i*ind);
			else if(i<=hil) res[i] = max(res[i],left[i]);
			else if(i>hil) res[i] = max(res[i],left[hil]);
		}
		// Possible from right
		if(lor!=-1)
		{	if(i<=lor) res[i] = max(res[i],i*(size-ind-1));
			else if(i<=hir) res[i] = max(res[i],right[i]);
			else if(i>hir) res[i] = max(res[i],right[hir]);
		}
	}
	return make_pair(least,max(hil,hir));
}
void preprocess()
{
	int i,j;
	for(i=1;i<=m;i++)
		hist[0][i-1]=((inp[1][i]==0)?1:0);
	for(i=1;i<n;i++)
	for(j=0;j<m;j++)
	{
		if(!inp[i+1][j+1])
			hist[i][j]=hist[i-1][j]+1;
		else hist[i][j]=0;
	}
	int resultarr[n+1];
	pair<int,int > ans;
	for(i=1;i<=n;i++)
	{
		ans = recurse(hist[i-1],resultarr,m);
		mini[i-1] = ans.first;
		maxi[i-1] = ans.second;
		for(j=mini[i-1];j<=maxi[i-1];j++)
			all[i-1][j] = resultarr[j];
	}
}
void solve()
{
	int i,j;
	memset(dp,0,1005*1005*sizeof(int));
	for(i=0;i<n;i++)
	{
 
		if(maxi[i]==0)dp[i][i]=0;
		else if(mini[i]==1)
			dp[i][i]=m;
		else dp[i][i] = all[i][1];
 
		for(j=i+1;j<n;j++)
		{
			dp[i][j] = dp[i][j-1];
			if(maxi[j]<=(j-i+1))
				dp[i][j] = max(dp[i][j],all[j][maxi[j]]);
			else if(mini[j]>=(j-i+1))
				dp[i][j] = max(dp[i][j],(j-i+1)*m);
			else dp[i][j] = max(dp[i][j],all[j][(j-1+1)]);
		}
	}
}
int main()
{
	int i,j;
	memset(inp,0,1005*1005);
	scanf("%d",&n);
	scanf("%d",&m);
	scanf("%d",&k);
	int u,v;
	for(i=0;i<k;i++)
	{
		scanf("%d %d",&u, &v);
		inp[u][v]=1;
	}
	preprocess();
	solve();
 
	/*for(i=0;i<n;i++)
	{for(j=0;j<m;j++)cout<<hist[i][j]<<" ";cout<<endl;}
	cout<<endl;
	for(i=0;i<n;i++)
	{for(j=0;j<=n;j++)cout<<dp[i][j]<<" ";cout<<endl;}
	cout<<endl;*/
	//cout<<"Computed\n";
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d %d",&u, &v);
		printf("%d\n",dp[u-1][v-1]);
	}
	return 0;
}