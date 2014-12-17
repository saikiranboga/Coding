#include <bits/stdc++.h>
#include <string.h>
using namespace std;

#define inf 1000000000
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define sz size()
#define VI vector<int>
#define PII pair<int, int>
#define all(v) (v.begin(), v.end())
#define ll long long int

int main(){
	LL n, x, y;
	cin >> n >> x >> y;
	LL ai;
	for (int i = 0; i < n; ++i) {
		cin >> ai;
		LL l = 0, r = inf;
		LL mid, mid_val;
		while(r-l != 1){
			mid = (l+r)/2;
			mid_val = mid*(x+y);
			if(ai > mid_val)
				l = mid+1;
			else
				r = mid;
		}
		LL rem = ai - l*(x+y);
		LL lt = 0,rt = 1000000;
		LL md;
		LL comp = 1;
		while(rem != 1){
			
		}
	}
	return 0;
}