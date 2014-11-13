#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;

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
	gl(t);
	fu(tc,1,t){
		int n;
		LL tot;
		
		gl(tot);
		gl(n);

		int fs[n];
		
		rep(i,n)
			gl(fs[i]);

		sort(fs,fs+n);

		LL sum = 0;
		int req = 0;
		fd(i,n-1,0)
		{
			sum += fs[i];
			req++;
			if(sum>=tot)
				break;
		}
		cout << "Scenario #" << tc << ":\n";
		if(sum>=tot)
		{
			cout << req << endl << endl;
		}
		else
		{
			cout << "impossible\n\n";
		}
	}
	return 0;
}