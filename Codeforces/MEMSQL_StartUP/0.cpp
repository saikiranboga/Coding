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
	string s;
	cin >> s;
	string ref[6] = {"jolteon", "flareon", "umbreon", "leafeon", "glaceon", "sylveon"};
	if(s.sz==8){
		cout << "vaporeon" << endl;
	}
	else if(s.sz==6){
		cout << "espeon" << endl;
	}
	int dots = count(s.begin(), s.end(),'.');
	int chrs = s.sz-dots;
	string rf;
	int cnt;
	rep(i,6){
		rf = ref[i];
		cnt = 0;
		rep(j,rf.sz){
			if(s[j]==rf[j])
				cnt++;
		}
		if(cnt==chrs){
			cout << rf << endl;
			break;
		}
	}
	return 0;
}