#include<stdio.h>
#include<iostream>
using namespace std;
int orientation(int x1,int y1,int x2,int y2,int x3,int y3)
{

	int val = (y2 - y1) * (x3 - x2) -
			  (x2 - x1) * (y3 - y2);

	if (val == 0) return 0;

	return (val > 0)? 1: 2;
}

int doIntersect(int x1,int y1, int x2,int y2, int x3,int y3, int x4 ,int y4)
{
	int o1 = orientation(x1,y1, x2,y2,x3,y3);
	int o2 = orientation(x1,y1, x2,y2,x4,y4);
	int o3 = orientation(x3,y3, x4,y4,x1,y1);
	int o4 = orientation(x3,y3, x4,y4,x2,y2);
	if (o1 != o2 && o3 != o4)return 1;
	return 0;
}



int main(){
	int t,n,m,i,j,k,v,b,x[55],y[55];
	char a[55][55];
	int deg[55]={0};
	cin>>n;
	for(i=0;i<n;++i)
		cin>>x[i]>>y[i];

	string s;

	for(i=0;i<n;++i){
		cin >> s;
		for(j=0;j<n;j++)
			a[i][j] = s[j];
	}
	
	for(i=0;i<n;++i)
		for(j=0;j<n;++j)
			if(a[i][j]=='Y')
				++deg[i];

	k = -1;
	int min=51, g[2500][50]={-1}, ctr[59]={0}, po;

	while(min<100){
		int vis[51] = {0};
		min = 100;
		for(i=0;i<n;++i)
			if(deg[i]&&deg[i]<min){
				min=deg[i];
				po=i;
			}

		vis[po]=1;
		if(min==100)
			break;
		int h = 1;
		k++;
		while(h){
			h=0;
			int o;
			g[k][ctr[k]]=po;
			ctr[k]++;
			for(i=0;i<n;++i){
				if(a[po][i]=='Y'&&vis[i]==0){
					for(o=0;o<ctr[k]-2;++o)
						if(doIntersect(x[g[k][o]],y[g[k][o]],x[g[k][o+1]],y[g[k][o+1]],x[po],y[po],x[i],y[i]))
							break;
						if(o==ctr[k]-1)	
							vis[i]=1;
						h=1;
						a[po][i]='N';
						a[i][po]='N';
						deg[po]--;
						deg[i]--;
						po=i;
				}
				if(h)
					break;
			}
			if(!h){
				g[k][ctr[k]] = po;
				ctr[k]++;
			}
		}
	}
	printf("%d\n",k+1);
	for(i=0;i<=k;++i){
		printf("%d ",ctr[i]-2);
		for(j=0;j<ctr[i]-2;++j)
			printf("%d ",g[i][j]);
		printf("%d",g[i][j]);
		printf("\n");
	}
	return 0;
}