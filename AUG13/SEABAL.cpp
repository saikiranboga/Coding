#include <iostream>
#include <stdio.h>

using namespace std;

struct node {
  int l;
  int r;
};


void quickSort(node arr[], int v[], int low, int high){
  int i = low;
  int j = high;
  int tmp;
  node y;
  int z = arr[(low + high) / 2].l;
  do {
    while(arr[i].l < z) i++;
    while(arr[j].l > z) j--;
    if(i <= j) {
      y = arr[i];
      arr[i] = arr[j];
      arr[j] = y;

      tmp = v[i];
      v[i] = v[j];
      v[j] = tmp;

      i++;
      j--;
    }
  } while(i <= j);
  if(low < j)
    quickSort(arr, v, low, j);
  if(i < high)
    quickSort(arr, v, i, high);
} 


int main(){
  int n, m;
  cin >> n >> m;
  int a[n+1];
  int v1[n+1];
  int v[m+1];
  node r[m+1];
  v1[0] = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    v1[i] = a[i]+v1[i-1];
  }
	
  for (int i = 1; i <= m; i++) {
    cin >> r[i].l;
    cin >> r[i].r;
    v[i] = v1[r[i].r] - v1[r[i].l-1];
  }
  int ans[100001];
  ans[0] = 0;	
  quickSort(r,v,1,m);
		
  int p,k;
  cin >> k;
  int res = 0;

  res = 0;
  for (int i = 0; i < k; i++) {
    cin >> p;
    p += ans[i];
    int j = m/2;
    if(m>1){
      while(r[j].l > p){
	j /= 2;
      }
    }
    if(j == 0)
      j = 1;
    if(m > j){
      while( (j+1 <= m) && (r[j+1].l <= p) ){
	j++;
      }
    }
    while (j >= 1) {
      if (p <= r[j].r) {
	if(v[j]){
	  v[j]--;
	  if(!v[j])
	    res++;
	}				
      }
      j--;
    }
    cout << res << endl;
    ans[i+1] = res;
		
  }
	
  return 0;
}
