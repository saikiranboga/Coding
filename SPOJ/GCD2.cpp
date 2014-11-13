#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;

#define PI 3.1415926
#define inf 1000000000

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define sz size()
#define ln length()
#define rep(i,n) for(int i=0;i<n;i++)

string to_string(LL n){
	ostringstream ss;
	ss << n;
	return ss.str();
}

int main(){
	int t;
	cin >> t;
	while(t--){
		LL a;
		string b;
		cin >> a >> b;
		if(a==0){
			cout << b << endl;
			continue;
		}
		LL rem, tmp;
		while(b.sz>10){
			tmp = 0;
			for(int i=0;i<10;i++)
				tmp = tmp*10 + (int)(b[i]-'0');
			rem = tmp%a;
			string prp = to_string(rem) + b.substr(10,b.sz-10);
			b = prp;
		}
		tmp = 0;
		for(int i=0;i<b.sz;i++)
			tmp = tmp*10 + (int)(b[i]-'0');
		rem = tmp%a;
		cout << __gcd(a, rem) << endl;
	}
	return 0;
}