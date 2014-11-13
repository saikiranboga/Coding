#define X(a,b) (a>b?a:b)
#define f(i,a,n) for(int i=a;i<n;i++)
#define g(n) scanf("%d",&n)
int t,n,a,m[1010][1010];
main(){
	g(t);
	f(c,0,t){
		g(n);
		f(i,0,n)
			f(j,0,i+1)
				g(m[i][j]);
		f(i,1,n){
			m[i][0]+=m[i-1][0];
			f(j,1,i)
				m[i][j]+=X(m[i-1][j-1],m[i-1][j]);
			m[i][i]+=m[i-1][i-1];
		}
		a=0;
		f(j,0,n)
			a=X(a,m[n-1][j]);
		printf("%d\n",a);
	}
}