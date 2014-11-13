#include <stdio.h>

#define inf 1000000000
#define rep(i,n) for(i=0;i<n;i++)
#define gi(n) scanf("%d",&n)
#define pi(n) printf("%d",n)
#define fu(i,a,n) for(i=a;i<=n;i++)
#define fd(i,n,a) for(i=n;i>=a;i--)

int min(int a, int b){
	return (a<b?a:b);
}

int main(){
	int t,i,j;
		int n,m;
		gi(n);
		gi(m);
		
		int ar[n][m];
		int dupar[n][m];

		rep(i,n){
			rep(j,m){
				gi(ar[i][j]);
				dupar[i][j] = ar[i][j];
			}
		}

		int ld,up,rd;
		fu(i,1,n-1){
			rep(j,m){
				ld = rd = up = inf;
				if(i-1>=0 && j-1>=0)
					ld = ar[i][j]+dupar[i-1][j-1];
				if(i-1>=0 && j+1<m)
					rd = ar[i][j]+dupar[i-1][j+1];
				if(i-1>=0)
					up = ar[i][j]+dupar[i-1][j];

				dupar[i][j] = min(ld,min(rd,up));
			}
		}

		int ans = inf;
		rep(j,n)
			ans = min(ans,dupar[n-1][j]);
		pi(ans);
	return 0;
}