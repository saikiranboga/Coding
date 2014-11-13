#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
using namespace std;

#define MAXN 100005

int n,m,k,a[MAXN],x[MAXN],y[MAXN],l[MAXN],r[MAXN],ans[MAXN];

multimap<int,int> lr;

struct baloon_box{
  int idx;
  int next;
  int prev;
  int count;
} baloon_boxes[MAXN];

baloon_box put_baloons(int idx){
  baloon_box res;
  res.idx = idx;
  res.count = a[idx];
  res.next = idx + 1;
  res.prev = idx - 1;
  return res;
}

int find_intervals(int ll, int rr){
  int count = 0;
  multimap<int,int>::iterator it,left,right;
  left = lr.lower_bound(ll);
  right = lr.upper_bound(rr);
  for(it = left; it != right; it++){
    if((*it).second <= rr)
      count++;
  }
  return count;
}

int burst_baloon(int idx){
  int ll,rr;
  baloon_boxes[idx].count--;
  if(baloon_boxes[idx].count == 0){
    rr = baloon_boxes[baloon_boxes[idx].prev].next = baloon_boxes[idx].next;
    ll = baloon_boxes[baloon_boxes[idx].next].prev = baloon_boxes[idx].prev;
    rr--;
    ll++;
    return find_intervals(ll, rr)-find_intervals(ll,idx-1)-find_intervals(idx+1, rr);
  }
  return 0;
}

int main(){
  int i;
  scanf("%d %d",&n,&m);
  for(i=1;i<=n;i++){
    scanf("%d",&a[i]);
    baloon_boxes[i] = put_baloons(i);
  }
  for(i=0;i<m;i++){
    scanf("%d %d",&l[i],&r[i]);
    lr.insert(make_pair(l[i],r[i]));
  }

  scanf("%d",&k);
  for(i=1;i<=k;i++)
    scanf("%d",&x[i]);  

  ans[0] = 0;

  for(i=1;i<=k;i++){
    y[i] = x[i] + ans[i-1];
    ans[i] = ans[i-1] + burst_baloon(y[i]);
    printf("%d\n",ans[i]);
  }
  return 0;
}
