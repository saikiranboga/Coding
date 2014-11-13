#include <stdio.h>
#include <string.h>

#define max(a,b) (a>b?a:b)
#define rep(i,n) for(i=0;i<n;i++)
#define fu(i,a,n) for(i=a;i<=n;i++)
#define fd(i,n,a) for(i=n;i>=a;i--)

#define gi(n) scanf("%d\n",&n)
#define pi(n) printf("%d",n)

char labyr[1001][1001];
int vis[1001][1001];
int r,c;

int mx,i,j;

int dfs(int x, int y, int len){
	int up, down, left, right;
	up = down = left = right = len;
	if(x-1>=0 && labyr[x-1][y]=='.' && !vis[x-1][y]){
		vis[x-1][y] = 1;
		up += dfs(x-1,y,len+1);
	}

	if(x+1<r && labyr[x+1][y]=='.' && !vis[x+1][y]){
		vis[x+1][y] = 1;
		down += dfs(x+1,y,len+1);
	}
	
	if(y-1>=0 && labyr[x][y-1]=='.' && !vis[x][y-1]){
		vis[x][y-1] = 1;
		left += dfs(x,y-1,len+1);
	}
	
	if(y+1<c && labyr[x][y+1]=='.' && !vis[x][y+1]){
		vis[x][y+1] = 1;
		right += dfs(x,y+1,len+1);
	}

	int mx1 = max(up,max(down,max(left,right)));
	if(up==mx1)
		up = 0;
	else if(down==mx1)
		down = 0;
	else if(left==mx1)
		left = 0;
	else if(right==mx1)
		right = 0;
	int mx2 = max(up,max(down,max(left,right)));
	mx1 -= len;
	mx2 -= len;

	if(mx1+mx2>mx)
		mx = mx1+mx2;

	if(mx1+len > mx)
		mx = mx1+len;
	return mx1+1;
}

int main(){

	int t,len;
	gi(t);
	char s[1010];
	while(t--){
		gi(c);
		gi(r);
		
		rep(i,r){
			scanf("%s",&s);
			rep(j,c){
				labyr[i][j] = s[j];
			}
		}

		memset(vis,0,sizeof(vis));

		mx = 0;

		rep(i,r){
			rep(j,c){
				if(labyr[i][j]=='.' && !vis[i][j]){
					vis[i][j] = 1;
					dfs(i,j, 0);
				}
			}
		}
		printf("Maximum rope length is %d.\n",mx);
	}
	return 0;
}