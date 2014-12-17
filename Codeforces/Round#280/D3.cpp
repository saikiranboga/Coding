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
#define LL long long int

LL ar[1000010];

int main(){
	LL n,x, y;
	cin >> n >> x >> y;
	for (int i = 0; i < 400010; ++i)
		ar[i] = -1;
	LL l1=1, l2=1, sec=1;
	while(l1<=x && l2<=y){
		if(l1*y > l2*x){
			ar[sec] = 1;
			sec++;
			l2++;
		}
		else if(l1*y < l2*x){
			ar[sec] = 0;
			sec++;
			l1++;
		}
		else{
			ar[sec] = ar[sec+1] = 2;
			sec = sec+2;
			l1++, l2++;
		}
	}

	LL ai, modu;
	string ans[3] = {"Vanya","Vova","Both"};
	for (int i = 0; i < n; ++i)
	{
		cin >> ai;
		modu = ai%(x+y);
		if(modu==0)
			cout << ans[ar[x+y]] << endl;
		else
			cout << ans[ar[modu]] << endl;
	}
	return 0;
}