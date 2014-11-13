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
	int n,k,cse=1;
	while( cin>>n && n!=-1 ){
		
		LL C[n+1];
		fd(i,n,0)
			cin >> C[i];
		
		cin >> k;

		LL X[k+1];
		fu(i,1,k)
			cin >> X[i];

		cout << "Case " << cse << ":\n";

		fu(i, 1, k){
			LL res = C[n];
			fd(j, n-1, 0){
				res = res*X[i] + C[j];
			}
			cout << res << endl;
		}
		cse++;
	}
	return 0;
}