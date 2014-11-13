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

ll gcd2(ll u, ll v) {
    while( v != 0) {
        ll r = u % v;
        u = v;
        v = r;
    }
    return u;
}

int main(){
	ll l, r;
	cin >> l >> r;
	if(r-l+1 <= 2){
		cout << -1 << endl;
	}
	else if(r-l+1==3){
		if(l%2==0 || ( gcd2(l,l+2) != 1) ){
			cout << l << " " << l+1 << " " << l+2 << endl;
		}
		else{
			cout << -1 << endl;
		}
	}
	else{
		if(l%2==0){
			cout << l << " " << l+1 << " " << l+2 << endl;
		}
		else{
			cout << l+1 << " " << l+2 << " " << l+3 << endl;
		}
	}
	return 0;
}