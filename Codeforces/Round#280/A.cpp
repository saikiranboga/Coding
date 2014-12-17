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

int val(int n){
	return ( n*(n+1) )/2;
}

int main(){
	int n;
	cin >> n;
	int x = 1;
	int tot = 1;
	while( tot <= n){
		x++;
		tot = tot + (x*(x+1))/2;
	}
	cout << x-1 << endl;
	return 0;
}