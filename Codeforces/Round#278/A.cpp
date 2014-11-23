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

bool check(ll n){
	int cur;
	while(n > 0){
		cur = n%10;
		n = n/10;
		if(cur==8)
			return true;
	}
	return false;
}

int main(){
	ll n;
	cin >> n;
	int count = 1;
	n++;
	while( check(abs(n)) == false){
		n++;
		count++;
	}
	cout << count << endl;
	return 0;
}