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

	int t;
	string s;
	cin >> t;
	while(t--){
		cin >> s;
		int min = 0;
		int p = 1;
		int l = 0;
		int N = s.sz;
		while( (p<N) && (min+l<N) ){
			if(s[min+l]==s[(p+l)%N])
				l++;
			else if(s[min+l]<s[(p+l)%N]){
				p = p+l+1;
				l = 0;
			}
			else if(s[min+l]>s[(p+l)%N]){
				min = max(min+l+1,p);
				p = min+1;
				l = 0;
			}
		}
		cout << min+1 << endl;
	}
	return 0;
}