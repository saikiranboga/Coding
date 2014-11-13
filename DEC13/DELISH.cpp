/*
  Using dynamic programming, we find maxLeft[i] is the maximal value of the sum of consecutive numbers that are in the left of i (including i).
  minLeft, maxRight, minRight are defined in the similar way.

  the result is max(abs(maxRight[i+1] - minLeft[i]), abs(minRight[i+1] - minLeft[i]), abs(minRight[i+1] - maxLeft[i]), abs(minRight[i+1] - minLeft[i])) for all i;
*/

#pragma comment(linker, "/STACK:16777216")
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <memory.h>
#include <sstream>
#include <complex>

#define FOR(i,a,b) for (long long int i = (a), _b = (b); i <= _b; i++)
#define FORD(i,a,b) for (long long int i = (a), _b = (b); i >= _b; i--)

using namespace std;

long long int a[122222], n;
long long int minLeft[122222], maxLeft[122222], minRight[122222], maxRight[122222], SoftLeftMax[122222], SoftRightMax[122222];

int main() {
  long long int ntest, K;
  cin >> ntest;

  while (ntest--) {
    scanf("%d %d", &n, &K);
    FOR (i, 1, n)
      scanf("%d", a + i);

    maxLeft[1] = a[1];
    FOR (i, 2, n) {
      maxLeft[i] = max(maxLeft[i - 1] + a[i], (long long int) a[i]);
    }

    maxRight[n] = a[n];
    FORD (i, n - 1, 1) {
      maxRight[i] = max(maxRight[i + 1] + a[i], (long long int)  a[i]);
    }

    SoftLeftMax[1] = a[1];
    FOR (i, 2, n) {
      SoftLeftMax[i] = max((long long int) maxLeft[i], (long long int) SoftLeftMax[i-1]);
    }

    SoftRightMax[n] = a[n];
    FORD (i, n-1, 1) {
      SoftRightMax[i] = max((long long int)maxRight[i], (long long int)SoftRightMax[i+1]);
    }
    
    FOR (i, 1, n){
      cout <<  maxLeft[i] << " ";
    }
    cout << endl;

    FOR (i, 1, n){
      cout <<  maxRight[i] << " ";
    }
    cout << endl;

    FOR (i, 1, n){
      cout <<  SoftLeftMax[i] << " ";
    }
    cout << endl;

    FOR (i, 1, n){
      cout <<  SoftRightMax[i] << " ";
    }
    cout << endl;
    
    long long int res = -10000000000LL;

    FOR (i, 1, n-K-1) {
      /*
      res = max(res, abs(minLeft[i] - maxRight[i+ 1]));
      res = max(res, abs(minLeft[i] - minRight[i+ 1]));
      res = max(res, abs(maxLeft[i] - maxRight[i+ 1]));
      res = max(res, abs(maxLeft[i] - minRight[i+ 1]));
      */
      //      cout << SoftLeftMax[i] << " " << SoftRightMax[i+K+1] << endl;
      res = max(res, (SoftLeftMax[i] + SoftRightMax[i+K+1]));

    }

    cout << res << endl;
  }
  return 0;
}
