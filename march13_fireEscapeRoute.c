#include<stdio.h>
#define MOD 1000000007
int a[100002];

int main()
{
  int t, i, j, k,n, m, p, q, count, temp;
  int b[100002];
  scanf("%d", &t);
  for(i=0; i<t; i++){
    scanf("%d %d", &n, &m);
    for(j=0; j<=n; j++){
      a[j]=j;
      b[j]=0;
    }
    int c_g = 0;
    for(j=0; j<m; j++){
      scanf("%d%d", &p, &q);
      while(1){
	if(a[p]==p){
	  a[p]=a[q];
	  break;
	}
	else{
	  temp=a[p];
	  a[p]=a[q];
	  p=temp;
	}	
      }
    }
    count=0;
    int mul=1;
    for(j=1; j<=n; j++){
      if(a[j]==j){
	count++;
      }
    }

    mul = mul%MOD;
    printf("%d %d\n", count,mul);
  }
  return 0;
} 
