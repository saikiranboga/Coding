#include <iostream>
#include <algorithm>

using namespace std;

int compare(const void *a, const void *b){
  return ( *(int*)a - *(int*)b);
}

int main(){
  int t,n,i;
  int weights[40],weight_lmts[40];
  cin >> t;
  while(t--){
    cin >> n;

    for(i=0; i<n; i++)
      cin >> weights[i];

    for(i=0; i<n; i++)
      cin >> weight_lmts[i];

    //    stable_sort(weights,weights+n);
    //    stable_sort(weight_lmts,weight_lmts+n);

    //    quickSort(weights,0,n);
    //    quickSort(weight_lmts,0,n);
    qsort(weights, n, sizeof(int), compare);
    qsort(weight_lmts, n, sizeof(int), compare);
    
    int i, idx = 0,res = 0;

    for(i=0; (i<n) && (idx < n); i++){
      while( (idx<n) && (weight_lmts[idx]<weights[i]) )
	idx++;
      if(idx < n){
	res++;
	idx++;
      }
    }
    cout << res << endl;
  }
  return 0;
}
