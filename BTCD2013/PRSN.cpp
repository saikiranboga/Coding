#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <cstring>
#include <cstdio>
using namespace std;

int memo[111][111];

vector<int> data;

int func(int leftIdx, int rightIdx) {
  // base case
  if (rightIdx - leftIdx < 2) {
    return 0;
  }
  if (memo[leftIdx][rightIdx] != -1) return memo[leftIdx][rightIdx];
  int res = 1<<30;
  for (int i = leftIdx+1; i < rightIdx; i++) {
    // split on monkey index i
    int calc = (data[i] - data[leftIdx] - 1) + (data[rightIdx] - data[i] - 1);
    calc = calc + func(leftIdx, i) + func(i, rightIdx);
    res = min(res,calc);
  }
  return memo[leftIdx][rightIdx] = res;
}

int main() {
  int N;
  //  cin >> N;
  scanf("%d",&N);
  while(N--){
    int P, Q;
    //    cin >> P >> Q;
    scanf("%d %d", &P, &Q);
    vector<int> pris;
    for (int i = 0; i < Q; i++) {
      int val;
      //      cin >> val;
      scanf("%d",&val);
      pris.push_back(val);
    }
    // add explicit barriers to the ends of the monkeys
    pris.push_back(0);
    pris.push_back(P+1);
    // ensure that the monkeys indexes are strictly increasing
    sort(pris.begin(),pris.end());
    data = pris;
    memset(memo,-1,sizeof(memo));
    int best = func(0, data.size()-1);
    //    cout << best << "\n";
    printf("%d\n",best);
  }
  return 0;
}
