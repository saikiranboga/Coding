#include <bits/stdc++.h>
using namespace std;

#define LL long long int

int A[200010];
int TMP[200010];
int n;

LL merge(int st, int mid, int ed){
	int i = st;
	int j = mid+1;
	int k = 0;
	LL count = 0;
	while(i<=mid || j<=ed){
		if(i>mid)
			TMP[k++] = A[j++];
		else if(j>ed)
			TMP[k++] = A[i++];
		else{
			if(A[j]<A[i]){
				count += (mid-i+1);
				TMP[k++] = A[j++];
			}
			else
				TMP[k++] = A[i++];
		}
	}
	for(i=0; i<k;i++)
		A[i+st] = TMP[i];
	return count;
}

LL solve(int st, int ed){
	if(st==ed || st>ed)
		return 0;

	int mid = (st+ed) / 2;
	LL lc = solve(st, mid); // left inversions
	LL rc = solve(mid+1, ed); // right inversions
	LL mc = merge(st, mid, ed); // merge inversions
	return (lc+rc+mc);
}

int main(){
	int t;
	cin >> t;
	string s;
	
	while(t--){
		map<string, int> mp;
		vector<string> yoda;
		cin >> n;
		for(int i=1;i<=n;i++){
			cin >> s;
			yoda.push_back(s);
		}

		for(int i=1;i<=n;i++){
			cin >> s;
			mp[s] = i;
		}
		for(int i=0;i<n;i++){
			A[i+1] = mp[ yoda[i] ];
		}
		cout << solve(1,n) << endl;
	}
	return 0;
}