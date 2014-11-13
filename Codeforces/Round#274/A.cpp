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

int main(){

	int a, b, c;
	cin >> a >> b >> c;
	int mx = -1;

	if( a+b+c  > mx)
		mx = (a+b)+c;

	if( a+(b*c) > mx)
		mx = a+(b*c);
	if( (a+b)*c > mx )
		mx = (a+b)*c;
	
	if(a*(b+c) > mx)
		mx = a*(b+c);
	if( (a*b)+c > mx )
		mx = (a*b)+c;

	if( a*b*c > mx)
		mx = a*b*c;

	cout << mx << endl;

	return 0;
}