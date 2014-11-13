#include <iostream>
#include <algorithm>
using namespace std;

int compare(const void *a, const void *b){
  return ( *(int*)a - *(int*)b);
}

int main(){
  int i,j,n,n1,n2,n3,num;
  cin >> n1 >> n2 >> n3;
  n = n1+n2+n3;
  int ar[n];
  int ans[n];
  for(i=0; i<n;i++)
    cin >> ar[i];
  qsort(ar, n, sizeof(int), compare);

  int idx = 0;

  for(i=0; i<n;){
    num = ar[i];
    j = i+1;
    while(j<n && ar[j] == num)
      j++;
    if( (j-i) >= 2)
      ans[idx++] = ar[i];    
    i = j;     
  }
  cout << idx << endl;
  for(i=0;i<idx;i++)
    cout << ans[i] << endl;
}
