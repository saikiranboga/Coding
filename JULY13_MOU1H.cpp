#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <stdio.h>
using namespace std;

struct entry { long long int nr[2], p; };
const int MAXN = 100024, MAXLG = 25;

entry L[MAXN];
long long int P[MAXLG][MAXN], N, stp, cnt, S[MAXN];
char A[MAXN];

long long int cmp(struct entry a, struct entry b) {
  return a.nr[0] == b.nr[0] ? (a.nr[1] < b.nr[1] ? 1 : 0) : (a.nr[0] < b.nr[0] ? 1 : 0);
}

long long int lcp(long long int x, long long int y) {
  long long int k, ret = 0;
  if(x < 0 || y < 0) return 0;
  if(x == y) return N - x;
  for(k = stp - 1; k >= 0 && x < N && y < N; k--)
    if(P[k][x] == P[k][y])
      x += 1 << k, y += 1 << k, ret += 1 << k;
  return ret;
}

int main() {
  long long int i, t, n;
  long long int tot;
  char mn;
  scanf("%lld",&t);
  while(t--) {
    scanf("%lld",&n);
    char c;
    long long int temp;
    long long int hts[100010];
    for(i = 0; i < n; i++){
      scanf("%lld",&hts[i]);
    }
    if(n != 1){
      for(i = 0; i < n-1; i++){
	c = hts[i+1]-hts[i];
	A[i] = c;
      }
      mn = 1000010;
      for(i = 0; i < n-1; i++)
	mn = min(mn, A[i]);
      for(i = 0; i < n-1; i++)
	P[0][i] = A[i] - mn;
      N = i;
      for(stp = 1, cnt = 1; (cnt >> 1) < N; stp++, cnt <<= 1) {
	for(i = 0; i < N; i++) {
	  L[i].nr[0] = P[stp - 1][i];
	  L[i].nr[1] = i + cnt < N ? P[stp - 1][i + cnt] : -1;
	  L[i].p = i;
	}
	sort(L, L + N, cmp);
	for(i = 0; i < N; i++) {
	  P[stp][L[i].p] = (i>0 && L[i].nr[0]==L[i-1].nr[0] && L[i].nr[1]==L[i-1].nr[1])? P[stp][L[i-1].p] : i;
	}
      }
      for(i = 0; i < N; i++) S[P[stp-1][i]] = i;
      tot = N - L[0].p;
      for(i = 1; i < N; i++) {
	tot += N - L[i].p - lcp(S[i-1], S[i]);
      }

      printf("%lld\n", (tot%1000000009));
    }
    else{
      printf("0\n");
    }
  }
  return 0;
}
