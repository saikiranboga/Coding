#include <cstdio>
#include <algorithm>
using namespace std;

int i,j,n,m,a[2001][2001],c[2001],last;
long long ret;
int main(){
  scanf("%d%d\n",&n,&m);
  for(i=1;i<=n;i++){
    for(j=1;j<=m;j++)
      a[i][j] = getchar()-'0';
    getchar();
  }

  for(i=n;i;i--){
    for(j=1;j<=m;j++){
      if(a[i][j]) c[j]++; else	c[j] = 0;
      //      printf("%d ",c[j]);
    }

    //    printf("\n");
    for(j=1,last=0;j<=m;j++){
      ret += last = min(last+1,c[j]);
    }
  }

  printf("%lld\n",ret);

  return 0;
}
