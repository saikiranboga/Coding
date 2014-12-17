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
	int n;
	cin >> n;
	int h[n];
	for (int i = 0; i < n; ++i)
		cin >> h[i];

	int ar[n-2][n-1];
	for(int i=1; i<n-1; i++) {
		for (int j = 0, id = 0; j < n; j++) {
			if(i!=j){
				ar[i-1][id] = h[j];
				id++;
			}
		}
	}
	// for (int i = 0; i < n-2; ++i)
	// {
	// 	for (int j = 0; j < n-1; ++j)
	// 	{
	// 		cout << ar[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }
	int ans = 100000;
	for (int i = 1; i < n-1; ++i) {
		int d = -1;
		for (int j = 1; j < n-1; ++j) {
			if(ar[i-1][j]-ar[i-1][j-1] > d)
				d = ar[i-1][j]-ar[i-1][j-1];
		}
		if(d < ans)
			ans = d;
	}
	cout << ans << endl;
	return 0;
}