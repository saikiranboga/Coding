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
	ll n;
	cin >> n;
	if(n%2 == 0){
		cout << n/2 << endl;
	}
	else{
		ll ans = (n-1)/2;
		ans = ans-n;
		cout << ans << endl;
	}
	return 0;
}