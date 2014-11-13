#include <stdio.h>
#include <algorithm>
using namespace std;

int compare(const void *a, const void *b){
  return ( *(int*)a - *(int*)b);
}

int main(){
  int t,n,i,j,k;
  scanf("%d",&n);
  while(n){
    int l[n];
    for(i=0;i<n;i++)
      scanf("%d",&l[i]);
    qsort(l,n,sizeof(int),compare);
    int chk,low,high,mid;
    int ans = 0;
    for(i=0;i<n-1;i++)
      for(j=i+1;j<n;j++){
	chk = l[i] + l[j];
	low = j+1;
	high = n-1;
	while(low <= high){
	  mid = (low+high)/2;
	  if(chk < l[mid])
	    high = mid-1;
	  else
	    low = mid+1;
	}
	ans += (n-low);
      }
    printf("%d\n",ans);
    scanf("%d",&n);
  }
  return 0;
}
