int X(a,b){return a>b?a:b;}
#define f(i,n) for(i=1;i<=n;i++)
#define g(n) scanf("%d",&n)
int main(){int t,n,i,j,x,c,m[101][101],a;g(t);f(c,t){a=0;g(n);f(i,n)f(j,i)g(m[i][j]),a=X(m[i][j]+=X(m[i-1][j-1],m[i-1][j]),a);printf("%d\n",a);}return 0;}