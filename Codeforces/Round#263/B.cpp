#include <bits/stdc++.h>
using namespace std;

#define LL long long int
#define inf 1000000000
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define VI vector<int>
#define PII pair<int, int>
#define all(v) (v.begin(), v.end())

int main(){
	LL n, k;
	cin >> n >> k;
	LL A[26];
	memset(A, 0, sizeof(A));
	char c;
	for(int i=0;i<n;i++){
		cin >> c;
		A[(int)(c-'A')]++;
	}
	sort(A, A+26);
	LL ans = 0;
	LL rem = k;
	for(int i=25; rem !=0 && i>=0; i--){
		if(rem>=A[i]){
			ans += (A[i]*A[i]);
			rem -= A[i];
		}
		else{
			ans += (rem*rem);
			break;
		}
	}
	cout << ans << endl;
	return 0;
}