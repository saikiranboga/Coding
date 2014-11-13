#include<stdio.h>
#include<math.h>
#define MAX 100.0

int main()
{
  int p,q,t;
  scanf("%d",&t);
  while(t--){
    int visited[252]={0};float min,mincost=0;
    float cost[252][252];
    float nearest;
    int a,b,u,v,n,m,i,j,ne=1;
    scanf("%d",&n);
    scanf("%d",&m);
    for(i=1;i<=n;i++)
      for(j=1;j<=n;j++)
	cost[i][j] = MAX;   
    for(j=1;j<=m;j++)
      {
	scanf("%d%d",&p,&q);
	scanf("%f",&cost[p][q]);
	cost[q][p] = cost[p][q];
      }
    visited[1]=1;
    while(ne<n)
      {
	for(i=1,min=100.0;i<=n;i++)
	  for(j=1;j<=n;j++)
	    if(cost[i][j]<min){
	      if(visited[i]!=0) {
		min=cost[i][j];
		a=u=i;
		b=v=j;
	      }
	    }
	if(visited[u]==0 || visited[v]==0)
	  {
	    ne++;
	    mincost+=min;
	    visited[b]=1;
	  }
	cost[a][b]=cost[b][a]=100.0;
      }
    nearest = ceilf(mincost * 100) / 100;  
    printf("%.2f\n",nearest);
  }
  return 0;
}
