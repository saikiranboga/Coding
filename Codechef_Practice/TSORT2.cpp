#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int main(){
  int t,n;
  scanf("%d",&t);

  int *a = new int[1000001];
  memset(a,0,1000001*sizeof(int));
  for(register int i=0;i<t;i++){
    scanf("%d",&n);
    a[n]++;
  }
  for(register int i=0;i<1000001;i++){
    for(register int j=1;j <= a[i];j++)
      printf("%d\n",i);
  }
  return 0;
}
