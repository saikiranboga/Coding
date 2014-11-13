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
#define fu(i,a,n) for(int i=a;i<=n;i++)
#define fd(i,n,a) for(int i=n;i>=a;i--)
#define all(a)  a.begin(),a.end() 
#define ESP (1e-9)

#define gi(n) scanf("%d",&n)
#define gl(n) cin >> n
#define pi(n) printf("%d",n)
#define pl(n) cout << n

int main(){

	int n;
	cin >> n;
	vector< PII > ls;

	int price, qual;
	rep(i,n){
		cin >> price >> qual;
		ls.pb( mp(qual, price) );
	}

	sort(ls.begin(), ls.end());

	int mx[n];
	mx[0] = 0;
	bool flag = false;
	int st = 0;
	fu(i,1,n-1){
		if(ls[i].ff > ls[i-1].ff){
			st = i;
			if(ls[i].ss < ls[mx[i-1]].ss){
				flag = true;
				break;
			}
		}
		else if(ls[i].ff == ls[i-1].ff){
			if(ls[i].ss < ls[mx[st]].ss){
				flag = true;
				break;
			}
		}
		mx[i] = ls[i].ss>mx[i-1]?i:mx[i-1];
	}

	if(flag==true)
		cout << "Happy Alex\n";
	else
		cout << "Poor Alex\n";

	return 0;
}