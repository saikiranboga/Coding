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
	string s1, s2;
	while(cin>>s1){
		cin >> s2;
		int freq1[26],freq2[26];
		memset(freq1,0,sizeof(freq1));
		memset(freq2,0,sizeof(freq2));
		rep(i,s1.sz)
			freq1[s1[i]-'a']++;
		rep(i,s2.sz)
			freq2[s2[i]-'a']++;
		int ct;
		rep(i,26){
			ct = min(freq1[i],freq2[i]);
			rep(j,ct)
				cout << (char)('a'+i);
		}
		cout << endl;
	}
	return 0;
}