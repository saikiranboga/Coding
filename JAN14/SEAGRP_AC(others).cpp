#include <iostream>
#include<stdio.h>
using namespace std;
int a[105][105],visited[105];
{
	if(count==0)
		return true;
	int i,j,k;
	for(i=0;i<n;i++)
	{
		if(visited[i]==0)
		{
			for(j=0;j<n;j++)
			{
				if(a[i][j]==1 && visited[j]==0)
				{
					visited[i]=1;
					visited[j]=1;
				//	printf("%d %d\n",i,j);
					if(check(n,count-2))
						return true;
					else
					{
						visited[i]=0;
						visited[j]=0;
					}
				}
			}
			if(j==n)
				return false;
		}
	}
	return false;
	
}
int main() 
{

	int i,j,k,n,m,x,y,t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		/*if(n%2)
		{
			printf("NO\n");
			continue;
		}*/
		for(i=0;i<=n;i++)
		{
			visited[i]=0;
			for(j=0;j<=n;j++)
				a[i][j]=0;
		}
		for(i=0;i<m;i++)
		{
			scanf("%d%d",&x,&y);
			a[x-1][y-1]=1;
			a[y-1][x-1]=1;
		}
		if(check(n,n))
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}