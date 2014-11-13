#include<stdio.h>
int a[10000000],b[10000000];
void Eratosthenes(int n,int a[],int b[])
{
  printf("in ");
  int i,j,p;
  a[0] = 0;
  if(n > 10000000){
    for(i=1; i<10000000; i++){
      a[i] = 1;
    }
    for(i=0; i<(n-10000000); i++){
      b[i] = 1;
    }
  }
  else{
    for(i=1; i<n; i++){
      a[i] = 1;
    }
  }
  p = 2;
  while((p*p) <= n){
    j = p*p;
    while(j <= n){
      if(j > 10000000)
	b[j-10000001] = 0;
      else
	a[j-1] = 0;
      j += p;
    }
    p++;
    if(p > 10000000){
      while(b[p-10000001] != 1){
	p++;
      }
    }
    else{
      while(a[p-1] != 1){
	p++;
      }
    }
  }
}
int main()
{
  int t,i,j;
  int m,n;
  scanf("%d",&t);
  for(i=0; i<t; i++){
    scanf("%d",&m);
    scanf("%d",&n);
    Eratosthenes(n,a,b);
    for(j=m; j<=n; j++){
      if(j>10000000){
	if(b[j-10000001] == 1){
	  printf("%d\n",j+1);
	}
      }
      else{
	if(a[j] == 1){
	  printf("%d\n",j+1);
	}
      }
    }
  }
  return 0;
}





