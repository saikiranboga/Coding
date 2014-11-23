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
	vector<int> t1,t2,t3;
	int t;
	int c1,c2,c3;
	for(int i = 0; i < n; ++i){
		cin >> t;
		if(t==1)
			t1.pb(i);
		if(t==2)
			t2.pb(i);
		if(t==3)
			t3.pb(i);
	}
	c1 = t1.size();
	c2 = t2.size();
	c3 = t3.size();
	int w = min(c1,min(c2,c3));
	cout << w << endl;
	for (int i = 0; i < w; ++i)
		cout << t1[i]+1 << " " << t2[i]+1 << " " << t3[i]+1 << endl;
	return 0;
}