#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define MAX 100000
#define lower 0
#define upper 1

vector<int> pos[MAX+1];
vector<int> divs[MAX+1];
int a[MAX+1];

int bound(int val, int l, int r, int k, int bnd){
  int m;
  while(l <= r){
    m = (l+r)/2;
    if(pos[k][m] == val)
      return m;
    else if(pos[k][m] > val)
      r = m-1;
    else
      l = m+1;
  }
  return m;
}

int main(){
  int i,j,k,n,q,d,l,r;

  for(i=1;i<=MAX;i++)
    for(j=i;j<=MAX;j += i)
      divs[j].push_back(i);

  cin >> n >> q;

  for(i=1;i<=n;i++){
    cin >> a[i];
    int sz = divs[a[i]].size();
    for(j=0;j<sz;j++){
      d = divs[a[i]][j];
      pos[ d ].push_back(i);
    }
  }

  for(i=1;i<=q;i++){
    cin >> l >> r >> k;
    if(pos[k].size() != 0){
      //      cout << upper_bound(pos[k].begin(),pos[k].end(),r) - lower_bound(pos[k].begin(),pos[k].end(),l) << endl;
      int left = bound(l, 0, pos[k].size()-1, k, lower);
      int right = bound(r, 0, pos[k].size()-1, k, upper);
      if(pos[k][left]>=l && pos[k][right]<=r)
	cout << (right-left+1) << endl;
      else if( (pos[k][left]>=l && pos[k][right]>r) || ( pos[k][left]<l && pos[k][right]<=r) )
	cout << (right-left) << endl;
      else
	cout << (right-left-1) << endl;      
    }
    else{
      cout << 0 << endl;
    }
  }
  return 0;
}
